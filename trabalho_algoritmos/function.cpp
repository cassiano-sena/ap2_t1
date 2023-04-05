#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>

using namespace std;

template <typename T>
 void trade(T v1, T v2){
    T temp;
    temp=v1;
    v1=v2;
    v2=temp;
 }

template <typename T>
void tradeFirst(T v1, T v2){
    T temp;
    v2=v1;
 }

template <typename T>
void tradeSecond(T v1, T v2){
    T temp;
    v1=v2;
 }

/// checks if there is a wall in given position
bool checkWall(int x, int y, int m[7][7]){
    if(m[x][y]==1){
        return true;
    }else
        return false;
}

/// checks if there is an objective in given position
bool checkObjective(int x, int y, int m[7][7]){
    if(m[x][y]==3){
        return true;
    }else
        return false;
}

/// checks if there is a crate in given position
bool checkCrate(int x, int y, int m[7][7]){
    if(m[x][y]==4){
        return true;
    }else
        return false;
}

/// copies the main matrix and
int loadMatrix(int m[7][7], int mn[7][7], bool toZero){
    for(int i=1;i<8;i++){
        for(int j=1;j<8;j++){
            mn[i][j]=m[i][j];
            if(toZero){
                if(m[i][j]==4){
                    mn[i][j]==0;
                }
            }
        }
    }
}

int restartMatrix(int m[7][7], int mn[7][7], int &x, int &y, int &xn, int &yn){
    x=xn;
    y=yn;
    for(int i=1;i<8;i++){
        for(int j=1;j<8;j++){
            m[i][j]=mn[i][j];
        }
    }
}

int saveMatrix(int x, int y, int m[7][7], int savedX, int savedY, int savedGame[7][7]){
    savedX=x;
    savedY=y;
    for(int i=1;i<8;i++){
        for(int j=1;j<8;j++){m[i][j]=0;
            savedGame[i][j]=m[i][j];
        }
    }
}

/**
APERTEI PARA CIMA
- personagem se mova para cima
-- se a posição de cima estiver livre ou objetivo
-- se a posição de cima não estiver livre, mas tiver uma caixa, cuja posição de cima é livre
-- se a posição de cima não estiver livre, mas tiver uma caixa, cuja posição de cima é objetivo

    if (m[x-1][y]==0 || m[x-1][y]==3){ //personagem se move para posição livre
        x=x-1;
    } else if (m[x-1][y]==4 && m[x-2][y]==0){ //personagem empurra caixa para posição livre
        m[x-1][y]=0;
        m[x-2][y]=4;
        x=x-1;

    } else if (m[x-1][y]==4 && m[x-2][y]==3){ //personagem empurra caixa para posição final
        m[x-1][y]=0;
        m[x-2][y]=5;
        x=x-1;
    } else if () {//personagem empurra uma caixa de uma posição final para uma posição livre
        //seu código 1
    } else if () {//personagem empurra uma caixa de uma posição final para uma posição final
        //seu codigo 2
    }
*/

int levelSelection(int &level,int &x, int &y, int m[7][7], int mn[7][7],int &xn, int &yn, bool inMenu, bool playing, int &savedX, int &savedY, int savedGame[7][7]){
    cout<<"Select The level"<<endl;
    cout<<"1- Abyss"<<endl;
    cout<<"2- Hell"<<endl;
    cout<<"3- The Profane Horror Beyond Human Comprehension"<<endl;
    cin>>level;
        if(level==1){
            //level=1;
            x=6;
            y=4;
            xn=6;
            yn=4;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==4 && j==4)){
                        m[i][j]=1; // x boundary, y boundary, center wall
                        mn[i][j]=1;
                    }else if(i==6 && j>1 && j<7){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if(i==5 && j>1 && j<7){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else {
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }
                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            loadMatrix(m,mn,true);
            //return level;
            return x;
            return y;
            //return m[7][7];
    }
       else if(level==2){
            //level=2;
            x=4;
            y=6;
            xn=4;
            yn=6;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==5) || (i==4 && j==3) || (i==5 && j==6) || (i==6 && j>4 && j<7)){
                        m[i][j]=1; // x boundary, y boundary, scattered walls
                        mn[i][j]=1;
                    }else if(i==2 && j>1 && j<7 && j!=3){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if((i==3 && j==3) || (i==4 && j>1 && j<6 && j!=3)){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else {
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }
                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            loadMatrix(m,mn,true);
            //return level;
            return x;
            return y;
            //return m[7][7];
    }
        else if(level==3){
            //level=3;
            x=4;
            y=2;
            xn=4;
            yn=2;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==3) || (i==4 && j==5) || (i==6 && j==4)){
                        m[i][j]=1; // x boundary, y boundary, three scattered walls
                        mn[i][j]=1;
                    }else if((i==2 && j==2) || (i==2 && j==6) || (i==6 && j==2) || (i==6 && j==6)){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if((i==3 && j==5)|| (i==4 && j>2 && j<5) || (i==5 && j==5)){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else{
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }

                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            loadMatrix(m,mn,true);
            //return level;
            return x;
            return y;
            //return m[7][7];
    }
}

