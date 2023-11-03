#include <iostream>
using namespace std;

struct Person
{
public:
	string _name;
	Person(string name)
	{
		_name = name;
	}
};

int main()
{
	Person person { "Jinhyeon" };

}