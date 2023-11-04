#include <iostream>
#include "Account.h"
using namespace std;

class GameManager
{

};

class Player
{
	friend class GameManager;
	friend void DisplayPlayer(const Player& p);
private:
	int x, y;
	float speed;
	static int numPlayer;
public:

#pragma region Constructor and Destoryer

	Player(int x, int y, float speed)
		: x{ x }, y{ y }, speed{ speed }
	{
		cout << this << endl;
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

void DisplayPlayer(const Player& p)
{
	cout << p.x << "," << p.y << endl; //friend가 아니면 private에 접근불가능
}

int main()
{
    Player p{ 1,1,1 };
	Player p2{ 1,1,1 };
	Player Monster { 1,1,1 };

	std::cout << Player::GetNumPlayer() << std::endl;
	DisplayPlayer(p);
}