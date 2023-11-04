#include <iostream>

class Point
{
private:
	int xPos;
	int yPos;
public:
	Point(int xpos, int ypos)
		: xPos{xpos}, yPos{ypos} {}
	
	void PrintPosition()
	{
		std::cout << "[ Xpos = " << xPos << ", Ypos = " << yPos << " ]" << std::endl;
	}

#pragma region Binary Operator Overloading 

	// const�� ��� ������ ������ �ʰԲ� �������ְ�, ���� ����� ���߱� ���ؼ� ���ڿ� const�� ���� ��. �Լ��� const�� ���� ���� �� �ڽ�(this) ���� ���� ���� ������ �ʵ��� �����ϱ� ����.
	Point operator+(const Point& target) const { return Point{ this->xPos + target.xPos, this->yPos + target.yPos }; }
	Point operator-(const Point& target) const { return Point{ this->xPos - target.xPos, this->yPos - target.yPos }; }
	Point operator*(const Point& target) const { return Point{ this->xPos * target.xPos, this->yPos * target.yPos }; }
	Point operator/(const Point& target) const { return Point{ this->xPos / target.xPos, this->yPos / target.yPos }; }
	Point operator%(const Point& target) const { return Point{ this->xPos % target.xPos, this->yPos % target.yPos }; }
	bool operator==(const Point& target) const { return this->xPos == target.xPos && this->yPos == target.yPos; }

	Point operator+(int val) const { return Point{ this->xPos + val, this->yPos + val }; }
	Point operator-(int val) const { return Point{ this->xPos - val, this->yPos - val }; }
	Point operator*(int val) const { return Point{ this->xPos * val, this->yPos * val }; }
	Point operator/(int val) const { return Point{ this->xPos / val, this->yPos / val }; }
	Point operator%(int val) const { return Point{ this->xPos % val, this->yPos % val }; }

#pragma endregion

#pragma region Unary Operator Overloading 

	Point operator-() const { return Point{ -xPos, -yPos }; }
	Point operator++() { return Point{ ++(this->xPos), ++(this->yPos) }; }
	Point operator--() { return Point{ --(this->xPos), --(this->yPos) }; }
	Point operator++(int) { return Point{ (this->xPos)++, (this->yPos)++ }; }
	Point operator--(int) { return Point{ (this->xPos)--, (this->yPos)-- }; }

#pragma endregion

};

int main()
{
	Point p1{ 2, 4 };
	Point p2{ 2, 4 };
	Point p3 = p1 + p2;
	(-p3).PrintPosition();
	(++p1).PrintPosition();
	(p1++).PrintPosition();
	(--p2).PrintPosition();
	(p2--).PrintPosition();
}