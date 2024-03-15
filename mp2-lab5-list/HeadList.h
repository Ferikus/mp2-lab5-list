#pragma once
#include "List.h"

template <class T>
class THeadList: public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		TList::TList();
		pHead = new TNode<T>;
		pHead->pNext = pHead;
	}
	THeadList(const THeadList<T>& list) {
		TList::TList(list);
		pHead = list.pHead;
	}
	~THeadList() {
		TList::clrList();
		delete pHead;
	}
	virtual void insFirst(T _val) override {
		TList::insFirst(_val);
		pHead->pNext = pFirst;
	}
	virtual void delFirst() override {
		TList::delFirst();
		if (TList::empty()) pHead->pNext = pHead;
		else pHead->pNext = pFirst;
	}
};