#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "Stack.h";
#include "Polynomial.h";

class TCalc
{
	std::string infix, postfix;
	TStack<int> D;
	TStack<char> C;
	TStack<TPolynomial> E;
	int prior(char c) {
		switch (c) {
		case '[': return 0;
		case ']': return 0;
		case '(': return 0;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		}
	}
public:
	TCalc() {}

	TCalc(std::string s):infix(s) {
		toPostfix();
	}

	void setInfix(std::string s) { infix = s; }

	std::string getInfix() { return infix; }

	std::string getPostfix() { return postfix; }

	void toPostfix() {
		C.clear();
		std::string str = '(' + infix + ')';
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') C.push('(');
			if (isdigit(str[i])) postfix += str[i];
			if (str[i] == ')') {
				char el = C.pop();
				while (el != '(') {
					postfix += el;
					el = C.pop();
				}
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
				char el = C.pop();
				while (prior(el) >= prior(str[i])) {
					postfix += el;
					el = C.pop();
				}
				C.push(el);
				C.push(str[i]);
			}
		}
	}

	bool checkExpression() {
		int res = true;
		for (int i = 0; i < infix.size(); i++) {
			if (infix[i] == '(') C.push('(');
			if (infix[i] == ')') {
				if (!C.empty()) C.pop();
				else res = false;
			}
		}
		if (!C.empty()) res = false;
		return res;
	}

	//double calc() {
	//	C.clear();  D.clear();
	//	std::string str = '(' + infix + ')';
	//	for (int i = 0; i < str.size(); i++) {
	//		if (str[i] == '(') C.push(str[i]);
	//		if (str[i] == ')') {
	//			char el = C.pop();
	//			while (el != '(') {
	//				double x2 = D.pop(),
	//					x1 = D.pop(),
	//					y;
	//				switch (el) {
	//				case '+': y = x1 + x2; break;
	//				case '-': y = x1 - x2; break;
	//				case '*': y = x1 * x2; break;
	//				case '/': {
	//					if (x2 == 0) throw "Division by 0";
	//					y = x1 / x2;
	//				} break;
	//				case '^': y = pow(x1, x2); break;
	//				}
	//				D.push(y);
	//				el = C.pop();
	//			}
	//		}
	//		if ((str[i] >= '0') && (str[i] <= '9')) {
	//			size_t pos;
	//			double x;
	//			x = std::stod(&str[i], &pos);
	//			D.push(x);
	//			i = i + pos - 1;
	//		}
	//		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
	//			char el = C.pop();
	//			while (prior(el) >= prior(str[i])) {
	//				double x2 = D.pop(),
	//					x1 = D.pop(),
	//					y;
	//				switch (el) {
	//				case '+': y = x1 + x2; break;
	//				case '-': y = x1 - x2; break;
	//				case '*': y = x1 * x2; break;
	//				case '/': {
	//					if (x2 == 0) throw "Division by 0";
	//					y = x1 / x2;
	//				} break;
	//				case '^': y = pow(x1, x2); break;
	//				}
	//				D.push(y);
	//				el = C.pop();
	//			}
	//			C.push(el);
	//			C.push(str[i]);
	//		}
	//	}
	//	return D.pop();
	//}
	
	TPolynomial toPolynomial()
	{
		TPolynomial p;
		TMonom m;
		int i = 0;
		char sign;
		int coeff, pow;

		// вспомогательные переменные
		size_t pos;
		bool px, py, pz;
		
		C.clear();
		std::string str = infix;
		while (i < str.size()) {
			// обрабатывать по моному за проход
			if (str[i] == '+' || str[i] == '-') {
				C.push(str[i]);
				i++;
			}
			if ((str[i] >= '0') && (str[i] <= '9')) { // коэффициент
				sign = C.pop();

				coeff = std::stoi(&str[i], &pos);
				i = i + pos;

				if (sign == '+') m.coeff = coeff;
				else if (sign == '-') m.coeff = -coeff;
			}
			px = py = pz = false;
			while (str[i] != '+' && str[i] != '-' && (i < str.size())) {
				if (str[i] == '(') { // степень
					C.push(str[i]);
					i++;

					pow = std::stoi(&str[i], &pos);
					i = i + pos;

					if (px == false) {
						m.x = pow;
						px = true;
					}
					else if (py == false) {
						m.y = pow;
						py = true;
					}
					else if (pz == false) {
						m.z = pow;
						pz = true;
					}
				}
				if (str[i] == ')') {
					C.pop();
					i++;
				}
			}
			p.addMonom(m);
		}
		return p;
	}


	TPolynomial& calcPolynomial(std::vector<TPolynomial> v) {
		C.clear(); D.clear();
		std::string str = '(' + infix + ')';
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') C.push(str[i]);
			if (str[i] == ')') {
				char el = C.pop();
				while (el != '(') {
					TPolynomial y;
					switch (el) {
					case '+': {
						TPolynomial x2 = E.pop(),
							x1 = E.pop();
						y = x1 + x2;
					} break;
					case '-': {
						TPolynomial x2 = E.pop(),
							x1 = E.pop();
						y = x1 - x2;
					} break;
					case '*': {
						TPolynomial x2 = E.pop();
						int x1 = D.pop();
						y = x2 * x1;
					} break;
					}
					E.push(y);
					el = C.pop();
				}
			}
			if (str[i] == '[') {
				// обработка полиномов вида [i], полный обход до ']'
				i++;
				size_t pos;
				int idx;
				idx = std::stoi(&str[i], &pos);
				E.push(v[idx]);
				i = i + pos;
			}
			if ((str[i] >= '0') && (str[i] <= '9')) {
				char el = C.pop();
				size_t pos;
				int coeff;
				coeff = std::stoi(&str[i], &pos);
				E.push(v[coeff]);
				i = i + pos - 1;
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*')) {
				char el = C.pop();
				while (prior(el) >= prior(str[i])) {
					TPolynomial y;
					switch (el) {
					case '+': {
						TPolynomial x2 = E.pop(),
							x1 = E.pop();
						y = x1 + x2;
					} break;
					case '-': {
						TPolynomial x2 = E.pop(),
							x1 = E.pop();
						y = x1 - x2;
					} break;
					case '*': {
						TPolynomial x2 = E.pop();
						int x1 = D.pop();
						y = x2 * x1;
					} break;
					}
					E.push(y);
					el = C.pop();
				}
				C.push(el);
				C.push(str[i]);
			}
		}
		TPolynomial res = E.pop();
		return res;
	}
};