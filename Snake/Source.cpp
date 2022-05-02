#include <iostream>
#include "Snake.h"
#include <ctime>
#include<Windows.h>
#include <conio.h>
using namespace std;

void Game::Draw_horizontal_borders() {
	for (int i = 0; i < width+1; i++)
	
		cout << "#";
	
	cout << endl;
}

bool Game::Draw_vertical_borders(int y_coordinate, int x_coordinate) {
	if (x_coordinate == 0 || x_coordinate==width-1)//����� ������������ ������ ����
	{
		cout << "#";
		return true;
	}
	return false;
}

bool Game::Draw_head_of_snake(int y_coordinate, int x_coordinate) {
	if (y_coordinate == yHead && x_coordinate == xHead)//����� ������ ����
	{
		cout << "0";
		return true;
	}
	return false;
}

bool Game::Draw_Fruite(int y_coordinate, int x_coordinate) {
	if (y_coordinate == fruitY && x_coordinate == fruitX)//����� ������
	{
		cout << "F";
		return true;
	}
	return false;
}

void Game::Draw_Snake_tail_or_space(int y_coordinate, int x_coordinate) {
	bool print = false;//���������� ��������� �������� ��������, ���� �� ���������� ������� ������ � �������� ������, ���� �� ����������
	for (int k = 0; k < nTail; k++)//���� �� ����� ������
	
		if (tailX[k] == x_coordinate && tailY[k] == y_coordinate)//���� ���������� ����� ����� ��������� � ������������ �������� ������ ������ �� ����� ����� ��� � ������ ������� ������
		{
			print = true;
			cout << "o";
		}
		if (!print)//���� �� ���������� ������� ������ ������, �� ������ ������
			cout << " ";
	
}

void Game::Draw() {
	system("cls");//������� �������
	Draw_horizontal_borders();//������ ������� �������
	for (int i = 0; i < heigth; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (Draw_vertical_borders(i, j));
			if (Draw_head_of_snake(i, j));
			else {
				if (Draw_Fruite(i, j));
				else {
					Draw_Snake_tail_or_space(i, j);
				}
			}
		}
		cout << endl;
	}
	Draw_horizontal_borders();//������ ������ �������
	cout << "Score: " << score << endl;//������ ���������� ����� �� ������ ������
}

void Game::Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		{
			dir = LEFT;
			break;
		}
		case'd':
		{
			dir = RIGHT;
			break;
		}
		case'w':
		{
			dir = UP;
			break;
		}
		case 's':
		{
			dir = DOWN;
			break;
		}
		case'x'://��� ������� � �� ������������� ������� �� ����
		{
			gameover = true;
			break;
		}
		}
	}
}

void Game::Tail_step()
{
	int prevX = tailX[0];//���������� ������� �� �
	int prevY = tailY[0];//���������� ������� �� �
	int prev2X, prev2Y;//��������� ������� ������
	tailX[0] = xHead;
	tailY[0] = yHead;
	for (int i = 1; i < nTail; i++)//������� �������� ������
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}
}

void Game::Change_of_head_position()
{
	switch (dir)//� ����������� �� �������� dir �������� ���������� ������ ������
	{
	case LEFT:
		xHead--;
		break;
	case RIGHT:
		xHead++;
		break;
	case UP:
		yHead--;
		break;
	case DOWN:
		yHead++;
		break;
	}
}

void Game::meating_with_border()//���������� ������, ���� ������ ������ �������� �� �������
{
	if (xHead >= width - 1)
		xHead = 0;
	else if (xHead < 0)
		xHead = width - 2;
	if (yHead >= heigth)
		yHead = 0;
	else if (yHead < 0)
		yHead = heigth - 1;
}

void Game::head_to_tail_check()
{
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == xHead && tailY[i] == yHead)//���� ������ ������ ������� �� �����
		{
			gameover = true;

		}
	}
}

bool Game::Check_Tail_and_Fruit_coincidence()
{
	bool f = true;
	for (int i = 0; i < nTail && f; i++)
	{
		f = false;
		if (tailX[i] == fruitX && tailY[i] == fruitY)
		{
			fruitX == rand() % (width - 1);
			fruitY = rand() % heigth;
			f = false;
		}
		else f = false;
	}
	return f;
}

void Game::Eating_Fruits()
{
	if (xHead==fruitX && yHead==fruitY)//�������� �������
	{
		score += 10;//�� �������� ������� ����������� 10 �����
		fruitX = rand() % (width - 1);
		fruitY = rand() % heigth;
		if (nTail > 0)
			while (Check_Tail_and_Fruit_coincidence());//�������� �� ���������� ���������
		nTail++;
	}
}

void Game::Logic()
{
	Tail_step();
	Change_of_head_position();
	meating_with_border();
	head_to_tail_check();
	Eating_Fruits();
}