int directLevelSelection(int &level,int &x,int &y, int m[7][7],int mn[7][7],int &xn, int &yn, bool inMenu, bool playing, int &savedX, int &savedY, int savedGame[7][7]){
    if(level==1){
        x=6;
        y=4;
        xn=6;
        yn=4;
        for(int i=1; i<8;i++){
            for(int j=1; j<8; j++){
                if(i==1 || i==7 || j==1 || j==7 || (i==4 && j==4)){
                    m[i][j]=1; // x boundary, y boundary, center wall
                    mn[i][j]=1;
                }else if(i==5 && j>1 && j<7){
                    m[i][j]=3; // objectives
                    mn[i][j]=3;
                }else if(i==6 && j>1 && j<7){
                    m[i][j]=4; // crates
                    mn[i][j]=4;
                }else {
                    m[i][j]=0; // path
                    mn[i][j]=0;
                }
            }
        }
        saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
        cout<<"Selected Level: "<<level<<endl;
        return x;
        return y;
        //return m[7][7];
    }
    else if(level==2){
        x=4;
        y=6;
        xn=4;
        yn=6;
        for(int i=1; i<8;i++){
            for(int j=1; j<8; j++){
                if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==5) || (i==4 && j==3) || (i==5 && j==6) || (i==6 && j>4 && j<7)){
                    m[i][j]=1; // x boundary, y boundary, scattered walls
                    mn[i][j]=1;
                }else if(i==2 && j>1 && j!=3 && j<7){
                    m[i][j]=3; // objectives
                    mn[i][j]=3;
                }else if((i==3 && j==3) || (i==4 && j>1 && j!=3 && j<6)){
                    m[i][j]=4; // crates
                    mn[i][j]=4;
                }else {
                    m[i][j]=0; // path
                    mn[i][j]=0;
                }
            }
        }
        saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
        cout<<"Selected Level: "<<level<<endl;
        return x;
        return y;
        //return m[7][7];
    }
    else if(level==3){
        x=4;
        y=2;
        xn=4;
        yn=2;
        for(int i=1; i<8;i++){
            for(int j=1; j<8; j++){
                if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==3) || (i==4 && j==5) || (i==6 && j==4)){
                    m[i][j]=1; // x boundary, y boundary, three scattered walls
                    mn[i][j]=1;
                }else if((i==2 && j==2) || (i==2 && j==6) || (i==6 && j==2) || (i==6 && j==6)){
                    m[i][j]=3; // objectives
                    mn[i][j]=3;
                }else if((i==3 && j==5)|| (i==4 && j>2 && j<5) || (i==5 && j==5)){
                    m[i][j]=4; // crates
                    mn[i][j]=4;
                }else {
                    m[i][j]=0; // path
                    mn[i][j]=0;
                }
            }
        }
        saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
        cout<<"Selected Level: "<<level<<endl;
        return x;
        return y;
        //return m[7][7];
    }
}

