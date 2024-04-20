#pragma once
#include <iostream>
#include <string>
#include "HeadList.h"

//#define NULL 0

struct TMonom {
	int coeff;
	int x, y, z;

	TMonom() {
		coeff = 0;
		x = y = z = 0;
	};
	TMonom(double _coeff, int _x, int _y, int _z) {
		coeff = _coeff;
		x = _x;
		y = _y;
		z = _z;
	};
	bool operator==(const TMonom& m) const {
		if (coeff != m.coeff) return false;
		else if (x != m.x && y != m.y && z != m.z) return false;
		return true;
	};
	bool operator!=(const TMonom& m) const {
		return !(*this == m);
	};

	inline void setCoeff(double _coeff) { coeff = _coeff; }
	inline void setX(double _x) { x = _x; }
	inline void setY(double _y) { y = _y; }
	inline void setZ(double _z) { z = _z; }
};

bool comparePowers(TMonom m1, TMonom m2) { // сравнить m1 >= m2
	if (m1.x > m2.x) return true;
	else if (m1.x == m2.x) {
		if (m1.y > m2.y) return true;
		else if (m1.y == m2.y) {
			if (m1.z >= m2.z) return true;
		}
	}
	return false;
}

class TPolynomial: public THeadList<TMonom> {
public:
	TPolynomial(int monoms[][4] = 0, int size = 0) // monoms[0][4] коэффициенты и кол-во мономов;  = NULL
	{
		TMonom head(0, -1, -1, -1);
		pHead->val = head;
		for (int i = 0; i < size; i++) {
			TMonom monom((double)monoms[i][0], monoms[i][1], monoms[i][2], monoms[i][3]);
			insLast(monom);
		}
	}
	TPolynomial(const TPolynomial& p)
	{
		TMonom head(0, -1, -1, -1);
		pHead->val = head;
		TNode<TMonom>* i = p.pFirst;
		while (i != p.pStop) {
			insLast(i->val);
			i = i->pNext;
		}
	}

	void addMonom(TMonom m) // добавить моном к полиному
	{
		if (empty()) {
			insFirst(m);
			return;
		}
		reset();
		TMonom i = getCurr();
		while (!(isEnd()) && !comparePowers(m, i)) goNext(); // пока m < i - двигаем
		// теперь pCurr указывает на место для вставки
		if (pCurr != pStop) {
			i = getCurr();
			if (i.x == m.x && i.y == m.y && i.z == m.z) {
				if (m.coeff + i.coeff == 0) delCurr();
				else i.coeff = m.coeff + i.coeff;
			}
			else insCurr(m);
		}
		else insLast(m);
	}

	bool operator==(const TPolynomial& list) const
	{
		if (len != list.len) return false;
		else {
			TNode<TMonom>* i = pFirst, * j = list.pFirst;
			while (i != pStop) {
				if (i->val != j->val) return false;
				i = i->pNext;
				j = j->pNext;
			}
		}
		return true;
	}
	bool operator!=(const TPolynomial& list) const
	{
		return !(*this == list);
	}

	TPolynomial& operator=(TPolynomial& p)
	{
		if (this == &p) return *this;
		clrList();
		TMonom head(0, -1, -1, -1);
		pHead->val = head;
		for (p.reset(); !(p.isEnd()); p.goNext()) {
			TMonom monom = p.getCurr();
			insLast(monom);
		}
		return *this;
	}
	TPolynomial& operator*(double a) // умножить полином на константу
	{
		for (reset(); !(isEnd()); goNext()) {
			getCurr().coeff *= a;
		}
		return *this;
	}
	TPolynomial& operator*(TMonom& m) // умножить полином на моном
	{
		for (reset(); !(isEnd()); goNext()) {
			getCurr().coeff *= m.coeff;
			getCurr().x += m.x;
			getCurr().y += m.y;
			getCurr().z += m.z;
		}
		return *this;
	}
	TPolynomial& operator+(TPolynomial& p)
	{
		// МНОГОКРАТНЫЙ ПРОХОД ПО СПСКУ

		// for (p.reset(); p.isEnd(); p.goNext())
		//	addMonom(p.getCurr());

		// ЧЕРЕЗ "СЛИЯНИЕ", ПАРАЛЛЕЛЬНЫЙ ПРОХОД ПО ОБОИМ СПИСКАМ

		TMonom m, pm, rm;
		reset();
		p.reset();
		while (pCurr != pStop) { // перенести брейк в условие while
			m = getCurr();
			pm = p.getCurr();
			if (!comparePowers(m, pm)) {
				// моном m < pm =>  добавляем моном pm в полином p
				insCurr(pm);
				p.goNext();
				//goNext();
			}
			else if (m.x == pm.x && m.y == pm.y && m.z == pm.z) {
				// индексы мономов равны (это могут быть головы)
				if (m.x == -1) break;
				m.coeff += pm.coeff;
				if (m.coeff != 0) {
					getCurr().coeff = m.coeff;
					goNext();
					p.goNext();
				}
				else {
					// удаление монома с нулевыми коэффициентами
					delCurr();
					p.goNext();
				}
			}
			else {
				goNext();
				insCurr(pm);
			}
			//else {
			//	// моном m > pm

			//}
		}
		return *this;
	}
	TPolynomial& operator-(TPolynomial& p)
	{
		*(this) = *(this) + p * (-1);
		return *this;
	}
	
	std::string outputPolynomial()
	{
		std::string s = "";
		TMonom curr;
		int currcoeff;
		for (reset(); !(isEnd()); goNext()) {
			curr = getCurr();
			currcoeff = curr.coeff;
			if (pCurr != pFirst) s += " ";
			if (currcoeff > 0) s += "+ ";
			else if (currcoeff < 0) {
				s += "- ";
				currcoeff *= -1;
			}
			s += std::to_string(currcoeff) + "*x^(" + std::to_string(curr.x) + ")*y^(" + std::to_string(curr.y) + ")*z^(" + std::to_string(curr.z) + ")";
			// преобразовать в ансайнд
		}
		return s;
	}
	//friend std::ostream& operator<<(std::ostream& os, TPolynomial& p);
};

// упорядочить по убыванию {0, -1, -1, -1} -> {0, 9, 9, 9} -> ... -> {0, 0, 0, 0}