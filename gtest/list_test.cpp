#include "gtest/gtest.h"
#include "../mp2-lab5-list/List.h"

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

//TEST(List, CAN_COPY_LIST) // Ошибка	C2678	бинарный "==": не найден оператор, принимающий левый операнд типа "const T1" (или приемлемое преобразование отсутствует)
//
//{
//	TList<int> l1;
//	l1.insLast(1);
//	TList<int> l2(l1);
//	EXPECT_EQ(l1, l2);
//}

//TEST(List, CAN_CREATE_EQUAL_LIST)
//{
//	TList<int> l1;
//	l1.insLast(1);
//	TList<int> l2 = l1;
//	EXPECT_EQ(l1, l2);
//}

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
	ADD_FAILURE();
}

/* -------------------------- ТЕСТЫ ДЛЯ TPolynomial  -------------------------- */

TEST(Polynomial, CAN_CREATE_POLYNOMIAL)
{
	ADD_FAILURE();
}