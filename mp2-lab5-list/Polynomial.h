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

// ����, ����� + �����������, ������������ + �������������� �������� (+, -, *a), ��������� + ���: ��������� ��������� ����� ���������� �� �����, ���������� 1 ������