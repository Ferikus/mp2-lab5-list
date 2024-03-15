#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext = nullptr;
};

template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pLast, * pCurr, * pPr, * pStop;
	int pos, len;
public:
	TList()
	{
		pFirst = pLast = pCurr = pPr = pStop = nullptr;
		pos = -1; len = 0;
	}
	TList(const TList<T>& list)
	{
		TNode<T>* tmp = list.pFirst, * i;
		pFirst = pLast = nullptr;
		while (tmp != pStop) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == pStop) {
				pFirst = pLast = i;
			}
			else {
				pLast->pNext = i; // Вызвано исключение: нарушение доступа для записи. this->pLast было nullptr.
				pLast = i;
			}
			tmp = tmp->pNext;
		}
		pos = list.pos;
		len = list.len;
	}

	virtual void clrList() // очистить список
	{
		TNode<T>* tmp;
		while (pFirst != pStop) {
			tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		len = 0; pos = -1;
	}
	~TList() {
		clrList();
	}

	TList& operator=(const TList& list)
	{
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

	bool operator==(const TList& list) const
	{
		if (len != list.len) return false;
		else {
			TNode<T>* i = pFirst, *j = list.pFirst;
			while (i != pStop) {
				if (i->val != j->val) return false;
				i = i->pNext;
				j = j->pNext;
			}
		}
		return true;
	}

	bool operator!=(const TList& list) {
		return !(*this == list);
	}

	virtual inline bool empty() { return pFirst == pStop; } // проверить список на пустоту
	virtual inline void reset() // установить первый элемент списка как текущий
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;
	}
	virtual inline void goNext() // перейти к следующему элементу списка
	{
		if (pos <= -1 || pos >= len) throw "Current index is out of list";
		pPr = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	virtual inline bool isEnd() { return pStop == pCurr; } // проверить, дошёл ли текущий элемент списка до конца
	virtual inline void setpos(int _pos)
	{
		if (_pos <= -1 || _pos >= len) throw "Current index is out of list";
		reset();
		while (pos < _pos) {
			goNext();
		}
	}

	virtual void insFirst(T _val) // вставить элемент списка в начало
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		if (empty()) {
			pFirst = pLast = tmp;
			reset();
		}
		else {
			pFirst = tmp;
			pos++;
		}
		len++;
	}
	virtual void insLast(T _val) // вставить элемент списка в конец
	{
		if (empty()) insFirst(_val);
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			pLast->pNext = tmp;
			pLast = tmp;
			len++;
		}
	}
	virtual void insCurr(T _val) // вставить элемент списка перед текущим
	{
		if (empty()) throw "The list is empty: there is no current node";
		else if (pCurr == pFirst) insFirst(_val);
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			pos++; len++;
		}
	}
	virtual void delFirst() // удалить первый элемент списка
	{
		if (empty()) throw "The list is empty";
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--; pos--;
	}
	virtual void delCurr() // удалить текущий элемент списка
	{
		if (empty()) throw "The list is empty";
		if (pCurr == pStop) throw "The current position is our of the list";
		if (pCurr == pFirst) {
			delFirst();
		}
		else if (pCurr == pLast) {
			TNode<T>* tmp = pCurr;
			delete tmp;
			pCurr = pPr = pStop;
			pos = -1; len--;
		}
		else {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			len--;
		}
	}

	virtual inline T getCurr() // получить доступ к текущему элементу списка
	{
		if (pos <= -1 || pos >= len) throw "Current index is out of list";
		return pCurr->val;
	}
	virtual inline T getPr() // получить доступ к текущему элементу списка
	{
		if (pos <= -1 || pos >= len) throw "Current index is out of list";
		return pPr->val;
	}
};