#include "gtest/gtest.h"
#include "../mp2-lab5-list/List.h"
#include "../mp2-lab5-list/HeadList.h"
#include "../mp2-lab5-list/Polynomial.h"

/* -------------------------- ТЕСТЫ ДЛЯ TList -------------------------- */

TEST(List, CAN_CREATE_LIST)
{
	EXPECT_NO_THROW(TList<int> l);
}

TEST(List, CAN_GET_CURRENT_NODE)
{
	TList<int> l;
	l.insLast(1);  l.insLast(2);
	l.goNext();
	EXPECT_NO_THROW(l.getCurr());
	EXPECT_EQ(2, l.getCurr());
}

TEST(List, SET_POSITION_IS_CORRECT)
{
	TList<int> l;
	int N = 1;
	l.insLast(1);  l.insLast(2); l.insLast(3);
	EXPECT_NO_THROW(l.setpos(N));
	int curr1 = l.getCurr();
	l.reset();
	for (int i = 0; i < N; i++) l.goNext();
	int curr2 = l.getCurr();
	EXPECT_EQ(curr1, curr2);
}

TEST(List, CAN_INSERT_FIRST_NODE)
{
	TList<int> l;
	EXPECT_NO_THROW(l.insFirst(1));
	l.setpos(0);
	EXPECT_EQ(1, l.getCurr());
}

TEST(List, CAN_INSERT_LAST_NODE)
{
	TList<int> l;
	l.insFirst(1);
	EXPECT_NO_THROW(l.insLast(2));
	l.setpos(1);
	EXPECT_EQ(2, l.getCurr());
}

TEST(List, CAN_INSERT_CURRENT_NODE)
{
	TList<int> l;
	l.insLast(1); l.insLast(2);
	l.setpos(1);
	l.insCurr(3);
	EXPECT_EQ(2, l.getCurr());
	EXPECT_EQ(3, l.getPr());
}

TEST(List, CAN_COPY_LIST)

{
	TList<int> l1;
	l1.insLast(1);
	TList<int> l2(l1);
	EXPECT_EQ(l1, l2);
}

TEST(List, CAN_CREATE_EQUAL_LIST)
{
	TList<int> l1;
	l1.insLast(1);
	TList<int> l2 = l1;
	EXPECT_EQ(l1, l2);
}

TEST(List, EMPTY_LIST_IS_EMPTY)
{
	TList<int> l;
	EXPECT_TRUE(l.empty());
	l.insLast(1);
	EXPECT_FALSE(l.empty());
}

TEST(List, CLEARED_LIST_IS_EMPTY)
{
	TList<int> l;
	l.insLast(1);
	EXPECT_FALSE(l.empty());
	l.clrList();
	EXPECT_TRUE(l.empty());
}

TEST(List, CAN_DELETE_FIRST_NODE)
{
	TList<int> l1, l2;
	l1.insFirst(1);
	EXPECT_NO_THROW(l1.delFirst());
	EXPECT_TRUE(l1.empty());
	EXPECT_ANY_THROW(l2.delFirst());
}

TEST(List, CAN_DELETE_CURRENT_NODE)
{
	TList<int> l;
	l.insLast(1); l.insLast(2); l.insLast(3);
	l.setpos(1);
	EXPECT_NO_THROW(l.delCurr());
}

/* -------------------------- ТЕСТЫ ДЛЯ THeadList -------------------------- */

TEST(HeadList, CAN_CREATE_HEADLIST)
{
	EXPECT_NO_THROW(THeadList<int> l);
}

TEST(HeadList, CAN_GET_CURRENT_NODE)
{
	THeadList<int> l;
	l.insLast(1);  l.insLast(2);
	l.goNext();
	EXPECT_NO_THROW(l.getCurr());
	EXPECT_EQ(2, l.getCurr());
}

