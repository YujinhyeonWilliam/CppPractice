#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <map>

template <typename T>
void PrintContainer(T container)
{
	std::cout << "===========================" << std::endl;
	std::cout << " Container Size = "<< container.size() << std::endl;
	for (auto it1 = container.begin(); it1 != container.end(); it1++)
		std::cout << *it1 << std::endl;

	std::cout << "===========================" << std::endl;
}

int main()
{
	std::list<int> sList { 3, 3, 3,1,5,4,2 };
	std::set<int> s{ 3, 3, 3,1,5,4,2 };
	std::map<std::string, int> m1{
		{"jinhyeon", 26},
		{"Minheoi", 25},
	};
	
	m1["nobdy"] = 40;
	m1.insert(std::make_pair("Choi", 30));

	
}