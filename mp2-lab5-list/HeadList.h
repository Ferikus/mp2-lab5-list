#pragma once
#include "List.h"

template <class T>
class THeadList: public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		TList();
		pHead = new TNode<T>;
		pHead->pNext = pHead;
	}
	~THeadList() {
		TList::clrList();
		delete pHead;
	}
	void insFirst(T _val) override {
		TList::insFirst(_val);
		pHead->pNext = pFirst;
	}
	void delFirst(T _val) override {
		TList::delFirst(_val);
		if (empty()) pHead->pNext = pHead;
		else pHead->pNext = pFirst;
	}
};