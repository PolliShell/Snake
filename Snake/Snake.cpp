#include <iostream>
#include "Snake.h"
#include <ctime>
#include<Windows.h>
#include <conio.h>

using namespace std;
int main()
{
    Game game1;
    while (!game1.gameover) {
        game1.draw();
        game1.input();
        game1.logic();
        Sleep(250);
    }
    setlocale(LC_ALL, "ru");
}
