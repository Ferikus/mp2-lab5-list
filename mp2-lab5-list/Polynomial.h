#pragma once
#include "HeadList.h"

struct TMonom {
	double coef;
	int index;
};

template <class T>
class TPolynomial: public THeadList<T> {
public:
};

// ввод, вывод + копирование, присваивание + арифметическое операции (+, -, *a), сравнение + доп: умножение полиномов через домножение на моном, добавление 1 монома