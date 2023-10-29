#include <iostream>

namespace A {

	void function()
	{
		std::cout << "Fucntion 1" << std::endl;
	}
}

namespace B
{
	void function()
	{
		std::cout << "Function 2" << std::endl;
	}
}

int main()
{
	int age = 26;
	float height = 175.2f;
	std::cout << " my age is " << age << "\n";
	std::cout << " my height is " << height;


	return 0; // optional
}