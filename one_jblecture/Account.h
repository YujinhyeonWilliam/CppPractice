#pragma once
#include <string>

class Account
{
public:
	bool Deposit(double amount);
private:
	double balance = 0;
	std::string name;
};