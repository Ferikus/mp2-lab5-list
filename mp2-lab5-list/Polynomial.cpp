#include <iostream>
#include "Polynomial.h"

TMonom::TMonom() {
	coeff = 0;
	x = y = z = 0;
}

TMonom::TMonom(double _coeff, int _x, int _y, int _z) {
	coeff = _coeff;
	x = _x;
	y = _y;
	z = _y;
}

bool TPolynomial::comparePowers(TMonom m1, TMonom m2) { // �������� m1 >= m2
	if (m1.x < m2.x) return false;
	else {
		if (m1.y < m2.y) return false;
		else {
			if (m1.z < m2.z) return false;
		}
	}
	return true;
}

void TPolynomial::addMonom(TMonom m)
{
	reset();
	TMonom i = getCurr();
	while (!comparePowers(m, i)) goNext(); // ���� m < i - �������
	// ������ pCurr ��������� �� ����� ��� �������
	i = getCurr();
	if (m.x == i.x && m.y == i.y && m.z == i.z) {
		if (m.coeff + i.coeff == 0) delCurr();
		else i.coeff = m.coeff + i.coeff;
	}
	else insCurr(m);
}

TPolynomial::TPolynomial(int monoms[][4], int km = 0) // monoms[][4] - ������ �� ������������� � �������� �������
{
	TMonom head(0, -1, -1, -1);
	pHead->val = head;
	for (int i = 0; i < km; i++) {
		TMonom monom((double)monoms[i][0], monoms[i][1], monoms[i][2], monoms[i][3]);
		insLast(monom);
	}
}

TPolynomial::TPolynomial(TPolynomial& p)
{
	TMonom head(0, -1, -1, -1);
	pHead->val = head;
	for (p.reset(); p.isEnd(); p.goNext()) {
		TMonom monom = p.getCurr();
		insLast(monom);
	}
}

TPolynomial& TPolynomial::operator=(TPolynomial& p)
{
	if (this == &p) return *this;
	clrList();
	TMonom head(0, -1, -1, -1);
	pHead->val = head;
	for (p.reset(); p.isEnd(); p.goNext()) {
		TMonom monom = p.getCurr();
		insLast(monom);
	}
	return *this;
}

TPolynomial& TPolynomial::operator+(TPolynomial& p)
{
	// ������������ ������ �� �����

	// for (p.reset(); p.isEnd(); p.goNext())
	//	addMonom(p.getCurr());

	// ����� "�������", ������������ ������ �� ����� �������

	TMonom m, pm, rm;
	reset();
	p.reset();
	while (1) { // ��������� ����� � ������� while
		m = getCurr();
		pm = p.getCurr();
		if (!comparePowers(m, pm)) {
			// ����� m < pm =>  ��������� ����� pm � ������� p
			insCurr(pm);
			p.goNext();
		}
		else if (m.x == pm.x && m.y == pm.y && m.z == pm.z) {
			// ������� ������� ����� (��� ����� ���� ������)
			if (m.x == -1) break;
			m.coeff += pm.coeff;
			if (m.coeff != 0) {
				goNext();
				p.goNext();
			}
			else {
				// �������� ������ � �������� ��������������
				delCurr();
				p.goNext();
			}
		}
	}
	return *this;
}

TPolynomial& TPolynomial::operator*(double a) {
	for (reset(); isEnd(); goNext()) {
		getCurr().coeff *= a;
	}
	return *this;
}

TPolynomial& TPolynomial::operator*(TMonom& m) {
	TMonom curr;
	for (reset(); isEnd(); goNext()) {
		curr = getCurr();
		curr.coeff *= m.coeff;
		curr.x *= m.x;
		curr.y *= m.y;
		curr.z *= m.z;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, TPolynomial& p) {
	TMonom curr;
	for (p.reset(); p.isEnd(); p.goNext()) {
		curr = p.getCurr();
		os << curr.coeff << " * x^" << curr.x << " * y^" << curr.y << " * z^" << curr.z << " ";
	}
	return os;
}