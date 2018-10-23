#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int org = 10;
	cout << "org " << org << endl;
	cout << "&org " << &org << endl;
	
	int *ptr;
	ptr = &org;
	
	cout << "ptr " << ptr << endl;
	cout << "*ptr " << *ptr << endl;
	
	return 0;
}
