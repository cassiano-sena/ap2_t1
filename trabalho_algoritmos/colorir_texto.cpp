#include <iostream>
#include <windows.h>

using namespace std;

#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15

void cor_texto (int fonte, int fundo=0) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (fonte | fundo<<4));
}


int main () {
    cor_texto(6,11);
    cout<<"Oi";
    cor_texto(0,14);
    cout<<"Mundo!";
    cor_texto(7,0);
    //system("pause");
}
/*
char menu2;
    while(inMenu){
        //menu = getch();
        if(menu==0){
            system("cls");
            cout<<"####################################"<<endl;
            cout<<"##############Sokoban###############"<<endl;
            cout<<"####################################"<<endl;
            cout<<"###########1-New Game###############"<<endl;
            cout<<"###########2-Continue###############"<<endl;
            cout<<"###########3-Info###################"<<endl;
            cout<<"###########Q-Quit###################"<<endl;
            cout<<"####################################"<<endl;
            cin>>menu;
        }else if(menu==1){
            //menu=1;
            system("cls");
            cout<<"####################################"<<endl;
            cout<<"##############Sokoban###############"<<endl;
            cout<<"####################################"<<endl;
            cout<<"###########1-Select Map#############"<<endl;
            cout<<"###########2-Random#################"<<endl;
            cout<<"###########3-Back###################"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            cin>>menu2;
        }else if(menu==2){
            //menu=2;
            system("cls");
            cout<<menu;
            cout<<"The 'continue' function is not yet ready"<<endl;
            system("pause");
            menu=0;
        }else if(menu==3){
            system("cls");
            cout<<"##################################################################################################"<<endl;
            cout<<"#Sokoban is a puzzle game about pushing crates around.                                           #"<<endl;
            cout<<"#                                                                                                #"<<endl;
            cout<<"#Invented in Japan, the word means 'warehouse keeper'.                                           #"<<endl;
            cout<<"#                                                                                                #"<<endl;
            cout<<"#The objective is to move the crates to the objectives using the minimum amount of moves possible#"<<endl;
            cout<<"##################################################################################################"<<endl;
            cout<<"#This game was made by Cassiano de Sena Crispim as a project for Programming and Algorhytms II.  #"<<endl;
            cout<<"#UNIVALI, March of 2023, Thiago Felski Pereira.                                                  #"<<endl;
            cout<<"##################################################################################################"<<endl;
            system("pause");
            menu=0;
        }else if(menu==4){
            system("cls");
            cout<<"####################################"<<endl;
            cout<<"##############Sokoban###############"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            cout<<"##########Thanks For Playing########"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            system("pause");
            menu=0;
            playing=false;
        }else if(menu2==1){
            levelSelection(level,x,y,m,mn);
            system("cls");
            inMenu=false;
            playing=true;
            //game(playing,level,victory,x,xn,y,yn,m,mn,menu,savedX,savedY,savedGame,inMenu);
        }else if(menu2==2){
            srand(time(NULL));
            level=1+(rand()%3);
            randomLevelSelection(level,x,y,m);
            system("cls");
            inMenu=false;
            playing=true;
            //game(playing,level,victory,x,xn,y,yn,m,mn,menu,savedX,savedY,savedGame,inMenu);
        }else if(menu2==3){
            menu=0;
        }
    }
    */
