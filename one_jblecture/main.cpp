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

	// const로 멤버 변수가 변하지 않게끔 방지해주고, 복사 비용을 낮추기 위해서 인자에 const를 붙인 것. 함수에 const를 붙인 것은 나 자신(this) 또한 연산 도중 변하지 않도록 방지하기 위함.
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