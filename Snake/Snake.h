#pragma once
#include <iostream>
#include <ctime>
using namespace std;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
class Snake {
protected:
    int width;//ширина поля
    int heigth;//высота поля
    int tailX[100], tailY[100];//В массивах храняться координаты хвоста змейки
    int nTail;//длина хвоста
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
    int xHead, yHead, fruitX, fruitY, score;
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

    void Draw();//рисуем поле
    void Input();//получаем входные данные
    void Logic();//реализуем логику игры
    void Draw_horizontal_borders();//рисуем горизонтальные стенки
    bool Draw_vertical_borders(int,int);//рисуем вертикальные стенки
    bool Draw_head_of_snake(int, int);//рисуем голову змейки
    bool Draw_Fruite(int, int);//рисуем фрукт
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();//метод отвечающий за движение хвоста змейки
    void Change_of_head_position();//
    void Eating_Fruits();//процесс поедания фруктов
    void head_to_tail_check();//проверка чтобы голова змейки не встретилась с хвостом
    void meating_with_border();//реализация взаимодействия змейки со стенками поля
    bool Check_Tail_and_Fruit_coincidence();//
};

