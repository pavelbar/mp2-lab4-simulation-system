//--
#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	string expression;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "������� �������������� ���������: ";
	cin >> expression;
	cout << expression << endl;
	TPostfix postfix(expression);
	cout << "�������������� ���������: " << postfix.GetInfix() << endl;
	postfix.ToPostfix();
	cout << "����������� �����: " << postfix.GetPostfix() << endl;
	res = postfix.Calculate();
	cout << res << endl;
	return 0;
}