#include <iostream>

class Point
{
private:
	int xPos;
	int yPos;

	// �� �Ʒ��� ���� Point class ���� ������ �Ʒ� friend ������ operator �Լ����� '�����Լ�(global)'�̴�.
	//	  �̿� ���� �ϴ� ������ '��ȯ ��Ģ' ������ ���ؼ���.
	// const ��� ������ ���� �������� ���ϵ��� �ϴ� ��. ������ (&) ��� ������ ��ü�� �����ϰ� ������ �ʵ��� �ϱ� ����

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
	
	friend std::ostream& operator<< (std::ostream& os, const Point& rhs)
	{
		os << "[ Xpos = " << rhs.xPos << ", Ypos = " << rhs.yPos << " ]" << std::endl;
		return os;
	}

	friend std::istream& operator>> (std::istream& is, Point& rhs)
	{
		int x = 0;
		int y = 0;
		is >> x >> y;
		rhs = Point{ x, y };
		return is;
	}

public:
	Point(int xpos, int ypos)
		: xPos{xpos}, yPos{ypos} {}
	
	void PrintPosition()
	{
		std::cout << "[ Xpos = " << xPos << ", Ypos = " << yPos << " ]" << std::endl;
	}

	// �� ��� �Լ� ������ �����ε�
	Point operator-() const { return Point{ -xPos, -yPos }; }
	Point operator++() { return Point{ ++(this->xPos), ++(this->yPos) }; }
	Point operator--() { return Point{ --(this->xPos), --(this->yPos) }; }
	Point operator++(int) { return Point{ (this->xPos)++, (this->yPos)++ }; }
	Point operator--(int) { return Point{ (this->xPos)--, (this->yPos)-- }; }

	Point()
	{
		xPos = 0;
		yPos = 0;
	}

	Point& operator=(const Point& rhs)
	{
		if (this == &rhs)
			return *this;

		xPos = rhs.xPos;
		yPos = rhs.yPos;
		return *this;
	}
//#pragma region Member Operator Functions Overloading 
//  
//  #pragma region Binary Operator Overloading 
//
//	// const�� ��� ������ ������ �ʰԲ� �������ְ�, ���� ����� ���߱� ���ؼ� ���ڿ� const�� ���� ��. �Լ��� const�� ���� ���� �� �ڽ�(this) ���� ���� ���� ������ �ʵ��� �����ϱ� ����.
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


class Array
{
private:
	int* ptr;
	int size;
public:
	Array(int value, int size)
		: size {size}
	{
		ptr = new int[size];
		
		for (int i = 0; i < size; i++)
			ptr[i] = value + i;
	}

	~Array() {
		delete[] ptr;
	}

	Array& operator =(const Array& rhs)
	{
		if (this == &rhs)
			return *this;
		
		delete[] ptr;

		ptr = new int[rhs.size];
		size = rhs.size;
		for (int i = 0; i < size; i++)
			ptr[i] = rhs.ptr[i];

		return *this;
	}


	int GetSize() const
	{
		return size;
	}

	int& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Out of range!" << std::endl;
			exit(1);
		}

		return ptr[index];
	}

	int operator[](int index) const
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Out of range!" << std::endl;
			exit(1);
		}

		return ptr[index];
	}
};


int main()
{
	const Array a1{ 5, 10 };
	
	std::cout << a1[0] << std::endl;
}