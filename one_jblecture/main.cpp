#include <iostream>
using namespace std;

//class Player
//{
//private:
//	int x, y;
//	int speed;
//public:
//	Player(int x, int y, int speed)
//		: x {x}, y {y}, speed { speed }
//	{}
//
//	void Move(int dx, int dy)
//	{
//		x += dx * speed;
//		y += dy * speed;
//	}
//	
//	void ShowPosition() const
//	{
//		cout << x << ", " << y << endl;
//	}
//};
//
//
//class PlayerHandler
//{
//private:
//	Player* playerList[50];
//	int playerNum;
//public:
//	PlayerHandler() : playerNum{ 0 }{}
//
//	~PlayerHandler()
//	{
//		for (int i = 0; i < playerNum; i++)
//			delete playerList[i];
//	}
//	
//	void AddPlayer(Player* player)
//	{
//		playerList[playerNum++] = player;
//	}
//
//	void ShowAllPlayerPositions() const
//	{
//		for (int i = 0; i < playerNum; i++)
//			playerList[i]->ShowPosition();
//	}
//
//	
//};


class Entity 
{
protected:
	int _x;
	int _y;

public:
	Entity(int x, int y)
		: _x {x}, _y {y} {}

	void ShowPosition()
	{
		cout << "[" << _x << ", " << _y << "]" << endl;
	}

	void Talk()
	{
		cout << "Hello" << endl;
	}

	Entity(const Entity& other)
	{

	}

};



class Player : public Entity
{
private:
	int* _hp;
	int* _xp;
	int* _speed;
public:

	Player(int x, int y, int speed) : Entity{ x, y }, _speed{ new int } { *_speed = speed; }
	~Player()
	{
		delete _hp;
		_hp = nullptr;
		
		delete _xp;
		_xp = nullptr;

		delete _speed;
		_speed = nullptr;
	}

	void Move(int dx, int dy)
	{
		_x += dx * (*_speed);
		_y += dy * (*_speed);
	}
	Player(const Player& player)
		: Entity { player }, _hp { new int }, _xp { new int }, _speed { new int }
	{
		*_hp = *player._hp;
		*_xp = *player._xp;
		*_speed = *player._speed;
	}

	void Talk()
	{
		Entity::Talk();
		cout << "I'm player." << endl;
	}
};

int main()
{
	Player player{ 5, 5, 10 };
	player.ShowPosition();
	player.Talk();
	player.Move(1, 5);
	player.ShowPosition();
}