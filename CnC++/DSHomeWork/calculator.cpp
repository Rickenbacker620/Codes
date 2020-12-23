#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "stack_2.h"
using namespace std;

const char* prec[8] = {">><<<>>", ">><<<>>", ">>>><>>", ">>>><>>", "<<<<<=@", ">>>>@>>", "<<<<<@=", ">>>>>>>"};
const char sign[] = "+-*/()#";

class Calculator
{
public:
	char precede(char a, char b);
	double calc(double a, char op, double b);
	double maintain();
	void setStr()
	{
		cout << "请输入表达式" << endl;
		cin >> str;
	}

private:
	Mystack<char> ostk;
	Mystack<double> nstk;
	string str;
};

double Calculator::calc(double a, char op, double b)
{
	switch (op)
	{
		case '+':
			return a+b;
		case '-':
			return b-a;
		case '*':
			return a*b;
		case '/':
			return b/a;
	}
	return 0;
}

char Calculator::precede(char a, char b)
{
	int i, j;
	i = j = 0;
	while (sign[i] != a) i++;
	while (sign[j] != b) j++;
	return prec[i][j];
}

double Calculator::maintain()
{
	int num;
	char theta;
	double a, b;
	ostk.push('#');
	int i = 0;
	while (str[i] != '#' || ostk.getTop() != '#')
	{
		int t = str[i];
		if (t >= '0' && t <= '9')
		{
			string res;
			stringstream ss;
			double num = 0;
			while ((t >= '0' && t <= '9') || t == '.')
			{
				res += t;
				t = str[++i];
			}
			ss << res;
			ss >> num;
			nstk.push(num);
		}
		else
			switch (precede(ostk.getTop(), str[i]))
				{
				case '<':
					ostk.push(str[i++]);
					break;
				case '=':
					ostk.pop();
					i++;
					break;
				case '>':
				{
					theta = ostk.pop();
					a = nstk.pop();
					b = nstk.pop();
					nstk.push(calc(a, theta, b));
					break;
				}
			}
	}
	return nstk.getTop();
}

int main()
{
	Calculator a;
	a.setStr();
	double result = a.maintain();
	cout << endl << "结果为:" << result;
	getchar();
	getchar();
	return 0;
}