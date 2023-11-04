#include "Account.h"

bool Account::Deposit(double amount)
{
	_balance += amount;
	return true;
}

Account::Account(std::string name, double balance) : _name {name}, _balance {balance}
{

}

Account::Account() : Account{ "JInhyeon", 0 }
{

}

Account::Account(double balance) : Account{ "Jinhyeon", balance }
{

}