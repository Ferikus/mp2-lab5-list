#pragma once
#include "HeadList.h"

struct TMonom {
	double coeff;
	int x, y, z;

	TMonom();
	TMonom(double _coeff, int _x, int _y, int _z);
};

class TPolynomial: public THeadList<TMonom> {
public:
	TPolynomial(int monoms[][4] = NULL, int km = 0); // monoms[0][4] ������������ � ������� �������
	TPolynomial(TPolynomial& p);

	bool comparePowers(TMonom m1, TMonom m2);
	void addMonom(TMonom m); // �������� ����� � ��������
	//inline TMonom getMonom() { getCurr(); } // ���������� ������� �������� ������

	TPolynomial& operator=(TPolynomial& p);
	TPolynomial& operator+(TPolynomial& p);
	TPolynomial& operator*(double a); // �������� ������� �� ���������
	TPolynomial& operator*(TMonom& m); // �������� ������� �� �����
	
	friend std::ostream& operator<<(std::ostream& os, TPolynomial& p);
};

// ����������� �� �������� {0, -1, -1, -1} -> {0, 9, 9, 9} -> ... -> {0, 0, 0, 0}