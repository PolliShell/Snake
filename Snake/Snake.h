#pragma once
#include <iostream>
#include <ctime>
using namespace std;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
protected:
	int tailX[100], tailY[100];//В массивах храняться координаты хвоста змейки
	int nTail;//длина хвоста
	int xHead, yHead;

	int width;//ширина поля
	int heigth;//высота поля

public:
	Snake() {//конструктор, задающий начальные значения змейки
		width = 20;
		heigth = 15;
		nTail = 0;
	}
};

class Game : public Snake //класс игра
{
public:
	eDirection dir;
	bool gameover;//отвечает за конец игры
	int score;
	int fruitX, fruitY;

	Game() :Snake() {
		srand(time(NULL));
		gameover = false;
		dir = STOP;

		xHead = (width / 2) - 1;
		yHead = (heigth / 2) - 1;

		fruitX = rand() % (width - 1);
		fruitY = rand() % heigth;
		score = 0;
	}

	void draw();//рисуем поле
	void input();//получаем входные данные
	void logic();//реализуем логику игры
	void draw_horizontal_borders();//рисуем горизонтальные стенки
	bool draw_vertical_borders(int, int);//рисуем вертикальные стенки
	bool draw_head_of_snake(int, int);//рисуем голову змейки
	bool draw_fruite(int, int);//рисуем фрукт
	void draw_snake_tail_or_space(int, int);
	void tail_step();//метод отвечающий за движение хвоста змейки
	void change_of_head_position();//
	void eating_fruits();//процесс поедания фруктов
	void head_to_tail_check();//проверка чтобы голова змейки не встретилась с хвостом
	void meating_with_border();//реализация взаимодействия змейки со стенками поля
	bool check_tail_and_fruit_coincidence();//
};



