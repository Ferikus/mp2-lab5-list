#pragma once
#include "HeadList.h"

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
	TPolynomial(int monoms[][4] = NULL, int size = 0); // monoms[0][4] ������������ � ���-�� �������
	TPolynomial(const TPolynomial& p);

	void addMonom(TMonom m); // �������� ����� � ��������
	//inline TMonom getMonom() { getCurr(); } // ���������� ������� �������� ������

	bool operator==(const TPolynomial& list) const;
	bool operator!=(const TPolynomial& list) const;

	TPolynomial& operator=(TPolynomial& p);
	TPolynomial& operator*(double a); // �������� ������� �� ���������
	TPolynomial& operator*(TMonom& m); // �������� ������� �� �����
	TPolynomial& operator+(TPolynomial& p);
	TPolynomial& operator-(TPolynomial& p);
	
	friend std::ostream& operator<<(std::ostream& os, TPolynomial& p);
};

// ����������� �� �������� {0, -1, -1, -1} -> {0, 9, 9, 9} -> ... -> {0, 0, 0, 0}