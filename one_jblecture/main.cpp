#include <iostream>

class Point
{
private:
	int xPos;
	int yPos;

	// ★ 아래와 같이 Point class 내에 적어놨어도 아래 friend 형식의 operator 함수들은 '전역함수(global)'이다.
	//	  이와 같이 하는 이유는 '교환 법칙' 성립을 위해서다.

	friend Point operator* (const int lhs, Point& rhs) { return Point{ rhs.xPos * lhs, rhs.yPos * lhs }; }
	friend Point operator+ (const int lhs, Point& rhs) { return Point{ rhs.xPos + lhs, rhs.yPos + lhs }; }
	friend Point operator- (const int lhs, Point& rhs) { return Point{ rhs.xPos - lhs, rhs.yPos - lhs }; }
	friend Point operator/ (const int lhs, Point& rhs) { return Point{ rhs.xPos / lhs, rhs.yPos / lhs }; }
	friend Point operator% (const int lhs, Point& rhs) { return Point{ rhs.xPos % lhs, rhs.yPos % lhs }; }

	friend Point operator* (const Point& lhs, int rhs) { return Point{ lhs.xPos * rhs, lhs.yPos * rhs }; }
	friend Point operator+ (const Point& lhs, int rhs) { return Point{ lhs.xPos + rhs, lhs.yPos + rhs }; }
	friend Point operator- (const Point& lhs, int rhs) { return Point{ lhs.xPos - rhs, lhs.yPos - rhs }; }
	friend Point operator/ (const Point& lhs, int rhs) { return Point{ lhs.xPos / rhs, lhs.yPos / rhs }; }
	friend Point operator% (const Point& lhs, int rhs) { return Point{ lhs.xPos % rhs, lhs.yPos % rhs }; }

	friend Point operator* (const Point& lhs, const Point& rhs) { return Point{ lhs.xPos * rhs.xPos, lhs.yPos * rhs.yPos }; }
	friend Point operator+ (const Point& lhs, const Point& rhs) { return Point{ lhs.xPos + rhs.xPos, lhs.yPos + rhs.yPos }; }
	friend Point operator- (const Point& lhs, const Point& rhs) { return Point{ lhs.xPos - rhs.xPos, lhs.yPos - rhs.yPos }; }
	friend Point operator/ (const Point& lhs, const Point& rhs) { return Point{ lhs.xPos / rhs.xPos, lhs.yPos / rhs.yPos }; }
	friend Point operator% (const Point& lhs, const Point& rhs) { return Point{ lhs.xPos % rhs.xPos, lhs.yPos % rhs.yPos }; }
	
public:
	Point(int xpos, int ypos)
		: xPos{xpos}, yPos{ypos} {}
	
	void PrintPosition()
	{
		std::cout << "[ Xpos = " << xPos << ", Ypos = " << yPos << " ]" << std::endl;
	}

	// ▼ 멤버 함수 연산자 오버로딩
	Point operator-() const { return Point{ -xPos, -yPos }; }
	Point operator++() { return Point{ ++(this->xPos), ++(this->yPos) }; }
	Point operator--() { return Point{ --(this->xPos), --(this->yPos) }; }
	Point operator++(int) { return Point{ (this->xPos)++, (this->yPos)++ }; }
	Point operator--(int) { return Point{ (this->xPos)--, (this->yPos)-- }; }
//#pragma region Member Operator Functions Overloading 
//  
//  #pragma region Binary Operator Overloading 
//
//	// const로 멤버 변수가 변하지 않게끔 방지해주고, 복사 비용을 낮추기 위해서 인자에 const를 붙인 것. 함수에 const를 붙인 것은 나 자신(this) 또한 연산 도중 변하지 않도록 방지하기 위함.
//	Point operator+(const Point& target) const { return Point{ this->xPos + target.xPos, this->yPos + target.yPos }; }
//	Point operator-(const Point& target) const { return Point{ this->xPos - target.xPos, this->yPos - target.yPos }; }
//	Point operator*(const Point& target) const { return Point{ this->xPos * target.xPos, this->yPos * target.yPos }; }
//	Point operator/(const Point& target) const { return Point{ this->xPos / target.xPos, this->yPos / target.yPos }; }
//	Point operator%(const Point& target) const { return Point{ this->xPos % target.xPos, this->yPos % target.yPos }; }
//	bool operator==(const Point& target) const { return this->xPos == target.xPos && this->yPos == target.yPos; }
//
//	Point operator+(int val) const { return Point{ this->xPos + val, this->yPos + val }; }
//	Point operator-(int val) const { return Point{ this->xPos - val, this->yPos - val }; }
//	Point operator*(int val) const { return Point{ this->xPos * val, this->yPos * val }; }
//	Point operator/(int val) const { return Point{ this->xPos / val, this->yPos / val }; }
//	Point operator%(int val) const { return Point{ this->xPos % val, this->yPos % val }; }
//
//#pragma endregion
//  
//  #pragma region Unary Operator Overloading 
//
//	Point operator-() const { return Point{ -xPos, -yPos }; }
//	Point operator++() { return Point{ ++(this->xPos), ++(this->yPos) }; }
//	Point operator--() { return Point{ --(this->xPos), --(this->yPos) }; }
//	Point operator++(int) { return Point{ (this->xPos)++, (this->yPos)++ }; }
//	Point operator--(int) { return Point{ (this->xPos)--, (this->yPos)-- }; }
//
//#pragma endregion
//  
//#pragma endregion
};

int main()
{
	Point p1{ 2, 4 };
	Point p2{ 2, 4 };
	Point p3 = p1 + 2;
	p3 = 2 + p1;
	Point p4 = p2 + p1;

	(-p3).PrintPosition();
	(++p1).PrintPosition();
	(p1++).PrintPosition();
	(--p2).PrintPosition();
	(p2--).PrintPosition();
}