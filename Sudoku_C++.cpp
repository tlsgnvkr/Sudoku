#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

vector<vector<int>> board(9, vector<int>(9, -1));
vector<vector<int>> base(9, vector<int>(9, -1));

void textColor(int, int);
void boardSet();
int selectNumber(int, int);
void randomCoverNumber(int);
vector<int> vectorReset(vector<int>, int);
void printBoard(int, int);
vector<int> countNumber();
int left(int);
int right(int);
int up(int);
int down(int);
void input0(int, int);
void input1(int, int);
void input2(int, int);
void input3(int, int);
void input4(int, int);
void input5(int, int);
void input6(int, int);
void input7(int, int);
void input8(int, int);
void del(int, int);
void checkBoard();
int testBoard();

#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define NUM0 48
#define NUM1 49
#define NUM2 50
#define NUM3 51
#define NUM4 52
#define NUM5 53
#define NUM6 54
#define NUM7 55
#define NUM8 56
#define SPACE 32

void textColor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void boardSet() {
	vector<int> cell(9, 0);

	int y = 0, x = 0;
	while (1) {
		int num = selectNumber(y, x);
		if (num == -1) {
			for (int i = 0; i < x; i += 1) {
				board[y][i] = -1;
			}
			x = 0;
			continue;
		}
		else {
			board[y][x] = num;
			x == 8 ? y += 1, x = 0 : x += 1;
		}

		if (x == 0 && y == 9) break;
	}

	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			base[i][j] = board[i][j];
		}
	}
}

int selectNumber(int y, int x) {
	vector<int> li(9, 1);
	vector<int> list(9, 0);

	for (int i = 0; i < x; i += 1) {
		if (board[y][i] != -1) li[board[y][i]] = 0;
	}

	for (int i = 0; i < y; i += 1) {
		if (board[i][x] != -1) li[board[i][x]] = 0;
	}

	int ys = (y / 3) * 3;
	int yf = ys + 3;
	int xs = (x / 3) * 3;
	int xf = xs + 3;

	for (int i = ys; i < yf; i += 1) {
		for (int j = xs; j < xf; j += 1) {
			if (i != y || j != x) {
				if (board[i][j] != -1) li[board[i][j]] = 0;
			}
		}
	}

	int c = 0;

	for (int i = 0; i < 9; i += 1) {
		if (li[i]) {
			list[c] = i;
			c += 1;
		}
	}

	if (c == 0) {
		return -1;
	}

	else {
		int n = rand() % c;
		int N = list[n];

		return N;
	}
}

void randomCoverNumber(int x) {
	vector<int> A(x);

	for (int i = 0; i < x; i += 1) {
		A[i] = rand() % 81;
		for (int j = 0; j < i; j += 1) {
			if (A[j] == A[i]) {
				i -= 1;
				continue;
			}
		}
	}

	for (int i = 0; i < x; i += 1) {
		int c = A[i] / 9;
		int d = A[i] % 9;

		board[c][d] = -1;
	}
}

vector<int> vectorReset(vector<int> X, int n) {
	vector<int> A;

	for (int i = 0; i < X.size(); i += 1) {
		if (X[i] != n) {
			A.push_back(X[i]);
		}
	}

	return A;
}

void printBoard(int x, int y) {
	system("cls");

	int N = -1;
	if (board[y][x] != -1) N = board[y][x] % 10;

	for (int i = 0; i < 3; i += 1) {
		for (int j = 3 * i; j < 3 * i + 3; j += 1) {
			if (j == 0) {
				cout << "忙式式式式式式式式式成式式式式式式式式式成式式式式式式式式式忖" << endl;
			}
			else if (j == 3 or j == 6) {
				cout << "戍式式式式式式式式式托式式式式式式式式式托式式式式式式式式式扣" << endl;
			}

			for (int k = 0; k < 9; k += 1) {
				int a = 1;

				if (k % 3 == 0) cout << "弛";

				if (j == y && k == x) {
					if (100 <= board[j][k] && board[j][k] <= 108) {
						textColor(9, 6);
					}
					else if (1100 <= board[j][k] && board[j][k] <= 1108) {
						textColor(9, 6);
					}
					else textColor(0, 6);

					a *= 0;
				}
				else if (100 <= board[j][k] && board[j][k] <= 108) {
					if (board[j][k] % 10 == N) textColor(9, 14);
					else textColor(9, 0);
					a *= 0;
				}
				else if (1000 <= board[j][k] && board[j][k] <= 1008) {
					textColor(15, 12);
					a *= 0;
				}
				else if (1100 <= board[j][k] && board[j][k] <= 1108) {
					textColor(9, 12);
					a *= 0;
				}
				else if (board[j][k] != -1) {
					if (board[j][k] % 10 == N) {
						textColor(0, 14);
						a *= 0;
					}
				}

				if (board[j][k] == -1) cout << "   ";
				else if (board[j][k] >= 10) cout << " " << board[j][k] % 10 << " ";
				else cout << " " << board[j][k] << " ";

				if (a == 0) textColor(15, 0);
			}
			cout << "弛" << endl;
		}
	}
	cout << "戌式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式戎";

	vector<int> num = countNumber();

	cout << endl << endl << "Number Left" << endl;
	cout << "忙式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式忖" << endl;
	cout << "弛 0 弛 1 弛 2 弛 3 弛 4 弛 5 弛 6 弛 7 弛 8 弛" << endl;
	cout << "戍式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式扣" << endl;
	for (int i = 0; i < 9; i += 1) {
		num[i] = 9 - num[i];
		if (num[i] < 0) {
			num[i] *= -1;
			cout << "弛";
			textColor(15, 12);
			cout << " " << num[i] << " ";
			textColor(15, 0);
		}
		else if (num[i] == 0) {
			cout << "弛";
			textColor(15, 10);
			cout << " " << num[i] << " ";
			textColor(15, 0);
		}
		else cout << "弛 " << num[i] << " ";
	}
	cout << "弛" << endl << "戌式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式戎";
}

