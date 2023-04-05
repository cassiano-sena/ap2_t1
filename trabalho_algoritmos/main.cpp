/**
    Estrutura inicial para um jogo de labirinto
    versão: 0.1 (Felski)
*/
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"function.cpp"

using namespace std;

int main()
{
    int level = 0;
    char menu = 0;
    bool playing = false;
    bool inMenu = false;
    bool victory = false;

    /// full matrix
    int m[7][7]={ 1,1,1,1,1,1,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,1,1,1,1,1,1 };

    /// walkable matrix
    int mn[7][7]={ 1,1,1,1,1,1,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,0,0,0,0,0,1,
                1,1,1,1,1,1,1 };

    int savedGame[7][7]={ 1,1,1,1,1,1,1,
                        1,0,0,0,0,0,1,
                        1,0,0,0,0,0,1,
                        1,0,0,0,0,0,1,
                        1,0,0,0,0,0,1,
                        1,0,0,0,0,0,1,
                        1,1,1,1,1,1,1 };

    int x=4, y=4, xn=0, yn=0, savedX=0, savedY=0;
    //char tecla;
    start(playing,level,victory,x,xn,y,yn,m,mn,inMenu,menu,savedGame,savedX,savedY);

} //fim main
