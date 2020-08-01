#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<windows.h>
using namespace std;

//Functions of Musical Notes
void sa(int t) {
	Beep(2400, t);
	return;
}

void re(int t) {
	Beep(2700, t);
	return;
}

void ga(int t) {
	Beep(3000, t);
	return;
}

void ma(int t) {
	Beep(3200, t);
	return;
}

void pa(int t) {
	Beep(3600, t);
	return;
}

void dha(int t) {
	Beep(4000, t);
	return;
}

void ni(int t) {
	Beep(4500, t);
	return;
}

void Sa(int t) {
	Beep(4800, t);
	return;
}
//End of Musical Notes

void printmatrix(int* ptr) {
	printf("                                MATRIX SITUATION\n");
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0)printf("                                     ");
		if (ptr[i]) {
			if (ptr[i] == 1)printf("X");
			if (ptr[i] == 10)printf("O");
		}
		else {
			if (i < 6)printf("_");
			else
				printf(" ");
		}
		if (i % 3 < 2)printf("|");
		if (i % 3 == 2)printf("\n");
	}
	return;
}

int checkmatrix(int* p) {
	if (p[0] + p[1] + p[2] == 3 || p[3] + p[4] + p[5] == 3 || p[6] + p[7] + p[8] == 3)return 1;
	else if (p[0] + p[1] + p[2] == 30 || p[3] + p[4] + p[5] == 30 || p[6] + p[7] + p[8] == 30)return 10;
	else if (p[0] + p[3] + p[6] == 3 || p[1] + p[4] + p[7] == 3 || p[2] + p[5] + p[8] == 3)return 1;
	else if (p[0] + p[3] + p[6] == 30 || p[1] + p[4] + p[7] == 30 || p[2] + p[5] + p[8] == 30)return 10;
	else if (p[0] + p[4] + p[8] == 3 || p[2] + p[4] + p[6] == 3)return 1;
	else if (p[0] + p[4] + p[8] == 30 || p[2] + p[4] + p[6] == 30)return 10;
	else return 0;
}

int checkinput(int i) {
	char str[100];
	if (i % 2 == 0) cout << "Player X , please enter your location number : " << endl;
	else cout << "Player O , please enter your location number : " << endl;
	gets_s(str,100);
	if (str[0] == '\0') {
		printf("PLEASE ENTER SOMETHING...\n");
		Beep(1000, 1000);
		return 0;
	}
	int len = strlen(str), n = (int)str[0] - 48;
	if (len > 1 || n <= 0 || n > 9) {
		cout << "                               !!!INVALID INPUT!!!" << endl << "Only single digit positive numbers are allowed." << endl;
		cout << "'0' , alphabets & special characters are not allowed. Please try AGAIN !" << endl;
		Beep(1000, 1000);
		return 0;
	}
	else return n;
}

int main() 
{
	//Introduction
	cout << "              Welcome to YVR TECHNOSOFT'S : The Game of Tic Tac Toe" << endl;
	cout << "              *****************************************************" << endl;
	//Prelude
	sa(200);
	ga(200);
	pa(200);
	sa(200);
	ga(200);
	pa(200);
	sa(200); 
	pa(200);
	ga(200);
	sa(200);
	//End of Prelude
	system("pause");
	start:
	Beep(500, 200);
	cout << "Rules and Regulations :" << endl;
	cout << "1.The game requires two players X & O." << endl;
	cout << "2.The game consists of a matrix with sections numbered as 1,2,3,4,5... like :" << endl;
	cout << "  1|2|3    _|_|_" << endl << "  4|5|6 OR _|_|_" <<endl << "  7|8|9     | | " << endl;
	cout << "3.Alternatively the game will ask for position of X or O from respective player as input." << endl;
	cout << "4.Only single digit positive numbers are allowed. '0' , alphabets & special characters are not allowed." << endl;
	cout << "5.You(the players) have to input the location number where you want your X or O." << endl;
	cout << "6.After every move the situation of the matrix will be displayed." << endl;
	cout << "7.As soon as any one player manages to have 3 Xs or 3 Os in line (Horizontal/Vertical/Diagonal)..." << endl;
	cout << "8.He/She WINS THE GAME and the result is displayed automatically." << endl;
	cout << "So warm up your mental muscles and press any key to begin the game..." << endl;
	//End of Instructions
	system("pause");
	Beep(500, 200);
	//The Game
	int* ptr = (int*)malloc(9 * sizeof(int));
	for (int i = 0; i < 9; i++)ptr[i] = 0;
	printmatrix(ptr);
	//Input
	for (int i = 0; i < 9; i++) {
		int tmp = checkinput(i);
		if (tmp) {
			if (ptr[tmp - 1] != 0) {
				cout << "                       !!!OOPS,LOCATION ALREADY OCCUPIED!!!" << endl << "Please try AGAIN !" << endl;
				Beep(1000, 1000);
				i--;
				continue;
			}
			if (i % 2 == 0) ptr[tmp - 1] = 1;
			else ptr[tmp - 1] = 10;
		}
		else {
			i--;
			continue;
		}
		printmatrix(ptr);
		Beep(500, 200);
		//Win check
		if (i > 3) {
			int tmp = checkmatrix(ptr);
			if (tmp) {
				if (tmp == 1) {
					cout << endl << endl;
					cout << "                            *******GAME OVER*******" << endl;
					cout << "                            ### X is the WINNER ###" << endl;
					cout << "                            ***********************" << endl;
					cout << endl << endl;
					Beep(2000, 100); Beep(2200, 100); Beep(2400, 100); Beep(2600, 100); Beep(2800, 100); Beep(3000, 100);
					break;
				}
				if (tmp == 10) {
					cout << endl << endl;
					cout << "                            *******GAME OVER*******" << endl;
					cout << "                            ### O is the WINNER ###" << endl;
					cout << "                            ***********************" << endl;
					cout << endl << endl;
					Beep(2000, 100); Beep(2200, 100); Beep(2400, 100); Beep(2600, 100); Beep(2800, 100); Beep(3000, 100);
					break;
				}
			}
			else {
				if (i == 8) {
					cout << endl << endl;
					cout << "                           ********GAME  OVER********" << endl;
					cout << "                           ### THE GAME IS A DRAW ###" << endl;
					cout << "                           **************************" << endl;
					cout << endl << endl;
					//SOS
					Beep(2000, 200); Beep(2000, 200); Beep(2000, 200);
					Beep(2000, 500); Beep(2000, 500); Beep(2000, 500);
					Beep(2000, 200); Beep(2000, 200); Beep(2000, 200);
					break;
				}
			}
		}
		
	}
    exit:
	cout << "Type 'r' (small) and press 'enter' key to RESTART the game." << endl;
	cout << "Press ONLY 'enter' key to EXIT the game." << endl;
	char c[100];
	gets_s(c, 100);
	int t = strlen(c);
	if (t == 0)return 0;
	if (t > 1) {
		cout << "!!!INVALID COMMAND!!!" << endl;
		Beep(1000, 1000);
		goto exit;
	}
	if(t == 1) {
		if (c[0] == 'r')goto start;
		else {
			cout << "!!!INVALID COMMAND!!!" << endl;
			Beep(1000, 1000);
			goto exit;
		}
	}
	//End of Game
}