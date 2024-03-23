#pragma once
#include <iostream>

template <class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int _MaxSize = 10) {
		if (_MaxSize <= 0) throw "Wrong size";
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	TStack(const TStack& s) {
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
		for (int i = 0; i < CurrInd + 1; i++) {
			pMem[i] = s.pMem[i];
		}
	}
	int getMaxSize() { return MaxSize; }
	int getLength() { return CurrInd + 1; }
	TStack& operator= (const TStack& s) {
		if (MaxSize != s.MaxSize) {
			delete[] pMem;
			MaxSize = s.MaxSize;
			pMem = new T[MaxSize];
		}
		CurrInd = s.CurrInd;
		for (int i = 0; i < CurrInd + 1; i++) {
			pMem[i] = s.pMem[i];
		}
	}
	friend std::ostream& operator<< (std::ostream& os, const TStack& s) {
		for (int i = 0; i < s.CurrInd; i++) {
			os << s.pMem[i] << " ";
		}
		return os;
	}
	bool empty() { return CurrInd == -1; }
	bool full() { return CurrInd == (MaxSize - 1); }
	void push(const T& el) {
		if (CurrInd + 1 >= MaxSize) throw "Stack overflow";
		CurrInd++;
		pMem[CurrInd] = el;
	}
	T pop() {
		if (empty()) throw "Stack is empty";
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	T top() {
		if (empty()) throw "Stack is empty";
		return pMem[CurrInd + 1];
	}
	void clear() {
		CurrInd = -1;
	}
};