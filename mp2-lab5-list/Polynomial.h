#pragma once
#include "HeadList.h"

//#define NULL 0

struct TMonom {
	double coeff;
	int x, y, z;

	TMonom();
	TMonom(double _coeff, int _x, int _y, int _z);
	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
};

class TPolynomial: public THeadList<TMonom> {
public:
	TPolynomial(int monoms[][4] = 0, int size = 0); // monoms[0][4] коэффициенты и кол-во мономов;  = NULL
	TPolynomial(const TPolynomial& p);

	void addMonom(TMonom m); // добавить моном к полиному
	//inline TMonom getMonom() { getCurr(); } // возвращает текущее значение монома

	bool operator==(const TPolynomial& list) const;
	bool operator!=(const TPolynomial& list) const;

	TPolynomial& operator=(TPolynomial& p);
	TPolynomial& operator*(double a); // умножить полином на константу
	TPolynomial& operator*(TMonom& m); // умножить полином на моном
	TPolynomial& operator+(TPolynomial& p);
	TPolynomial& operator-(TPolynomial& p)
	{
		*(this) = *(this) + p * (-1);
		return *this;
	}
	
	//friend std::ostream& operator<<(std::ostream& os, TPolynomial& p);
};

// упорядочить по убыванию {0, -1, -1, -1} -> {0, 9, 9, 9} -> ... -> {0, 0, 0, 0}