#include <iostream>
#include "Account.h"
using namespace std;

class Player
{
private:
	int x, y;
	float speed;
	static int numPlayer;
public:

#pragma region Constructor and Destoryer

	Player(int x, int y, float speed)
		: x{ x }, y{ y }, speed{ speed }
	{
		numPlayer++;
	}
	~Player()
	{
		numPlayer--;
	}

#pragma endregion

	void SetPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void PrintPosition() const
	{
		cout << x << ", " << y << endl;
	}

	static int GetNumPlayer() { return numPlayer; }

};

int Player::numPlayer = 0;

int main()
{
    Player p{ 1,1,1 };
	Player p2{ 1,1,1 };
	Player Monster { 1,1,1 };

	std::cout << Player::GetNumPlayer() << std::endl;
}