
#pragma region  Forward Declartions

#include <iostream>

int add_numbers(int, int = 4);
double add_numbers(double, double);

#pragma endregion 

int main()
{


}


int add_numbers(int a, int b)
{
	return a + b;
}

double add_numbers(double a, double b)
{
	return a + b;
}