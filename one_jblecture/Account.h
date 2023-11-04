#pragma once
#include <string>

class Account
{
public:
	Account();
	Account(double balance);
	Account(std::string name, double balance);
	bool Deposit(double amount);
private:
	double _balance = 0;
	std::string _name;
};