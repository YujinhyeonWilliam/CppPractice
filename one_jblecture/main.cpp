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


class ItemData final
{

};

class Entity 
{
protected:
	int _x;
	int _y;
public:
	Entity(int x, int y)
		: _x{ x }, _y{ y } {}

	virtual ~Entity()
	{
		cout << "Entity Destroyer called" << endl;
	}

	virtual void Move(int dx, int dy)
	{
		_x += dx;
		_y += dy;
	}

	virtual void PrintPosition() const
	{
		std::cout << "Entity : " << _x << ", " << _y << std::endl;
	}
};

class Player final : public Entity
{
private:
	int _hp;
	int _xp;
public:
	Player(int x, int y, int hp, int exp)
		: Entity {x, y}, _hp {hp}, _xp {exp} {}
	
	~Player()
	{
		cout << "Player Destroyer called" << endl;
	}

	// override
    void Move(int dx, int dy) override final
	{
		_x += dx * 2;
		_y += dy * 2;
	}

	// override
     void PrintPosition() const override
	 {
		std::cout << "Player : " << _x << ", " << _y << std::endl;
	 }
};

int main()
{
	Player p{ 1,1,10,10 };
	const Entity& e = p;
	e.PrintPosition();

}