TEST(HeadList, SET_POSITION_IS_CORRECT)
{
	THeadList<int> l;
	int N = 1;
	l.insLast(1);  l.insLast(2); l.insLast(3);
	EXPECT_NO_THROW(l.setpos(N));
	int curr1 = l.getCurr();
	l.reset();
	for (int i = 0; i < N; i++) l.goNext();
	int curr2 = l.getCurr();
	EXPECT_EQ(curr1, curr2);
}

TEST(HeadList, CAN_INSERT_FIRST_NODE)
{
	THeadList<int> l;
	EXPECT_NO_THROW(l.insFirst(1));
	l.setpos(0);
	EXPECT_EQ(1, l.getCurr());
}

TEST(HeadList, CAN_INSERT_LAST_NODE)
{
	THeadList<int> l;
	l.insFirst(1);
	EXPECT_NO_THROW(l.insLast(2));
	l.setpos(1);
	EXPECT_EQ(2, l.getCurr());
}

TEST(HeadList, CAN_INSERT_CURRENT_NODE)
{
	THeadList<int> l;
	l.insLast(1); l.insLast(2);
	l.setpos(1);
	l.insCurr(3);
	EXPECT_EQ(2, l.getCurr());
	EXPECT_EQ(3, l.getPr());
}

TEST(HeadList, CAN_COPY_LIST)

{
	THeadList<int> l1;
	l1.insLast(1);
	THeadList<int> l2(l1);
	EXPECT_EQ(l1, l2);
}

TEST(HeadList, CAN_CREATE_EQUAL_LIST)
{
	THeadList<int> l1;
	l1.insLast(1);
	THeadList<int> l2 = l1;
	EXPECT_EQ(l1, l2);
}

TEST(HeadList, EMPTY_LIST_IS_EMPTY)
{
	THeadList<int> l;
	EXPECT_TRUE(l.empty());
	l.insLast(1);
	EXPECT_FALSE(l.empty());
}

TEST(HeadList, CLEARED_LIST_IS_EMPTY)
{
	THeadList<int> l;
	l.insLast(1);
	EXPECT_FALSE(l.empty());
	l.clrList();
	EXPECT_TRUE(l.empty());
}

TEST(HeadList, CAN_DELETE_FIRST_NODE)
{
	THeadList<int> l1, l2;
	l1.insFirst(1);
	EXPECT_NO_THROW(l1.delFirst());
	EXPECT_TRUE(l1.empty());
	EXPECT_ANY_THROW(l2.delFirst());
}

TEST(HeadList, CAN_DELETE_CURRENT_NODE)
{
	THeadList<int> l;
	l.insLast(1); l.insLast(2); l.insLast(3);
	l.setpos(1);
	EXPECT_NO_THROW(l.delCurr());
}

/* -------------------------- ТЕСТЫ ДЛЯ TPolynomial  -------------------------- */

TEST(Polynomial, CAN_CREATE_POLYNOMIAL)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int)); // 4 - количество элементов в массиве
	EXPECT_NO_THROW(TPolynomial p(p1m, size1));
}

TEST(Polynomial, CAN_COPY_POLYNOMIAL)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	TPolynomial p2(p1);
	EXPECT_EQ(p1, p2);
}

TEST(Polynomial, CAN_CREATE_EQUAL_POLYNOMIAL)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	TPolynomial p2 = p1;
	EXPECT_EQ(p1, p2);
}

TEST(Polynomial, CAN_COMPARE_POWERS)
{
	TMonom m1 = {0, 3, 2, 2}, m2 = {0, 3, 2, 1}, m3 = {0, 3, 2, 0};
	EXPECT_TRUE(comparePowers(m1, m2)); // m2 >= m1 ? yes
	EXPECT_FALSE(comparePowers(m3, m1)); // m3 >= m1 ? no
}

