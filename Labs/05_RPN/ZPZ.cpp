#include "stack.h"
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
int precedence(char op) {
	switch (op) {
	case '^': return 3;
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	default: return 0;
	}
}


 string remove_spaces(string line)
{
	string res;
	for (size_t i = 0; i < line.length(); ++i)
	{
		if (line[i] !=' ')
		{
			res += line[i];
		}
	}
	return res;
}
bool isOperator(char c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluate_v1(string expression) // 2+ ЦИФРОВІ
{
	stringstream ss(expression);
	string token;
	MyStack s1(expression.length());
	while (ss >> token) {
		if (isdigit(token[0])) {
			s1.push(stoi(token));
		}
		else if (isOperator(token[0])) {
			int b = s1.pop();
			int a = s1.pop();
			switch (token[0]) {
			case '+': s1.push(a + b); break;
			case '-': s1.push(a - b); break;
			case '*': s1.push(a * b); break;
			case '/':
				if (b == 0) {
					cout << "Division by zero!" << endl;
					break;
				}
				s1.push(a / b);
				break;
			case '^': s1.push((int)pow(a, b)); break;
			}
		}
	}

	return s1.pop();
}
string to_Postfix_v1(string line) {
	string postfix;
	MyStack s2(line.length());
	string number = "";  

	for (size_t i = 0; i < line.length(); ++i) {
		char c = line[i];
		if (isdigit(c)) {
			number += c;
		}
		else {
			if (!number.empty()) {
				postfix += number + " ";
				number = "";
			}

			if (c == '(') {
				s2.push((int)(c)); // оскільки чар можна перетворити силою в ІНТ(АСІІ код) то юзаємо!!
			}
			if (c == ')') {
				while (!s2.isEmpty() && s2.peek() != '(') {
					postfix += (char)(s2.pop()) + string(" "); // Тут назад в чар бо заповнюємо стрінг рядок
				}
				if (!s2.isEmpty()) s2.pop();
			}

			else if (isOperator(c)) {
				while (!s2.isEmpty() && precedence((char)(s2.peek())) >= precedence(c)) {
					postfix += (char)(s2.pop()) + string(" ");
				}
				s2.push((int(c)));
			}
		}
	}
	if (!number.empty()) {
		postfix += number + " ";
	}
	while (!s2.isEmpty()) {
		postfix += (char)(s2.pop()) + string(" ");
	}

	return postfix;
}
int main()
{
	string infix = "31 + 1";
	string calc = to_Postfix_v1(infix);
	cout << "Postfix: " << calc << endl;
	cout << "Result: " << evaluate_v1(calc) << "\n\n";

	string to_cal = "(10 + 2) * 3";
	cout << "Postfix: " << to_Postfix_v1(to_cal) << endl;
	cout << "Result: " << evaluate_v1(to_Postfix_v1(to_cal)) << endl;

	to_cal = "(22 + 6) / 7";
	cout << "Postfix: " << to_Postfix_v1(to_cal) << endl;
	cout << "Result: " << evaluate_v1(to_Postfix_v1(to_cal)) << endl;

	return 0;
}

