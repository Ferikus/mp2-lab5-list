#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pLast,, * pCurr, * pPr;
	const TNode<T>* pStop;
	int pos, len;
public:
	TList() {
		pStop = nullptr;
		pFirst = pLast = pCurr = pPr = pStop;
		pos = -1;
		len = 0;
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
		while !(empty()) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	TList& operator=(const TList& list) {
		// ?
	}

	bool empty() { return pFirst == pStop;  }

	T insFirst(T _val) // вставить элемент списка в начало
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		pFirst = tmp;
		pos++; len++;
	}
	T insLast(T _val) // вставить элемент списка в конец
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pLast->pNext = tmp;
		pos++; len++;
	}
	T insCurr(T _val) // вставить элемент списка перед текущим
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pPr->pNext = tmp;
		tmp->pNext = pCurr;
		pPr = tmp;
		pos++; len++;
	}
	void delFirst() // удалить первый элемент списка НЕ ДОДЕЛАЛ
	{
		TNode<T>* tmp = pFirst;
		pFirst->pNext = pFirst;
		delete tmp;
		len--; pos--;
	}
	void delLast() // удалить последний элемент списка
	{
		TNode<T>* tmp = pLast;
		
		delete tmp;
		len--;
	}
	void delCurr() // удалить текущий элемент списка
	{
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPr->pNext = pCurr;
		delete tmp;
		len--; pos++;
	}
	void clrList() // ?
	{
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	TNode<T> getCurr() { return *pCurr; } // получить доступ к текущему элементу списка
	void reset(); // установить первый элемент списка как текущий
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;
	}
	void goNext(); // перейти к следующему элементу списка
	{
		pPr = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool isEnd() { return pStop == pCurr; }; // проверить, дошёл ли текущий элемент списка до конца
	void setpos(int _pos) {
		pos = _pos;
		pCurr = pFirst;
		for (int i = 0; i < pos; i++) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
		}
	};
};