int randomLevelSelection(int &level,int &x,int &y, int m[7][7],int mn[7][7],int &xn, int &yn, bool inMenu, bool playing, int &savedX, int &savedY, int savedGame[7][7]){
    srand(time(NULL));
    while(level<1 || level>3){
        level=rand()%3+1;
        if(level==1){
            x=6;
            y=4;
            xn=6;
            yn=6;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==4 && j==4)){
                        m[i][j]=1; // x boundary, y boundary, center wall
                    }else if(i==5 && j>1 && j<7){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if(i==6 && j>1 && j<7){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else {
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }
                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            return x;
            return y;
            //return m[7][7];
        }
        else if(level==2){
            x=4;
            y=6;
            xn=4;
            yn=6;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==5) || (i==4 && j==3) || (i==5 && j==6) || (i==6 && j>4 && j<7)){
                        m[i][j]=1; // x boundary, y boundary, scattered walls
                        mn[i][j]=1;
                    }else if(i==2 && j>1 && j!=3 && j<7){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if((i==3 && j==3) || (i==4 && j>1 && j!=3 && j<6)){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else {
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }
                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            return x;
            return y;
            //return m[7][7];
        }
        else if(level==3){
            x=4;
            y=2;
            xn=4;
            yn=2;
            for(int i=1; i<8;i++){
                for(int j=1; j<8; j++){
                    if(i==1 || i==7 || j==1 || j==7 || (i==3 && j==3) || (i==4 && j==5) || (i==6 && j==4)){
                        m[i][j]=1; // x boundary, y boundary, three scattered walls
                        mn[i][j]=1;
                    }else if((i==2 && j==2) || (i==2 && j==6) || (i==6 && j==2) || (i==6 && j==6)){
                        m[i][j]=3; // objectives
                        mn[i][j]=3;
                    }else if((i==3 && j==5)|| (i==4 && j>2 && j<5) || (i==5 && j==5)){
                        m[i][j]=4; // crates
                        mn[i][j]=4;
                    }else {
                        m[i][j]=0; // path
                        mn[i][j]=0;
                    }
                }
            }
            saveMatrix(xn,yn,mn,savedX,savedY,savedGame);
            cout<<"Selected Level: "<<level<<endl;
            return x;
            return y;
            //return m[7][7];
        }
    }
}

void toggleCursor(){
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
}

