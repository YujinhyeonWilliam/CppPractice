#pragma once

#include <iostream>
using namespace std;

class Copy
{
private:
	int* _data; //Pointer
public:
	Copy(int data); // Constructor. Shallow Copy
	Copy(int* data); // Constructor. Deep Copy
	Copy(const Copy& source); // Copy Constructor
	~Copy();
};