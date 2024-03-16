#pragma once
#include "List.h"

template <class T>
class THeadList: public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		this->TList::TList();
		pHead = new TNode<T>;
		pHead->pNext = pHead;
	}
	THeadList(const THeadList<T>& list) {
		this->TList::TList(list);
		pHead = new TNode<T>;
		pHead->val = list.pHead->val;
		pHead->pNext = pFirst;
	}
	~THeadList() {
		TList::clrList();
		delete pHead;
	}
	bool operator==(const THeadList& list) const
	{
		if (len != list.len) return false;
		else {
			TNode<T>* i = pFirst, * j = list.pFirst;
			while (i != pStop) {
				if (i->val != j->val) return false;
				i = i->pNext;
				j = j->pNext;
			}
		}
		return true;
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