TEST(Polynomial, CAN_ADD_MONOM)
{
	//вставка в конец
	int p1m[][4] = { {-2, 6, 4, 3}, {1, 5, 4, 3} };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	TMonom m = { 1, 4, 2, 1 };
	EXPECT_NO_THROW(p1.addMonom(m));
	int p2m[][4] = { {-2, 6, 4, 3}, {1, 5, 4, 3}, {1, 4, 2, 1} };
	int size2 = sizeof(p2m) / (4 * sizeof(int));
	TPolynomial p2(p2m, size2);
	EXPECT_EQ(p1, p2);

	//вставка в середину
	int p3m[][4] = { {-2, 5, 5, 5}, {1, 5, 3, 9} };
	int size3 = sizeof(p3m) / (4 * sizeof(int));
	TPolynomial p3(p3m, size3);
	TMonom n = { 1, 5, 4, 7 };
	EXPECT_NO_THROW(p3.addMonom(n));
	int p4m[][4] = { {-2, 5, 3, 3}, {1, 5, 4, 7}, {1, 5, 5, 5} };
	int size4 = sizeof(p4m) / (4 * sizeof(int));
	TPolynomial p4(p4m, size4);
	EXPECT_EQ(p3, p4);

	//мономы с одинаковыми степенями
	int p5m[][4] = { {-2, 6, 4, 3}, {1, 5, 4, 3} };
	int size5 = sizeof(p5m) / (4 * sizeof(int));
	TPolynomial p5(p5m, size5);
	TMonom q = { 2, 6, 4, 3 };
	EXPECT_NO_THROW(p5.addMonom(q));
	int p6m[][4] = { {1, 5, 4, 3} };
	int size6 = sizeof(p6m) / (4 * sizeof(int));
	TPolynomial p6(p6m, size6);
	EXPECT_EQ(p5, p6);
}

TEST(Polynomial, CAN_ADD_POLYNOMIAL)
{
	//int p1m[][4] = { {-2, 6, 4, 3}, {1, 5, 4, 3} };
	int p1m[][4] = { {5, 8, 3, 4}, { 2, 8, 1, 6 }, { 6, 3, 6, 1 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	//int p2m[][4] = { {2, 6, 4, 3}, {1, 5, 5, 7}, {2, 5, 4, 3} };
	int p2m[][4] = { {5, 8, 3, 4}, { -2, 8, 1, 6 }, { 8, 1, 4, 2 } };
	int size2 = sizeof(p2m) / (4 * sizeof(int));
	TPolynomial p2(p2m, size2);
	TPolynomial p3;
	p3 = p1 + p2;
	//int p4m[][4] = { {1, 5, 5, 7}, {3, 5, 4, 3} };
	int p4m[][4] = { {10, 8, 3, 4}, {6, 3, 6, 1}, {8, 1, 4, 2} };
	int size4 = sizeof(p4m) / (4 * sizeof(int));
	TPolynomial p4(p4m, size4);
	EXPECT_EQ(p3, p4);
}

TEST(Polynomial, CAN_MULTIPLY_BY_CONST)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	double a = 5;
	p1 = p1 * a;
	int p2m[][4] = { {-2 * a, 6, 4, 3}, { 1 * a, 5, 4, 3 } };
	int size2 = sizeof(p2m) / (4 * sizeof(int));
	TPolynomial p2(p2m, size2);
	EXPECT_EQ(p1, p2);
}

TEST(Polynomial, CAN_MULTIPLY_BY_MONOM)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	TMonom m = { 2, 1, 1, 1 };
	p1 = p1 * m;
	int p2m[][4] = { {-4, 7, 5, 4}, { 2, 6, 5, 4 } };
	int size2 = sizeof(p2m) / (4 * sizeof(int));
	TPolynomial p2(p2m, size2);
	EXPECT_EQ(p1, p2);
}

TEST(Polynomial, OUTPUTS_POLYNOMIAL_CORRECTLY)
{
	int p1m[][4] = { {-2, 6, 4, 3}, { 1, 5, 4, 3 } };
	int size1 = sizeof(p1m) / (4 * sizeof(int));
	TPolynomial p1(p1m, size1);
	std::string s1 = "- 2*x^(6)*y^(4)*z^(3) + 1*x^(5)*y^(4)*z^(3)";
	std::string s2 = p1.outputPolynomial();
	EXPECT_EQ(s1, s2);
}