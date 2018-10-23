#include <iostream>
#include <string>

using namespace std;

int countDigitsTailHelper(int n, int digit, int count);

// REQ: n >= 1
// EFF: Prints the hailstone sequence starting at n.
//      Uses iteration.
void hailstoneIterative(int n){
	int hail = n;
	cout << hail << " ";
	while( hail != 1){
		if(hail%2 == 1){
			hail = (hail*3)+1;
			cout << hail << " ";
		}
		else if(hail%2 == 0){
			hail = (hail/2);
			cout << hail << " ";
		}
	}
}

// REQ: n >= 1
// EFF: Prints the hailstone sequence starting at n.
//      Uses recursion.
void hailstoneRecursive(int n){
	int hail = n;
	cout << hail << " ";
	if(hail == 1){}
	else if(hail%2 == 1){
		hail = (hail*3)+1;
		hailstoneRecursive(hail);
	}
	else if(hail%2 == 0){
		hail = (hail/2);
		hailstoneRecursive(hail);
	}
}

// REQ: 0 <= digit <= 9, n >= 0
// EFF: Returns the number of times 'digit' appears in 'n'.
//      Uses iteration.
int countDigitsIterative(int n, int digit){
	int counter = 0;
	int number = n;
	int last = digit;
	if( number == 0 && digit == 0){
		counter++;
	}
	while(number != 0){
		if(number%10 == last){
			counter++;
		}
		number = number/10;
	}
  return counter;
}

// REQ: 0 <= digit <= 9, n >= 0
// EFF: Returns the number of times 'digit' appears in 'n'.
//      Uses recursion.
int countDigitsRecursive(int n, int digit){
	int number = n;
	int last = digit;
	int counter = 0;
	if(number == 0 && last == 0){
		counter++;
		return counter;
	}
	if(number != 0){
		if(number%10 == last){
		counter++;
		}
		number = number/10;
		if(number == 0){
			return counter;
		}
		counter = counter + countDigitsRecursive(number, last);
		return counter;
	}
	return 0;
}

// REQ: 0 <= digit <= 9, n >= 0
// EFF: Returns the number of times 'digit' appears in 'n'.
//      Uses tail recursion.
int countDigitsTail(int n, int digit){
	int number = n;
	int last = digit;
	return countDigitsTailHelper(number, last, 0);
}

int countDigitsTailHelper(int n, int digit, int count){
	int number = n;
	int last = digit;
	int counter = count;
	if(number == 0 && last == 0){
		counter++;
		return counter;
	}
	if(number == 0 && last != 0){
		return counter;
	}
	if(number != 0){
		if(number%10 == last){
		counter++;
		}
		number = number/10;
		if(number == 0){
			return counter;
		}
		return countDigitsTailHelper(number, last, counter);
	}
	return counter;
}

void hailstoneTest(int n){
  cout << endl << "  Hailstone test for n = " << n << endl;
  cout << "    Iterative: "; hailstoneIterative(n);  cout << endl;
  cout << "    Recursive: "; hailstoneRecursive(n);  cout << endl;
}

void countDigitsTest(int n, int digit){
  cout << endl << "  CountDigits test.  How many " << digit << "s in " << n << endl;
  cout << "    Iterative:      " << countDigitsIterative(n, digit) << endl;
  cout << "    Recursive:      " << countDigitsRecursive(n, digit) << endl;
  cout << "    Tail Recursive: " << countDigitsTail(n, digit) << endl;
}

int main() {
  cout << "Start Recursive Tests" << endl;
  hailstoneTest(5);
  hailstoneTest(8);
  hailstoneTest(14);

  cout << "--------------------------" << endl;

  countDigitsTest(201220130, 2);
  countDigitsTest(201220130, 0);
  countDigitsTest(201220130, 7);
  countDigitsTest(0, 0);
  countDigitsTest(0, 8);
 
  return 0;
}
