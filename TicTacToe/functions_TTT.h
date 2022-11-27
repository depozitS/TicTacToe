#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::cin;
using std::string;

void Xdraw(int layer);
void Odraw(int layer);
void draw(int typeLayer, int layer);

int output(int map[], int counter) {

		//строка 1
		for (int i = 0; i < 8; i++) {

			if ((i == 0) || (i == 5)) {
				cout << "       |       |";
			}
			else if ((i == 1) || (i == 2) || (i == 3) || (i == 4)) {

				
				draw(map[0], i);
				cout << " |";
				
				draw(map[1], i);
				cout << " |";
				
				draw(map[2], i);

			}
			else if (i == 6) {
				cout << "-----------------------";
			}

			cout << endl;
		
		}

		//cтрока 2
		for (int i = 0; i < 8; i++) {

			if ((i == 0) || (i == 5)) {
				cout << "       |       |";
			}
			else if ((i == 1) || (i == 2) || (i == 3) || (i == 4)) {


				draw(map[3], i);
				cout << " |";

				draw(map[4], i);
				cout << " |";

				draw(map[5], i);

			}
			else if (i == 6) {
				cout << "-----------------------";
			}

			cout << endl;

		}

		//строка 3
		for (int i = 0; i < 8; i++) {

			if ((i == 0) || (i == 5)) {
				cout << "       |       |";
			}
			else if ((i == 1) || (i == 2) || (i == 3) || (i == 4)) {


				draw(map[6], i);
				cout << " |";

				draw(map[7], i);
				cout << " |";

				draw(map[8], i);

			}
			else if (i == 6) {
				cout << "-----------------------";
			}

			cout << endl;

		}
	
	return 0;
}

int chekWin(int map[]) {  //return 0 - нет победы, 1 - х победил, 2 - о победил 
	
	if (
		//горизонталь
		((map[0] == 1) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 1) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 1) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//вертикаль
		((map[0] == 1) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 1) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 1) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//диагональ
		((map[0] == 1) && (map[0] == map[4]) && (map[0] == map[8])) ||
		((map[2] == 1) && (map[2] == map[4]) && (map[2] == map[6])))
		return 1;
	else if (
		//горизонталь
		((map[0] == 0) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 0) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 0) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//вертикаль
		((map[0] == 0) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 0) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 0) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//диагональ
		((map[0] == 0) && (map[0] == map[4]) && (map[0] == map[8])) ||
		((map[2] == 0) && (map[2] == map[4]) && (map[2] == map[6])))
		return 2;
	else {
		return 0;
	}
}

int play( int map[], int counter) {
	int win = 10;

	

	if (counter < 9) {
		//ход = step
		int step;
		if (counter % 2 == 0) {
			cout << "Ходит крестик" << endl;
			cin >> step;
			step -= 1;

			//проверка на возможность хода
			if (map[step] == 10) {
				map[step] = 1;
				system("cls");
			}
			else {
				cout << "сюда невозможно походить" << endl;
				return play(map, counter);
			}
			//проверили
		}
		else {
			cout << "Ходит нолик" << endl;
			cin >> step;
			step -= 1;
			//проверка на возможность хода
			if (map[step] == 10) {
				map[step] = 0;
				system("cls");
			}
			else {
				cout << "сюда невозможно походить" << endl;
				return play(map, counter);
			}
			//проверили
		}
		//проверка на победу
		if (chekWin(map) == 1) {
			return 1;
		}
		else if (chekWin(map) == 2) {
			return 2;
		}
		

		counter++;
		output(map, counter);
		
	}
	else {
		//ничья
		system("cls");
		return 0;
	}
	return play(map,counter);
}

void points(int a) {
	cout << endl;
	for (int i = 0; i < 30; i++) {
		cout << "[]";
		Sleep(50);
	}
	cout << endl;
	Sleep(1000);
	
}

void rules() {
	cout << "И так... что тут у нас? крестики нолики? ох бл..." << endl;
	Sleep(1000);
	cout << "ща.. ща, всё будет" ;
	points(10);

	system("cls");

	cout << setfill(' ') << setw(64) << "1|2|3" << endl;
	cout << "для хода введите число соответствующее нужной вам клетки - " << "4|5|6" << endl;
	cout << setfill(' ') << setw(64) << "7|8|9" << endl;
	
	cout << "у вас будет поле, которое постоянно обновляется, для победы надо собрать 3 ваших фигуры в ряд или по диагонали" << endl;
	Sleep(4000);
	cout << "Поле выглядит так" << endl << endl;
	
	int rul[9];
	for (int i = 0; i < 9; i++) {
		rul[i] = 10;
	}
	rul[0] = 1;
	rul[4] = 0;
	rul[8] = 1;
	output(rul, 1);

	cout << " крестики ходят первыми" << endl;
	cout << "введите что угодно для продолжения" << endl;
	string move;
	cin >> move;
	system("cls");
	
}

void Xdraw(int layer) { //6 на 4

	if (layer == 1) {
		cout << "\\\\  //";
	}
	else if (layer == 2) {
		cout << " \\\\// ";
	}
	else if (layer == 3) {
		cout << " //\\\\ " ;
	}
	else {
		cout << "//  \\\\";
	}
}

void Odraw(int layer) {  // 5 на 4

	if (layer == 1) {
		cout << " -----";
	}
	else if (layer == 2) {
		cout << " -   -";
	}
	else if (layer == 3) {
		cout << " -   -";
	}
	else {
		cout << " -----";
	}

	/*
	if (layer==5) {
	cout << "-----" << endl;
	cout << "|   |" << endl;
	cout << "|   |" << endl;
	cout << "-----" << endl;
	}
	*/
}

void draw(int typeLayer, int layer) {

	if (typeLayer == 10) {
		cout << "      ";
	}
	else if (typeLayer == 1) {
		Xdraw(layer);
	}
	else if (typeLayer == 0) {
		Odraw(layer);
	}
	else {
		cout << "не должно быть, но если случилось, пиздец";
	}

}
