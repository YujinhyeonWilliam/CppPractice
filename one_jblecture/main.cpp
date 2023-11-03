#include <iostream>
using namespace std;

int* create_array(int size, int init_value = 0)
{
	int* new_storage = nullptr;
	new_storage = new int[size];
	for (int i = 0; i < size; i++)
		*(new_storage + i) = init_value;

	return new_storage;
}

int main()
{
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;
	
	return 0;
}

