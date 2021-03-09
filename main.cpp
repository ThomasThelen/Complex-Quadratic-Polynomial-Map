#include "stdafx.h"
#include <vector>

using std::vector;

class Imaginary
{
public:
	double real;
	double complex;
	Imaginary operator+(const Imaginary&);
};
Imaginary Imaginary::operator+(const Imaginary& cmplx)
{
	Imaginary result;
	//Imaginary aaa = *this;
	result.real = real+ cmplx.real;
	result.complex = complex+cmplx.complex;
	return result;
}
Imaginary Square(Imaginary number)
{
	auto result = Imaginary();
	result.real = pow(number.real,2) + pow(number.complex, 2);
	result.complex= 2 * number.real*number.complex;
	return result;
}

class Quadratic
{
public:
	Imaginary GetPrevious(int);
	void SetY(Imaginary);
protected:
	vector<Imaginary> y;

};
Imaginary Quadratic::GetPrevious(int current_position)
{
	return y.at(current_position - 1);
}
void Quadratic::SetY(Imaginary value)
{
	y.push_back(value);
}


int main()
{
	int iterations=10;
	Imaginary z, initial, c;
	Quadratic eqn;
	initial.complex = 1.2;
	initial.real = 1;
	c.complex = 0;
	c.real = 1;
	// Initial Condition
	eqn.SetY(initial);

	for (int i = 1; i < iterations; i++)
	{
		eqn.SetY(Square(eqn.GetPrevious(i))+c);
	}

    return 0;
}
