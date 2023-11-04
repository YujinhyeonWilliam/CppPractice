
#include "Copy.h"

Copy::Copy(int data)
{
	/* Shallow Copy */
	_data = new int; // allocate storage
	*_data = data;
}

Copy::Copy(int* data)
{
	/* Deep Copy */
	_data = new int; // allocate storage
	*_data = *data;
}

// Deep Copy Constructor
Copy::Copy(const Copy& source) : Copy{ *source._data } {}

Copy::~Copy()
{
	delete _data; // free storage
	cout << "Free Storage" << endl;
}