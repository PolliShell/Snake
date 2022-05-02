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
        game1.Draw();
        game1.Input();
        game1.Logic();
        Sleep(300);
    }
    setlocale(LC_ALL, "ru");
}