vector<int> countNumber() {
	vector<int> num(9, 0);
	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			if (board[i][j] != -1) num[board[i][j] % 10] += 1;
		}
	}

	return num;
}

int left(int x) {
	if (x == 0) x = 0;
	else x -= 1;

	return x;
}

int right(int x) {
	if (x == 8) x = 8;
	else x += 1;

	return x;
}

int up(int y) {
	if (y == 0) y = 0;
	else y -= 1;

	return y;
}

int down(int y) {
	if (y == 8) y = 8;
	else y += 1;

	return y;
}

void input0(int x, int y) {
	board[y][x] = 100;
}

void input1(int x, int y) {
	board[y][x] = 101;
}

void input2(int x, int y) {
	board[y][x] = 102;
}

void input3(int x, int y) {
	board[y][x] = 103;
}

void input4(int x, int y) {
	board[y][x] = 104;
}

void input5(int x, int y) {
	board[y][x] = 105;
}

void input6(int x, int y) {
	board[y][x] = 106;
}

void input7(int x, int y) {
	board[y][x] = 107;
}

void input8(int x, int y) {
	board[y][x] = 108;
}

void del(int x, int y) {
	board[y][x] = -1;
}

void checkBoard() {
	vector<int> li = { 0, 3, 6, 27, 30, 33, 54, 57, 60 };

	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			board[i][j] %= 1000;
		}
	}

	for (int i = 0; i < 9; i += 1) {
		vector<int> xsize(9, 0);
		vector<int> ysize(9, 0);
		vector<int> zsize(9, 0);

		int ys = li[i] / 9;
		int yf = ys + 3;
		int xs = li[i] % 9;
		int xf = xs + 3;

		for (int j = 0; j < 9; j += 1) {
			if (board[i][j] != -1) xsize[board[i][j] % 10] += 1;
			if (board[j][i] != -1) ysize[board[j][i] % 10] += 1;
		}

		for (int j = ys; j < yf; j += 1) {
			for (int k = xs; k < xf; k += 1) {
				if (board[j][k] != -1) zsize[board[j][k] % 10] += 1;
			}
		}

		for (int j = 0; j < 9; j += 1) {
			if (board[i][j] != -1 && xsize[board[i][j] % 10] >= 2) board[i][j] += 1000;
			if (board[j][i] != -1 && ysize[board[j][i] % 10] >= 2) board[j][i] += 1000;
		}

		for (int j = ys; j < yf; j += 1) {
			for (int k = xs; k < xf; k += 1) {
				if (board[j][k] != -1 && zsize[board[j][k] % 10] >= 2) board[j][k] += 1000;
			}
		}
	}

	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			if (board[i][j] >= 1000) board[i][j] = board[i][j] % 1000 + 1000;
		}
	}
}

int testBoard() {
	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			if (board[i][j] >= 1000 || board[i][j] == -1) return 0;
		}
	}
	return 1;
}

int main() {
	int key;
	int x = 0, y = 0;
	string X;

	srand((unsigned int)GetTickCount64());
	boardSet();
	int N = 0;

	while (1) {
		cout << "Select Difficulty(Easy, Normal, Hard, Insane): ";
		cin >> X;

		if (X == "Easy") {
			N = rand() % 12 + 12;
			break;
		}
		else if (X == "Normal") {
			N = rand() % 12 + 24;
			break;
		}
		else if (X == "Hard") {
			N = rand() % 12 + 36;
			break;
		}
		else if (X == "Insane") {
			N = rand() % 12 + 48;
			break;
		}
		else {
			cout << "Wrong Answer. ";
		}
	}

	randomCoverNumber(N);
	printBoard(0, 0);

	while (1) {
		key = _getch();
		switch (key) {
		case LEFT: x = left(x);
			break;

		case RIGHT: x = right(x);
			break;

		case UP: y = up(y);
			break;

		case DOWN: y = down(y);
			break;

		case NUM0:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 0) {
					input0(x, y);
					checkBoard();
				}
			}
			break;

		case NUM1:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 1) {
					input1(x, y);
					checkBoard();
				}
			}
			break;

		case NUM2:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 2) {
					input2(x, y);
					checkBoard();
				}
			}
			break;

		case NUM3:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 3) {
					input3(x, y);
					checkBoard();
				}
			}
			break;

		case NUM4:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 4) {
					input4(x, y);
					checkBoard();
				}
			}
			break;

		case NUM5:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 5) {
					input5(x, y);
					checkBoard();
				}
			}
			break;

		case NUM6:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 6) {
					input6(x, y);
					checkBoard();
				}
			}
			break;

		case NUM7:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 7) {
					input7(x, y);
					checkBoard();
				}
			}
			break;

		case NUM8:
			if (board[y][x] == -1 || (100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				if (board[y][x] % 10 != 8) {
					input8(x, y);
					checkBoard();
				}
			}
			break;

		case SPACE:
			if ((100 <= board[y][x] % 1000 && board[y][x] % 1000 <= 108)) {
				del(x, y);
				checkBoard();
			}
			break;
		}

		printBoard(x, y);

		if (testBoard()) {
			cout << endl << endl;
			cout << "Game Over" << endl << "You Win!" << endl << endl << endl;
			system("PAUSE");
			return 0;
		}
	}
}