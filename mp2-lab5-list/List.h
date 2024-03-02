#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pLast, * pCurr, * pPr;
	const TNode<T>* pStop = nullptr;
	int pos, len;
public:
	TList() {
		pFirst = pLast = pCurr = pPr = pStop;
		pos = -1; len = 0;
	}
	TList(const TList& list) {
		TNode<T>* tmp = list.pFirst, * i;
		pFirst = pLast = nullptr;
		while (tmp != pStop) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == pStop) {
				pFirst = pLast = i;
			}
			else {
				pLast->pNext = i;
				pLast = i;
			}
		}
		tmp = tmp->pNext;
		pos = list.pos;
		len = list.len;
	}
	~TList() {
		while (!empty()) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	TList& operator=(const TList& list) {
		if (&list == this) return *this;
		clrList();
		TNode<T>* tmp = list.pFirst, * i;
		pFirst = pLast = nullptr;
		while (tmp != pStop) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == pStop) {
				pFirst = pLast = i;
			}
			else {
				pLast->pNext = i;
				pLast = i;
			}
		}
		tmp = tmp->pNext;
		pos = list.pos;
		len = list.len;
		return *this;
	}

	bool empty() { return pFirst == pStop; } // проверить список на пустоту
	bool isEnd() { return pStop == pCurr; }; // проверить, дошёл ли текущий элемент списка до конца

	virtual T insFirst(T _val) // вставить элемент списка в начало
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		pFirst = tmp;
		pos++; len++;
	}
	virtual T insLast(T _val) // вставить элемент списка в конец
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pLast->pNext = tmp;
		pos++; len++;
	}
	virtual T insCurr(T _val) // вставить элемент списка перед текущим
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pPr->pNext = tmp;
		tmp->pNext = pCurr;
		pPr = tmp;
		pos++; len++;
	}
	virtual void delFirst() // удалить первый элемент списка
	{
		TNode<T>* tmp = pFirst;
		pFirst->pNext = pFirst;
		delete tmp;
		len--; pos--;
	}
	virtual void delCurr() // удалить текущий элемент списка
	{
		if (pCurr != pStop) {
			if (pCurr == pFirst) {
				delFirst();
				return;
			}
			if (pCurr == pLast) {
				TNode<T>* tmp = pCurr;
				delete tmp;
				pCurr = pStop;
				pos = -1; len--;
				return;
			}
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			len--; pos++;
			return;
		}
	}
	void clrList() // очистить список
	{
		TNode<T>* tmp = pFirst;
		while (!isEnd()) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	TNode<T> getCurr() { return *pCurr; } // получить доступ к текущему элементу списка
	void reset() // установить первый элемент списка как текущий
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;
	}
	void goNext() // перейти к следующему элементу списка
	{
		pPr = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	void setpos(int _pos) {
		pos = _pos;
		pCurr = pFirst;
		for (int i = 0; i < pos; i++) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
		}
	};
};

template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pFirst = pLast = pPr = pCurr = pHead = pStop;
		pos = -1; len = 0;
	}
	~THeadList() {
		TList::delList();
		delete pHead;
	}
	void insFirst(T _val) override {
		TList::insFirst(_val);
		pHead->pNext = pFirst;
	}
	void insLast(T _val) override {
		TList::insLast(_val);
	}
	void insCurr(T _val) override {
		TList::insCurr(_val);
	}
	void delFirst(T _val) override {
		TList::delFirst(_val);
	}
	void delCurr(T _val) override {
		TList::delCurr(_val);
	}
};

struct TMonom {
	double coef;
	int index;
};

//template <class T>
//class Polynom : public THeadList<T> {
//};