void repositionCursor(){
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short int CX=0, CY=0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.
    ///Posiciona a escrita no início do console
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/// prints the game
void printGame(bool playing, int level, bool victory, int &x, int &xn, int &y, int &yn, int m[7][7], int mn[7][7]){
    //system("cls");
    toggleCursor();
    repositionCursor();
    cout<<"M- Menu";
    cout<<", ";
    cout<<"R- Restart"<<endl;
    //cout<<", ";
    //cout<<"Q- Quit"<<endl;
    cout<<endl;

    for(int i=1;i<8;i++){
            for(int j=1;j<8;j++){
                //m[x][y]=2;
                if(i==x && j==y){
                    cout<<char(2); //character
                } else {
                    switch (m[i][j]){
                        case 0: cout<<" "; break; //path
                        case 1: cout<<char(219); break; //wall
                        case 3: cout<<char(184); break; //crate
                        case 4: cout<<char(178); break; //final-positioned crate
                        case 5: cout<<char(176); break; //objective
                        default: cout<<"-"; //error
                    }
                }
            }
            cout<<"\n";
    }
}

/// check if final-boxes are placed in final-positions
int checkWinCondition(bool &playing,bool &victory, int m[7][7], int level){
    if(level==1){
        if(m[6][2]==5 && m[6][3]==5 && m[6][4]==5 && m[6][5]==5 && m[6][6]==5){
            victory=true;
        }
    }else if(level==2){
        if(m[2][2]==5 && m[2][4]==5 && m[2][5]==5 && m[2][6]==5){
            victory=true;
        }
    }else if(level==3){
        if(m[2][2]==5 && m[2][6]==5 && m[6][2]==5 && m[6][6]==5){
            victory=true;
        }
    }
}

int continueGame(int savedGame[7][7], int savedX, int savedY, int m[7][7], int x, int y, int mn[7][7], int level){
    tradeSecond<int>(x,savedX);
    tradeSecond<int>(y,savedY);
    loadMatrix(m,savedGame,false);
}


/// menus
void mainMenu(bool &playing, int level, bool victory, int x, int xn, int y, int yn, int m[7][7], int mn[7][7], bool inMenu, char menu, int savedX, int savedY, int savedGame[7][7]){
    char menu2;
    while(inMenu){
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

        /// New Game
        if(menu=='1'){
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
                //break;
                if(menu2=='1'){
                    levelSelection(level,x,y,m,mn,xn,yn,inMenu,playing,savedX,savedY,savedGame);
                    system("cls");
                    inMenu=false;
                    playing=true;
                    //break;
                }else if(menu2=='2'){
                    randomLevelSelection(level,x,y,m,mn,xn,yn,inMenu,playing,savedX,savedY,savedGame);
                    system("cls");
                    inMenu=false;
                    playing=true;
                }else if(menu2=='3'){
                }else{
                    cin>>menu2;
                }
        }

        /// Continue
        else if(menu=='2'){
                if(savedX==0 && savedY==0){
                //system("cls");
                cout<<"There isn't an ongoing game!"<<endl;
                system("pause");
                }else{
                //cout<<"The 'continue' function is not ready!";
                continueGame(savedGame,savedX,savedY,m,x,y,mn,level);
                inMenu=false;
                playing=true;
                //break;

                }
        }

        /// Info
        else if(menu=='3'){
            if(menu2!='1'){
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
                //menu=0;
                //break;
            }if(menu2=='1'){
            //menu2=0;
            //menu='0';
            //break;
            }
        }

        /// Quit
        else if(menu=='q' || menu=='Q'){
            system("cls");
            cout<<"####################################"<<endl;
            cout<<"##############Sokoban###############"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            cout<<"##########Thanks For Playing########"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            cout<<"####################################"<<endl;
            //menu='0';
            playing=false;
            inMenu=false;
            //break;
        }
        else{
            cin>>menu;
        }
    }
}


/// controls
int controls(int &x, int &y, int m[7][7], int mn[7][7], int &xn, int &yn, char &menu, bool &playing, int &level, bool &inMenu, int savedX, int savedY, int savedGame[7][7],bool victory){
    if(playing==true){
    char key;
        if ( _kbhit() ){
                key = getch();
                switch(key)
                {
                    case 72: case 'w': ///up
                        if(m[x-1][y]==0 || m[x-1][y]==3){///walkable
                            x--;
                        }else if(m[x-1][y]==4 && m[x-2][y]==0){///crate is freely pushable
                            m[x-1][y]=0;
                            m[x-2][y]=4;
                            x--;
                        }else if(m[x-1][y]==4 && m[x-2][y]==3){///crate is pushable to final position
                            m[x-1][y]=0;
                            m[x-2][y]=5;
                            x--;
                        }else if(m[x-1][y]==5 && m[x-2][y]==3){///crate is pushable to final position
                            m[x-1][y]=3;
                            m[x-2][y]=4;
                            x--;
                        }else if(m[x-1][y]==5 && m[x-2][y]==5){///crate is pushable from final position to final position
                            //m[x-1][y]=5;
                            //m[x-2][y]=5;
                            //x--;
                        }else if(checkWall(x-1,y,m)==true){
                        }
                    break;

                    case 80: case 's': ///down
                        if(m[x+1][y]==0 || m[x+1][y]==3){///walkable
                            x++;
                        }else if(checkWall(x+1,y,m)==true){
                        }else if(m[x+1][y]==4 && m[x+2][y]==0){///crate is freely pushable
                            m[x+1][y]=0;
                            m[x+2][y]=4;
                            x++;
                        }else if(m[x+1][y]==4 && m[x+2][y]==3){///crate is pushable to final position
                            m[x+1][y]=0;
                            m[x+2][y]=5;
                            x++;
                        }else if(m[x+1][y]==5 && m[x+2][y]==3){///crate is pushable to final position
                            m[x+1][y]=3;
                            m[x+2][y]=4;
                            x++;
                        }else if(m[x+1][y]==5 && m[x+2][y]==5){///crate is pushable from final position to final position
                            //m[x+1][y]=5;
                            //m[x+2][y]=5;
                            //x++;
                        }
                    break;

                    case 75:case 'a': ///left
                        if(m[x][y-1]==0 || m[x][y-1]==3){///walkable
                            y--;
                        }else if(checkWall(x,y-1,m)==true){
                        }else if(m[x][y-1]==4 && m[x][y-2]==0){///crate is freely pushable
                            m[x][y-1]=0;
                            m[x][y-2]=4;
                            y--;
                        }else if(m[x][y-1]==4 && m[x][y-2]==3){///crate is pushable to final position
                            m[x][y-1]=0;
                            m[x][y-2]=5;
                            y--;
                        }else if(m[x][y-1]==5 && m[x][y-2]==3){///crate is pushable to final position
                            m[x][y-1]=3;
                            m[x][y-2]=4;
                            y--;
                        }else if(m[x][y-1]==5 && m[x][y-2]==5){///crate is pushable from final position to final position
                            //m[x][y-1]=5;
                            //m[x][y-2]=5;
                            //y--;
                        }
                    break;

                    case 77: case 'd': ///right
                        if(m[x][y+1]==0 || m[x][y+1]==3){///walkable
                            y++;
                        }else if(checkWall(x,y+1,m)==true){
                        }else if(m[x][y+1]==4 && m[x][y+2]==0){///crate is freely pushable
                            m[x][y+1]=0;
                            m[x][y+2]=4;
                            y++;
                        }else if(m[x][y+1]==4 && m[x][y+2]==3){///crate is pushable to final position
                            m[x][y+1]=0;
                            m[x][y+2]=5;
                            y++;
                        }else if(m[x][y+1]==5 && m[x][y+2]==3){///crate is pushable from final position to objective
                            m[x][y+1]=3;
                            m[x][y+2]=5;
                            y++;
                        }else if(m[x][y+1]==5 && m[x][y+2]==5){///crate is pushable from final position to final position
                            //m[x][y+1]=5;
                            //m[x][y+2]=5;
                            //y++;
                        }
                    break;

                    case 'm': /// menu
                        saveMatrix(x,y,m,savedX,savedY,savedGame);
                        playing=false;
                        inMenu=true;
                        mainMenu(playing,level,victory,x,xn,y,yn,m,mn,inMenu,menu,savedX,savedY,savedGame);
                    break;

                    case 'r': /// restart
                        system("cls");
                        //x=savedX;
                        //y=savedY;
                        restartMatrix(m,mn,x,y,xn,yn);
                        //game(playing,level,victory,x,xn,y,yn,m,mn,menu,savedX,savedY,savedGame,inMenu);
                        //directLevelSelection(level,x,y,m,xn,yn,inMenu,playing,savedX,savedY,savedGame);
                    break;

                }
            }
         }else{
            return 0;
         }
}


/// function to play the game
int game(bool playing, int level, bool victory, int &x, int &xn, int &y, int &yn, int m[7][7], int mn[7][7], char menu, int savedX, int savedY, int savedGame[7][7], bool inMenu){
    while(playing=true){
        checkWinCondition(playing,victory,m,level);
        if(victory==false){
            //commands(playing,menu,level,x,y,m);
            controls(x,y,m,mn,xn,yn,menu,playing,level,inMenu,savedX,savedY,savedGame,victory);
            printGame(playing,level,victory,x,xn,y,yn,m,mn);
        }else{
            cout<<"Congratulations!! You've Won!!"<<endl;
            playing=false;
            inMenu=true;
            system("pause");
        }
    }
}

/// enables the program to run
int start(bool &playing, int level, bool victory, int &x, int &xn, int &y, int &yn, int m[7][7], int mn[7][7], int inMenu, char menu, int savedGame[7][7], int savedX, int savedY){
    //char key;
    inMenu=true;
    while(true){
        if(inMenu==true){
            mainMenu(playing,level,victory,x,xn,y,yn,m,mn,inMenu,menu,savedX,savedY,savedGame);
        }else{
            playing=true;
        }
        if(playing==true){
            system("cls");
            game(playing,level,victory,x,xn,y,yn,m,mn,menu,savedX,savedY,savedGame,inMenu);
        }else{
            return 0;
        }
    }
}

