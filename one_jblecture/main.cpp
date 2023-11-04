#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
	int* p1 = new int;
	*p1 = 100;
	int* p2 = p1;

	delete p2;
	delete p1;
}