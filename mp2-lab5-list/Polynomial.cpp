//#include "Polynomial.h"
//
//TMonom::TMonom() {
//	coeff = 0;
//	x = y = z = 0;
//}
//
//TMonom::TMonom(double _coeff, int _x, int _y, int _z) {
//	coeff = _coeff;
//	x = _x;
//	y = _y;
//	z = _z;
//}
//
//bool TMonom::operator==(const TMonom& m) const {
//	if (coeff != m.coeff) return false;
//	else if (x != m.x && y != m.y && z != m.z) return false;
//	return true;
//}
//
//bool TMonom::operator!=(const TMonom& m) const {
//	return !(*this == m);
//}
//
//bool comparePowers(TMonom m1, TMonom m2) { // сравнить m1 >= m2
//	if (m1.x < m2.x) return false;
//	else {
//		if (m1.y < m2.y) return false;
//		else {
//			if (m1.z < m2.z) return false;
//		}
//	}
//	return true;
//}
//
//TPolynomial::TPolynomial(int monoms[][4], int size) // monoms[][4] - массив из коэффициентов и степеней мономов, size - размер массива
//{
//	TMonom head(0, -1, -1, -1);
//	pHead->val = head;
//	for (int i = 0; i < size; i++) {
//		TMonom monom((double)monoms[i][0], monoms[i][1], monoms[i][2], monoms[i][3]);
//		insLast(monom);
//	}
//}
//
//TPolynomial::TPolynomial(const TPolynomial& p)
//{
//	TMonom head(0, -1, -1, -1);
//	pHead->val = head;
//	TNode<TMonom>* i = p.pFirst;
//	while (i != p.pStop) {
//		insLast(i->val);
//		i = i->pNext;
//	}
//}
//
//void TPolynomial::addMonom(TMonom m)
//{
//	reset();
//	TMonom i = getCurr();
//	while (!(isEnd()) && !comparePowers(m, i)) goNext(); // пока m < i - двигаем
//	// теперь pCurr указывает на место для вставки
//	if (pCurr != pStop) {
//		i = getCurr();
//		if (i.x == m.x && i.y == m.y && i.z == m.z) {
//			if (m.coeff + i.coeff == 0) delCurr();
//			else i.coeff = m.coeff + i.coeff;
//		}
//		else insCurr(m);
//	}
//	else insLast(m);
//}
//
//TPolynomial& TPolynomial::operator=(TPolynomial& p)
//{
//	if (this == &p) return *this;
//	clrList();
//	TMonom head(0, -1, -1, -1);
//	pHead->val = head;
//	for (p.reset(); !(p.isEnd()); p.goNext()) {
//		TMonom monom = p.getCurr();
//		insLast(monom);
//	}
//	return *this;
//}
//
//bool TPolynomial::operator==(const TPolynomial& list) const
//{
//	if (len != list.len) return false;
//	else {
//		TNode<TMonom>* i = pFirst, *j = list.pFirst;
//		while (i != pStop) {
//			if (i->val != j->val) return false;
//			i = i->pNext;
//			j = j->pNext;
//		}
//	}
//	return true;
//}
//
//bool TPolynomial::operator!=(const TPolynomial& list) const
//{
//	return !(*this == list);
//}
//
//TPolynomial& TPolynomial::operator*(double a)
//{
//	for (reset(); !(isEnd()); goNext()) {
//		getCurr().coeff *= a;
//	}
//	return *this;
//}
//
//TPolynomial& TPolynomial::operator*(TMonom& m)
//{
//	for (reset(); !(isEnd()); goNext()) {
//		getCurr().coeff *= m.coeff;
//		getCurr().x += m.x;
//		getCurr().y += m.y;
//		getCurr().z += m.z;
//	}
//	return *this;
//}
//
//TPolynomial& TPolynomial::operator+(TPolynomial& p)
//{
//	// МНОГОКРАТНЫЙ ПРОХОД ПО СПСКУ
//
//	// for (p.reset(); p.isEnd(); p.goNext())
//	//	addMonom(p.getCurr());
//
//	// ЧЕРЕЗ "СЛИЯНИЕ", ПАРАЛЛЕЛЬНЫЙ ПРОХОД ПО ОБОИМ СПИСКАМ
//
//	TMonom m, pm, rm;
//	reset();
//	p.reset();
//	while (pCurr != pStop) { // перенести брейк в условие while
//		m = getCurr();
//		pm = p.getCurr();
//		if (!comparePowers(m, pm)) {
//			// моном m < pm =>  добавляем моном pm в полином p
//			insCurr(pm);
//			p.goNext();
//		}
//		else if (m.x == pm.x && m.y == pm.y && m.z == pm.z) {
//			// индексы мономов равны (это могут быть головы)
//			if (m.x == -1) break;
//			m.coeff += pm.coeff;
//			if (m.coeff != 0) {
//				getCurr().coeff = m.coeff;
//				goNext();
//				p.goNext();
//			}
//			else {
//				// удаление монома с нулевыми коэффициентами
//				delCurr();
//				p.goNext();
//			}
//		}
//	}
//	return *this;
//}
//
////TPolynomial& TPolynomial::operator-(TPolynomial& p)
////{
////	*(this) = *(this) + p * (-1);
////	return *this;
////}
//
////std::ostream& operator<<(std::ostream& os, TPolynomial& p)
////{
////	TMonom curr;
////	for (p.reset(); p.isEnd(); p.goNext()) {
////		curr = p.getCurr();
////		os << curr.coeff << " * x^" << curr.x << " * y^" << curr.y << " * z^" << curr.z << " ";
////	}
////	return os;
////}
//
//std::string TPolynomial::outputPolynomial()
//{
//	std::string s = "";
//	TMonom curr;
//	int currcoeff;
//	for (reset(); !(isEnd()); goNext()) {
//		curr = getCurr();
//		currcoeff = curr.coeff;
//		if (pCurr != pFirst) s += " ";
//		if (currcoeff > 0) s += "+ ";
//		else if (currcoeff < 0) {
//			s += "- ";
//			currcoeff *= -1;
//		}
//		s += std::to_string(currcoeff) + "*x^(" + std::to_string(curr.x) + ")*y^(" + std::to_string(curr.y) + ")*z^(" + std::to_string(curr.z) + ")";
//	// преобразовать в ансайнд
//	}
//	return s;
//}