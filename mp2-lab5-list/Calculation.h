#pragma once
#include <string>
#include <cmath>
#include "Stack.h";
#include "Polynomial.h";

class TCalc
{
	std::string infix, postfix;
	TStack<int> D;
	TStack<char> C;
	int prior(char c) {
		switch (c) {
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

	double calc() {
		C.clear();  D.clear();
		std::string str = '(' + infix + ')';
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') C.push(str[i]);
			if (str[i] == ')') {
				char el = C.pop();
				while (el != '(') {
					double x2 = D.pop(),
						x1 = D.pop(),
						y;
					switch (el) {
					case '+': y = x1 + x2; break;
					case '-': y = x1 - x2; break;
					case '*': y = x1 * x2; break;
					case '/': {
						if (x2 == 0) throw "Division by 0";
						y = x1 / x2;
					} break;
					case '^': y = pow(x1, x2); break;
					}
					D.push(y);
					el = C.pop();
				}
			}
			if ((str[i] >= '0') && (str[i] <= '9')) {
				size_t pos;
				double x;
				x = std::stod(&str[i], &pos);
				D.push(x);
				i = i + pos - 1;
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
				char el = C.pop();
				while (prior(el) >= prior(str[i])) {
					double x2 = D.pop(),
						x1 = D.pop(),
						y;
					switch (el) {
					case '+': y = x1 + x2; break;
					case '-': y = x1 - x2; break;
					case '*': y = x1 * x2; break;
					case '/': {
						if (x2 == 0) throw "Division by 0";
						y = x1 / x2;
					} break;
					case '^': y = pow(x1, x2); break;
					}
					D.push(y);
					el = C.pop();
				}
				C.push(el);
				C.push(str[i]);
			}
		}
		return D.pop();
	}
	
	TPolynomial toPolynomial()
	{
		TPolynomial p;
		TMonom m;
		bool px, py, pz;
		C.clear();  D.clear();
		std::string str = infix;
		for (int i = 0; i < str.size(); i++) {
			px, py, pz = false;
			if ((str[i] == '+') || (str[i] == '-')) {
				C.push(str[i]);
			}
			if ((str[i] >= '0') && (str[i] <= '9')) { // коэффициент
				C.push(str[i]);
			}
			if (str[i] == '(') {
				if (px == false) { // если число стоит до скобок, то...
					int coeff = C.pop(); // установили коэффициент монома
					char sign = C.pop();
					if (sign == '-') m.setCoeff(-coeff);
					else m.setCoeff(coeff);
				}
				C.push(str[i]); // положили ( в стек
				i++;
				size_t pos;
				double x;
				x = std::stod(&str[i], &pos);
				D.push(x);
				i = i + pos - 1;
				// обрабатываем степень
				int power = C.pop();
				if (px == false) {
					m.setX(power);
					px = true;
				}
				else if (py == false) {
					m.setY(power);
					py = true;
				}
				else if (pz == false) {
					m.setZ(power);
					pz = true;
				}
			}
			if (str[i] == ')') {
			}
		}

		int i = 0;
		while (i < str.size()) {

		}

		return p;
	}
};