/*
������� Dep
*/

#include "functions_TTT.h"
#include <iostream>
#include <Windows.h>
#include <string>

using std::cout; 
using std::cin;
using std::endl;
using std::string;


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "�������? (1 - ��, ����� ������ �������� - ���)" << endl;
	string rls;
	cin >> rls;
	if (rls.compare("1") == 0) {
		rules();
	}

	int count = 0;
	int map[9];
	for (int i = 0; i < 9; i++) {
		map[i] = 10;
	}
	

	int winner=play(map,count);
	
	// ��������� �����
	output(map, 1);

	if (winner == 0) {
		cout << "�����";
	}
	else if (winner == 1) {
		cout << "������� �������!";
	}
	else if (winner == 2) {
		cout << "������� �����!";
	}
	else {
		cout << "��� �� ����� �� ���, ����� ����� �������";
	}
	cout << endl << "������� ��� ������ ��� �����������" << endl;
	cin >> rls;

	return 0;
}