#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include "initialBoard.h"

int main()
{
    welcome();
    sequence();
    printf("\n");
    return 0;

}




void sequence()
{
    while(!stop)
    {
        getPathFlag=0;
        stalemateFlag=0;
        flag=0;
        promotionFlag=1;
        changeTurn=1;
        stalemateCheck();
        if (stalemateFlag==1)
        {
            playerTurn();
            checkInput();
            inSquare();
            checkMyKing();
            if ((flag==1)&&(checkFlag==1))
            {
                undo[u].eaten=board[y1][b1];
                undo[u].piece=board[x1][a1];
                moving();
                undo[u].x=x1;
                undo[u].a=a1;
                undo[u].y=y1;
                undo[u].b=b1;
                undo[u].turn=turn;
                u++;
                nu=u;
                if (piece=='k')
                {
                    kx2=y1;
                    ka2=b1;
                }
                else if (piece=='K')
                {
                    kx1=y1;
                    ka1=b1;
                }
            }
            else if ((flag==2)&&(checkFlag==1))
            {
                undo[u].eaten=board[y1][b1];
                eating();
                undo[u].piece=piece;
                undo[u].x=x1;
                undo[u].a=a1;
                undo[u].y=y1;
                undo[u].b=b1;
                undo[u].turn=turn;
                u++;
                nu=u;
            }
            printBoard();
            if ((flag==0)||(checkFlag==0))
            {
                printf("Invalid Move!\n");
                changeTurn=0;
            }
            m=0;
            n=0;
            int l, k;
            for (l=0;l<9;l++)
            {
                for (k=0;k<9;k++)
                {
                    enemyPath[l][k]=0;
                }
            }
            checkAfterMove();
            if (changeTurn==1)
            {
                if(turn==0)
                {
                    turn=1;
                }
                else if(turn==1)
                {
                    turn=0;
                }
            }
        }
        else
        {
            printf("Stalemate!");
            stop=1;
        }
    }
}

void welcome()
{
    initialBoard();
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,11);
    printf("\n\n\n\n\n\n");
    printf("                     #####  #     # #######  #####   #####  \n");
    printf("                    #     # #     # #       #     # #     # \n");
    printf("                    #       #     # #       #       #       \n");
    printf("                    #       ####### #####    #####   #####  \n");
    printf("                    #       #     # #             #       # \n");
    printf("                    #     # #     # #       #     # #     # \n");
    printf("                     #####  #     # #######  #####   #####  \n");
    HANDLE hConsole1;
    hConsole1=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,15);
    printf("\n\n                                  WELCOME");
    printf("\n                          Press Enter to continue");
    while (getchar()!='\n')
    {
        system("cls");
        HANDLE hConsole;
        hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,11);
        printf("\n\n\n\n\n\n");
        printf("                     #####  #     # #######  #####   #####  \n");
        printf("                    #     # #     # #       #     # #     # \n");
        printf("                    #       #     # #       #       #       \n");
        printf("                    #       ####### #####    #####   #####  \n");
        printf("                    #       #     # #             #       # \n");
        printf("                    #     # #     # #       #     # #     # \n");
        printf("                     #####  #     # #######  #####   #####  \n");
        HANDLE hConsole1;
        hConsole1=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,15);
        printf("\n\n                                  WELCOME");
        printf("\n                           Press Enter to continue");
        getchar();
    }
    system("cls");
    // menu
    HANDLE hConsole2;
    hConsole2=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,9);
    printf("\n\n\n\n");
    printf("                                         _          \n");
    printf("                            __  _       (_| _ __  _ \n");
    printf("                            | |(/_\\^/   __|(_||||(/_\n\n");
    printf("                                    Press n \n");
    printf("                                          _          \n");
    printf("                           |  _  _  _|   (_| _ __  _  \n");
    printf("                           | (_)(_|(_|   __|(_||||(/_\n\n");
    printf("                                    Press l \n");
    printf("                                   __         \n");
    printf("                                  |_     o _|_ \n");
    printf("                                  |__><  |  |_ \n\n");
    printf("                                    Press E \n");
    printf("\n");
    printf("                                     ");
    char s=getchar();
    while ((s!='n')&&(s!='l')&&(s!='N')&&(s!='L')&&(s!='E')&&(s!='e'))
    {
        system("cls");
        HANDLE hConsole2;
        hConsole2=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,9);
        printf("\n\n\n\n");
        printf("                                         _          \n");
        printf("                            __  _       (_| _ __  _ \n");
        printf("                            | |(/_\\^/   __|(_||||(/_\n\n");
        printf("                                    Press n \n");
        printf("                                          _          \n");
        printf("                           |  _  _  _|   (_| _ __  _  \n");
        printf("                           | (_)(_|(_|   __|(_||||(/_\n\n");
        printf("                                    Press l \n");
        printf("                                   __         \n");
        printf("                                  |_     o _|_ \n");
        printf("                                  |__><  |  |_ \n\n");
        printf("                                    Press E \n");
        printf("\n");
        printf("                                       ");
        s=getchar();
    }
    if ((s=='n')||(s=='N'))
    {
        system("cls");
        howToPlay();
        char t,f;
        t=getchar();
        f=getchar();
        system("cls");
        playerName();
    }
    else if ((s=='l')||(s=='L'))
    {
        printf("\n                       ");
        load();
        system("cls");
        printBoard();
    }
    else if ((s=='e')||(s=='E'))
    {
        printf("\tThanks for playing\n\tGoodbye:)\n");
        exit(0);
    }
}


void playerName()
{
    HANDLE hConsole2;
    hConsole2=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole2,7);
    printf("\n\n\n\n\n\n\n");
    printf("\t Enter player one's name(Playing with the BLACK pieces): ");
    printf("\n\n");
    printf("                                   ");
    scanf("%s", playerOne);
    printf("\n");
    printf("\t Enter player two's name(Playing with the WHITE pieces): ");
    printf("\n\n");
    printf("                                   ");
    scanf(" %s", playerTwo);
    printf("\n");
    HANDLE hConsole3;
    hConsole3=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole3,5);
    printf("\t\t\t  WELCOME %s and %s\n", playerOne, playerTwo);
    printf("\n\t\t\tPress Enter to continue");
    char c;
    c=getchar();
    c=getchar();
    while (c!='\n')
    {
        c=getchar();
    }
    system("cls");
    printBoard();
}

void printBoard()
{
    int i,j;
    for (i=0;i<nor;i++)
    {
        for(j=0;j<noc;j++)
        {
            if((i==1)||(i==19)||(j==8)||(j==35))
            {
                HANDLE hConsole;
                hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,11);
                printf("%c",board[i][j]);
            }
            else if (((i<18)&&(i>2))&&((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N')))

            {
                HANDLE hConsole;
                hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,8); //player 1
                printf("%c",board[i][j]);
            }
            else if (((i<18)&&(i>2))&&((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))){
            {
                HANDLE hConsole;
                hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,15); // player 2
                printf("%c",board[i][j]);
            }}
            else
            {
                HANDLE hConsole;
                hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,15); //white
                printf("%c",board[i][j]);
            }
        }
        printf("\n");
    }
}


void playerTurn()
{
    if (turn==0)
    {
        printf("%s's turn: ", playerOne);
    }
    else if (turn==1)
    {
        printf("%s's turn: ", playerTwo);
    }
}


void initialBoard()
{
    int i,j;
    // white square
    for (i=3;i<19;i=i+4)
    {
        for (j=11;j<35;j=j+6)
        {
            board[i][j]=ws;
        }
    }
    //  black square
    for (i=3;i<19;i=i+4)
    {
        for (j=14;j<35;j=j+6)
        {
            board[i][j]=bs;
        }
    }
    for (i=5;i<19;i=i+4)
    {
        for (j=11;j<35;j=j+6)
        {
            board[i][j]=bs;
        }
    }
    // white square
    for (i=5;i<19;i=i+4)
    {
        for (j=14;j<35;j=j+6)
        {
            board[i][j]=ws;
        }
    }
    // first ABC row
    board[1][11]='A';
    board[1][14]='B';
    board[1][17]='C';
    board[1][20]='D';
    board[1][23]='E';
    board[1][26]='F';
    board[1][29]='G';
    board[1][32]='H';
    //last ABC row
    board[19][11]='A';
    board[19][14]='B';
    board[19][17]='C';
    board[19][20]='D';
    board[19][23]='E';
    board[19][26]='F';
    board[19][29]='G';
    board[19][32]='H';
    //first np column
    board[3][8]='8';
    board[5][8]='7';
    board[7][8]='6';
    board[9][8]='5';
    board[11][8]='4';
    board[13][8]='3';
    board[15][8]='2';
    board[17][8]='1';
    //last no column
    board[3][35]='8';
    board[5][35]='7';
    board[7][35]='6';
    board[9][35]='5';
    board[11][35]='4';
    board[13][35]='3';
    board[15][35]='2';
    board[17][35]='1';
    //first row pieces
    board[3][11]='R';
    board[3][14]='N';
    board[3][17]='B';
    board[3][20]='Q';
    board[3][23]='K';
    board[3][26]='B';
    board[3][29]='N';
    board[3][32]='R';
    // last row pieces
    board[17][11]='r';
    board[17][14]='n';
    board[17][17]='b';
    board[17][20]='q';
    board[17][23]='k';
    board[17][26]='b';
    board[17][29]='n';
    board[17][32]='r';
    // first soldiers
    board[5][11]='P';
    board[5][14]='P';
    board[5][17]='P';
    board[5][20]='P';
    board[5][23]='P';
    board[5][26]='P';
    board[5][29]='P';
    board[5][32]='P';
    // last soldies
    board[15][11]='p';
    board[15][14]='p';
    board[15][17]='p';
    board[15][20]='p';
    board[15][23]='p';
    board[15][26]='p';
    board[15][29]='p';
    board[15][32]='p';
    // dead white
    board[2][47]='W';
    board[2][48]='H';
    board[2][49]='I';
    board[2][50]='T';
    board[2][51]='E';
    board[3][47]='-';
    board[3][48]='-';
    board[3][49]='-';
    board[3][50]='-';
    board[3][51]='-';
    // dead black
    board[2][53]='B';
    board[2][54]='L';
    board[2][55]='A';
    board[2][56]='C';
    board[2][57]='K';
    board[3][53]='-';
    board[3][54]='-';
    board[3][55]='-';
    board[3][56]='-';
    board[3][57]='-';
    //lines
    for(i=2;i<19;i++)
    {
        board[i][46]='|';
        board[i][52]='|';
        board[i][58]='|';
    }
}


void scanMove()
{
    char s;
    a=getchar();
    s=getchar();
    if (s=='\n')
    {
        while (a=='\n')
        {
            a=getchar();
        }
        if ((a=='s')||(a=='S'))
        {
            save();
            printf("Your Game is Saved!\n");
            playerTurn();
            scanMove();
        }
        else if ((a=='l')||(a=='L'))
        {
            load();
            system("cls");
            printBoard();
            sequence();
        }
        else if((a=='u')||(a=='U'))
        {
            undoMoves();
            if (undoFlag==1)
            {
                system("cls");
                printBoard();
                sequence();
            }
            else
            {
                printf("There are no more moves to be undone!\n");
                flag=0;
                sequence();
            }
        }
        else if((a=='r')||(a=='R'))
        {
            redoMoves();
            if (redoFlag==1)
            {
                system("cls");
                printBoard();
                sequence();
            }
            else
            {
                printf("There are no moves to be redone.\n");
                flag=0;
                sequence();
            }
        }
        else if ((a=='e')||(a=='E'))
        {
            printf("\tThanks for playing\n\tGoodbye:)\n");
            exit(0);
        }
    }
    else
    {
        x=s-48;
        scanf("%c%d",&b,&y);
    }
}

void convertMoves()
{
    switch(a)
    {
    case 'A':
        {
            a1=11;
            reScan1=0;
            break;
        }
    case 'B':
        {
            a1=14;
            reScan1=0;
            break;
        }
    case 'C':
        {
            a1=17;
            reScan1=0;
            break;
        }
    case'D':
        {
            a1=20;
            reScan1=0;
            break;
        }
    case'E':
        {
            a1=23;
            reScan1=0;
            break;
        }
    case'F':
            a1=26;
            reScan1=0;
            break;
    case'G':
        {
            a1=29;
            reScan1=0;
            break;
        }
    case'H':
        {
            a1=32;
            reScan1=0;
            break;
        }
    default:
        {
            printf("%c is not on the board! Enter a letter from(A-H): ",a);
            reScan1=1;
        }
    }
    switch(b)
    {
    case 'A':
        {
            b1=11;
            reScan2=0;
            break;
        }
    case 'B':
        {
            b1=14;
            reScan2=0;
            break;
        }
    case 'C':
        {
            b1=17;
            reScan2=0;
            break;
        }
    case'D':
        {
            b1=20;
            reScan2=0;
            break;
        }
    case'E':
        {
            b1=23;
            reScan2=0;
            break;
        }
    case'F':
            b1=26;
            reScan2=0;
            break;
    case'G':
        {
            b1=29;
            reScan2=0;
            break;
        }
    case'H':
        {
            b1=32;
            reScan2=0;
            break;
        }
    default:
        {
            printf("%c is not on the board! Enter a letter from(A-H): ",b);
            reScan2=1;
        }
    }
    switch(x)
    {
    case 1:
        {
            x1=17;
            reScan3=0;
            break;
        }
    case 2:
        {
            x1=15;
            reScan3=0;
            break;
        }
    case 3:
        {
            x1=13;
            reScan3=0;
            break;
        }
    case 4:
        {
            x1=11;
            reScan3=0;
            break;
        }
    case 5:
        {
            x1=9;
            reScan3=0;
            break;
        }
    case 6:
            x1=7;
            reScan3=0;
            break;
    case 7:
        {
            x1=5;
            reScan3=0;
            break;
        }
    case 8:
        {
            x1=3;
            reScan3=0;
            break;
        }
    default:
        {
            printf("%d is not on the board! Enter a number from(1-8): ",x);
            reScan3=1;
        }
    }
    switch(y)
    {
    case 1:
        {
            y1=17;
            reScan4=0;
            break;
        }
    case 2:
        {
            y1=15;
            reScan4=0;
            break;
        }
    case 3:
        {
            y1=13;
            reScan4=0;
            break;
        }
    case 4:
        {
            y1=11;
            reScan4=0;
            break;
        }
    case 5:
        {
            y1=9;
            reScan4=0;
            break;
        }
    case 6:
            y1=7;
            reScan4=0;
            break;
    case 7:
        {
            y1=5;
            reScan4=0;
            break;
        }
    case 8:
        {
            y1=3;
            reScan4=0;
            break;
        }
    default:
        {
            printf("%d is not on the board! Enter a number from(1-8): ",y);
            reScan4=1;
        }
    }
}

void checkInput()
{
    while(reScan1||reScan2||reScan3||reScan4)
    {
        scanMove();
        convertMoves();
        while (getchar()!='\n'){}
    }
    reScan1=1,reScan2=1,reScan3=1,reScan4=1;
    system("cls");
}

void inSquare()//search what character is in square
{
    piece=board[x1][a1];
    if(turn==0)
    {
        switch(piece)
        {
        case'Q':
            checkKindOfMove();
            break;
        case'P':
            movePawn();
            break;
        case'R':
            moveRook();
            break;
        case'B':
            moveBishop();
            break;
        case'N':
            moveKnight();
            break;
        case 'K':
            moveKing();
            break;
        default :
            flag=0;
        }
    }
    else
    {
        switch(piece)
        {
            case 'p':
                movePawn();
                break;
            case'q':
                checkKindOfMove();
                break;
            case'r':
                moveRook();
                break;
            case'b':
                moveBishop();
                break;
            case'n':
                moveKnight();
                break;
            case 'k':
                moveKing();
                break;
            default :
               flag=0;
        }
    }
}

void checkKindOfMove()//rook queen bishop contains functions vertical, horizontal and diagonal
{

    if ((x1==y1)&&(a1==b1))
    {
        flag=0;
    }
    else if (a1==b1)
    {
        movingVertical();
    }
    else if (x1==y1)
    {
        movingHorizontal();
    }
    else if ((((x1-y1)/2)==((a1-b1)/3))||(((x1-y1)/2)==-((a1-b1)/3)))
    {
        movingDiagonal();
    }
    else
    {
        flag=0;
    }

}


void movingVertical()//queen rook
{
    l=0;
    flag =1;
    int i;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11)) // OUT THE BORDERS
    {
        flag=0;
    }
    else
    {
        if (x1<y1) //vertical down
        {
            for (i=x1+1;(flag)&&(i<=y1);i++)
            {
                if ((board[i][a1]==ws)||(board[i][a1]==bs)||(board[i][a1]==0))
                {
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=i;
                        enemyPath[m][1]=a1;
                        m++;
                    }
                }
                else if (i==y1)
                {
                    if (turn==0)
                    {
                        if ((board[i][a1]=='q')||(board[i][a1]=='b')||(board[i][a1]=='r')||(board[i][a1]=='k')||(board[i][a1]=='p')||(board[i][a1]=='n'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else if (turn==1)
                    {
                        if ((board[i][a1]=='Q')||(board[i][a1]=='B')||(board[i][a1]=='R')||(board[i][a1]=='K')||(board[i][a1]=='P')||(board[i][a1]=='N'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else
                {
                    flag=0;
                }
            }
        }
        else if (x1>y1) // vertical up
        {
            for (i=x1-1;(flag)&&(i>=y1);i--)
            {
                if ((board[i][a1]==ws)||(board[i][a1]==bs)||(board[i][a1]==0))
                {
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=i;
                        enemyPath[m][1]=a1;
                        m++;
                    }
                }
                else if (i==y1)
                {
                    if (turn==0)
                    {
                        if ((board[i][a1]=='q')||(board[i][a1]=='b')||(board[i][a1]=='r')||(board[i][a1]=='k')||(board[i][a1]=='p')||(board[i][a1]=='n'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else if (turn==1)
                    {
                        if ((board[i][a1]=='Q')||(board[i][a1]=='B')||(board[i][a1]=='R')||(board[i][a1]=='K')||(board[i][a1]=='P')||(board[i][a1]=='N'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else
                {
                    flag=0;

                }
            }
        }

    }
}


void movingHorizontal()//queen rook
{

    flag =1;
    int j;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else
    {
        if (a1<b1) // to the right
        {
            for (j=a1+1;(flag)&&(j<=b1);j++)
            {
                if ((board[x1][j]==ws)||(board[x1][j]==bs)||(board[x1][j]==0))
                {
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=x1;
                        enemyPath[m][1]=j;
                        m++;
                    }
                }
                else if (j==b1)
                {
                    if (turn==0)
                    {
                        if ((board[x1][j]=='q')||(board[x1][j]=='b')||(board[x1][j]=='r')||(board[x1][j]=='k')||(board[x1][j]=='p')||(board[x1][j]=='n'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else if (turn==1)
                    {
                        if ((board[x1][j]=='Q')||(board[x1][j]=='B')||(board[x1][j]=='R')||(board[x1][j]=='K')||(board[x1][j]=='P')||(board[x1][j]=='N'))
                        {
                            flag=2;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else
                {
                    flag=0;
                }
            }

        }
        else if (a1>b1) // to the left
        {
            for (j=a1-1;(flag)&&(j>=b1);j--)
            {
                if ((board[x1][j]==ws)||(board[x1][j]==bs)||(board[x1][j]==0))
                {
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=x1;
                        enemyPath[m][1]=j;
                        m++;
                    }
                }
                else if (j==b1)
            {
                if (turn==0)
                {
                    if ((board[x1][j]=='q')||(board[x1][j]=='b')||(board[x1][j]=='r')||(board[x1][j]=='k')||(board[x1][j]=='p')||(board[x1][j]=='n'))

                    {
                        flag=2;
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else if (turn==1)
                {
                    if ((board[x1][j]=='Q')||(board[x1][j]=='B')||(board[x1][j]=='R')||(board[x1][j]=='K')||(board[x1][j]=='P')||(board[x1][j]=='N'))
                    {
                        flag=2;
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else
                {
                    flag=0;
                }
            }
         else
            {
                flag=0;

            }

        }

    }

}}

void movingDiagonal() //CHECK WHEATHER THE DIAGONAL IS DOWNRIGHT DOWNLEFT UPRIGHT UPLEFT
{

    flag=1;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else if((y1>=(x1+2))&&(b1>=(a1+3))) //moving diagonally down right
    {
        movingDownRight();
    }
    else if((y1<=(x1-2))&&(b1>=(a1+3))) //moving diagonally up right
    {
        movingUpRight();
    }
    else if((y1>=x1+2)&&(b1<=a1-3)) //moving diagonally down left
    {
        movingDownLeft();
    }
    else if((y1<=x1-2)&&(b1<=a1-3)) //moving diagonally up left
    {
        movingUpLeft();
    }
    else
    {
        flag=0;
    }

}

void movingDownRight() //diagonal
{
    flag=1;
    int i,j;
    j=a1+3;// D
    for(i=x1+2;i<=y1;i=i+2)
    {
        if((board[i][j]==ws)||(board[i][j]==bs))
        {
            j=j+3;
            if(getPathFlag==1)
                {
                    enemyPath[m][0]=i;
                    enemyPath[m][1]=j;
                    m++;
                }
        }

        else if(j==b1)
        {
            if(turn==0)
            {
                if((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=2;
                }
            }
            else if(turn==1)
            {
                if((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=2;
                }
            }
        }
        else if(j!=b1)
        {
            flag=0;
        }
    }
}

void movingUpRight() //diagonal
{
    flag=1;
    int i,j;
    j=a1+3;
    for(i=x1-2;i>=y1;i=i-2)
    {
        if((board[i][j]==ws)||(board[i][j]==bs))
        {
            j=j+3;
            if(getPathFlag==1)
                {
                    enemyPath[m][0]=i;
                    enemyPath[m][1]=j;
                    m++;
                }
        }
        else if(j==b1)
        {
            if(turn==0)
            {
                if((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=2;
                }
            }
            else if(turn==1)
            {
                if((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=2;
                }
            }
        }
        else if(j!=b1)
        {
            flag=0;
        }
    }

}

void movingDownLeft() //diagonal
{

    flag=1;
    int i,j;
    j=a1-3;
    for(i=x1+2;i<=y1;i=i+2)
    {
        if((board[i][j]==ws)||(board[i][j]==bs))
        {
            j=j-3;
            if(getPathFlag==1)
                {
                    enemyPath[m][0]=i;
                    enemyPath[m][1]=j;
                    m++;
                }
        }
        else if(j==b1)
        {
            if(turn==0)
            {
                if((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=2;
                }
            }
            else if(turn==1)
            {
                if((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=2;
                }
            }
        }
        else if(j!=b1)
        {
            flag=0;
        }
    }
}

void movingUpLeft() //diagonal
{

    flag=1;
    int i,j;
    j=a1-3;
    for(i=x1-2;i>=y1;i=i-2)
    {
        if((board[i][j]==ws)||(board[i][j]==bs))
        {
            j=j-3;
            if(getPathFlag==1)
                {
                    enemyPath[m][0]=i;
                    enemyPath[m][1]=j;
                    m++;
                }
        }
        else if(j==b1)
        {
            if(turn==0)
            {
                if((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=2;
                }
            }
            else if(turn==1)
            {
                if((board[i][j]=='q')||(board[i][j]=='b')||(board[i][j]=='r')||(board[i][j]=='k')||(board[i][j]=='p')||(board[i][j]=='n'))
                {
                    flag=0;
                }
                else if ((board[i][j]=='Q')||(board[i][j]=='B')||(board[i][j]=='R')||(board[i][j]=='K')||(board[i][j]=='P')||(board[i][j]=='N'))
                {
                    flag=2;
                }
            }
        }
        else if(j!=b1)
        {
            flag=0;
        }
    }
}


void movePawn()

{

    flag=1;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else{
    if (turn==0)
    {

        if ((y1==x1+2)&&(a1==b1))  // for moving st. forward
        {
            if ((board[y1][a1]==ws)||(board[y1][a1]==bs)||(board[y1][a1]==0))
            {
                if(getPathFlag==1)
                {
                    enemyPath[m][0]=y1;
                    enemyPath[m][1]=a1;
                    m++;
                }
            }
            else
            {

                flag=0;
            }
        }
        else if ((y1==x1+2)&&(a1!=b1))  // for eating
        {
            if ((b1==a1+3)||(b1==a1-3))
            {
                if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                {

                    flag=0;
                }
                else if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))// eating
                {
                    flag=2;
                }
                else
                {

                  flag=0;
                }
            }
            else
            {

              flag=0;
            }

        }
        else if (x1==5)  // for moving 2 steps in the first move
        {
            if ((y1==x1+4)&&(a1==b1))
            {
                if (((board[y1-2][a1]==ws)||(board[y1-2][a1]==bs)||(board[y1-2][a1]==0))&&((board[y1][a1]==ws)||(board[y1][a1]==bs)||(board[y1][a1]==0)))
                {
                    //moving();
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=y1;
                        enemyPath[m][1]=a1;
                        m++;
                        enemyPath[m][0]=y1-2;
                        enemyPath[m][1]=a1;
                        m++;
                    }
                }

            }
            else
            {
                flag=0;
            }

        }
        else
        {
          flag=0;
        }
        }
    else if (turn==1)
    {

        if ((y1==x1-2)&&(a1==b1))  // for moving st. forward
        {
            if ((board[y1][a1]==ws)||(board[y1][a1]==bs)||(board[y1][a1]==0))
            {
               // moving();
                if(getPathFlag==1)
                {
                    enemyPath[m][0]=y1;
                    enemyPath[m][1]=a1;
                    m++;
                }
            }
            else
            {
                flag=0;
            }
        }
        else if ((y1==x1-2)&&(a1!=b1))  // for eating
        {
            if ((b1==a1+3)||(b1==a1-3))
            {
                if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                {
                    flag=0;
                }
                else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                {
                    flag=2;
                }
                else
                {
                    flag=0;
                }
            }
            else
            {
              flag=0;
            }
        }
        else if (x1==15)  // for moving 2 steps in the first move
        {
            if ((y1==x1-4)&&(a1==b1))
            {
                if  (((board[y1+2][a1]==ws)||(board[y1+2][a1]==bs)||(board[y1+2][a1]==0))&&((board[y1][a1]==ws)||(board[y1][a1]==bs)||(board[y1][a1]==0)))
                {
                    if(getPathFlag==1)
                    {
                        enemyPath[m][0]=y1;
                        enemyPath[m][1]=a1;
                        m++;
                        enemyPath[m][0]=y1+2;
                        enemyPath[m][1]=a1;
                        m++;
                    }
                }
            }
            else
            {
                flag=0;
            }
        }
        else
        {
          flag=0;
        }
    }
    if (promotionFlag==1)
    {
        promotion();
    }

}}
 void moving()
 {
     int i,j;
     temp=board[y1][b1]; // store the eaten piece to put it outside
     board[y1][b1]=piece;
     for (i=3;i<17;i=i+4)// white square
     {
         for (j=11;j<32;j=j+6)// MAKE FLAG IF FIND

             if ((x1==i)&&(a1==j))
             {
                 board[i][j]=ws;//
             }

         }
     for (i=5;i<=17;i=i+4)// white square
     {
         for (j=14;j<=32;j=j+6)// MAKE FLAG IF FOUND

             if ((x1==i)&&(a1==j))
             {
                 board[i][j]=ws;
             }

         }

     for (i=3;i<19;i=i+4)// black square
     {
         for (j=14;j<35;j=j+6)
         {
             if ((x1==i)&&(a1==j))
             {
                 board[i][j]=bs;
             }
         }

     }
     for (i=5;i<=19;i=i+4)// black square
     {
         for (j=11;j<=35;j=j+6)
         {
             if ((x1==i)&&(a1==j))
             {
                 board[i][j]=bs;
             }
         }

     }


 }
 void eating()
 {
     moving();
     if(turn==0)
     {
         board[wi][wj]=temp;
         if(wj==48)
         {
             wj=50;
         }
         else if(wj=50)
         {
             wj=48;
             wi+=2;
         }
     }
     else if(turn==1)
     {
         board[bi][bj]=temp;
         if(bj==54)
         {
            bj=56;
         }
         else if(bj==56)
         {
             bj=54;
             bi+=2;
         }
     }

 }

 void moveRook()
 {
     flag=1;
     //taken from checkKindOfMove function
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else{
     if ((x1==y1)&&(a1==b1))
     {
         flag=0;
     }
     else if (a1==b1)
    {
        movingVertical();
    }
    else if (x1==y1)
    {
        movingHorizontal();
    }
    else
    {
       flag=0;
    }
 }}
 void moveBishop()
 {
     flag=1;
     //taken from checkKindOfMove
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else{
     if (a1==b1)
    {
        flag=0;
    }
    else if (x1==y1)
    {
        flag=0;
    }
    else if ((((x1-y1)/2)==((a1-b1)/3))||(((x1-y1)/2)==-((a1-b1)/3)))
    {
        movingDiagonal();
    }
    else
    {
        flag=0;
    }
 }}

 void moveKnight()
 {
     flag=1;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else{
     if((b1==(a1+3))||(b1==(a1-3)))
     {
         if((y1==(x1+4))||(y1==(x1-4)))
         {
             if(turn==0)
             {
                 if((board[y1][b1]==ws)||(board[y1][b1]==bs))
                 {

                     //moving();
                 }
                 else if((board[y1][b1]=='Q')||(board[y1][b1]=='K')||(board[y1][b1]=='N')||(board[y1][b1]=='B')||(board[y1][b1]=='P')||(board[y1][b1]=='R'))
                 {
                     flag=0;
                 }
                 else if((board[y1][b1]=='q')||(board[y1][b1]=='k')||(board[y1][b1]=='n')||(board[y1][b1]=='b')||(board[y1][b1]=='p')||(board[y1][b1]=='r'))
                 {
                     flag=2;
                 }
             }
             else if(turn==1)
             {
                 if((board[y1][b1]==ws)||(board[y1][b1]==bs))
                 {
                 }
                 else if((board[y1][b1]=='q')||(board[y1][b1]=='k')||(board[y1][b1]=='n')||(board[y1][b1]=='b')||(board[y1][b1]=='p')||(board[y1][b1]=='r'))
                 {
                     flag=0;
                 }
                 else if((board[y1][b1]=='Q')||(board[y1][b1]=='K')||(board[y1][b1]=='N')||(board[y1][b1]=='B')||(board[y1][b1]=='P')||(board[y1][b1]=='R'))
                 {
                     flag=2;
                 }

             }
         }
         else
         {
             flag=0;
         }
     }
     else if((b1==(a1+6))||(b1==(a1-6)))
     {
         if((y1==(x1+2))||(y1==(x1-2)))
         {
             if(turn==0)
             {
                 if((board[y1][b1]==ws)||(board[y1][b1]==bs))
                 {
                 }
                 else if((board[y1][b1]=='Q')||(board[y1][b1]=='K')||(board[y1][b1]=='N')||(board[y1][b1]=='B')||(board[y1][b1]=='P')||(board[y1][b1]=='R'))
                 {
                     flag=0;
                 }
                 else if((board[y1][b1]=='q')||(board[y1][b1]=='k')||(board[y1][b1]=='n')||(board[y1][b1]=='b')||(board[y1][b1]=='p')||(board[y1][b1]=='r'))
                 {
                     flag=2;
                 }
             }
             else if(turn==1)
             {
                 if((board[y1][b1]==ws)||(board[y1][b1]==bs))
                 {
                 }
                 else if((board[y1][b1]=='q')||(board[y1][b1]=='k')||(board[y1][b1]=='n')||(board[y1][b1]=='b')||(board[y1][b1]=='p')||(board[y1][b1]=='r'))
                 {
                     flag=0;
                 }
                 else if((board[y1][b1]=='Q')||(board[y1][b1]=='K')||(board[y1][b1]=='N')||(board[y1][b1]=='B')||(board[y1][b1]=='P')||(board[y1][b1]=='R'))
                 {
                     flag=2;
                 }
         }

     }
     else
     {
         flag=0;
     }
    }
    else
    {
        flag=0;
    }
 }}


 void moveKing()
 {

     flag=1;
    if ((y1>17)||(b1>32)||(y1<3)||(b1<11))
    {
        flag=0;
    }
    else{
     if (y1==x1)
     {
         if ((b1==a1+3)||(b1==a1-3))
         {
             if ((board[y1][b1]==ws)||(board[y1][b1]==bs)||(board[y1][b1]==0))
             {
             }
             else
             {
                 if (turn==0)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=2;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=0;
                     }

                 }
                 else if (turn==1)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=0;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=2;

                     }


                 }
             }
         }
         else
         {
             flag=0;
         }
     }
     else if (a1==b1)
     {
         if ((y1==x1+2)||(y1==x1-2))
         {
             if ((board[y1][b1]==ws)||(board[y1][b1]==bs)||(board[y1][b1]==0))
             {
             }
             else
             {
                 if (turn==0)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=2;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=0;
                     }

                 }
                 else if (turn==1)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=0;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=2;
                     }


                }
            }

        }
        else

        {
            flag=0;
        }
     }
     else if (((y1==x1+2)&&(b1==a1+3))||((y1==x1+2)&&(b1==a1-3))||((y1==x1-2)&&(b1==a1+3))||((y1==x1-2)&&(b1==a1-3)))
     {
        if ((y1==x1+2)||(y1==x1-2))
         {
             if ((board[y1][b1]==ws)||(board[y1][b1]==bs)||(board[y1][b1]==0))
             {
             }
             else
             {
                 if (turn==0)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=2;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=0;
                     }

                 }
                 else if (turn==1)
                 {
                     if ((board[y1][b1]=='q')||(board[y1][b1]=='b')||(board[y1][b1]=='r')||(board[y1][b1]=='k')||(board[y1][b1]=='p')||(board[y1][b1]=='n'))
                     {
                         flag=0;
                     }
                     else if ((board[y1][b1]=='Q')||(board[y1][b1]=='B')||(board[y1][b1]=='R')||(board[y1][b1]=='K')||(board[y1][b1]=='P')||(board[y1][b1]=='N'))
                     {
                         flag=2;
                     }


                }
            }

        }


     }
     else
     {
         flag=0;
     }
     if (flag!=0)
     {
         if (turn==0)
         {
             tempkx=y1;
             tempka=b1;
         }
         else if (turn==1)
         {
             tempkx=y1;
             tempka=b1;
         }
     }

 }}


void promotion()
{
    if ((flag==1)||(flag==2))
    {
        printBoard();
    if (turn==0)
    {
        if (y1==17)
        {
            printf("Enter the promotion: ");
            scanf("%c",&prom);
            while (((prom!='Q')&&(prom!='K')&&(prom!='P')&&(prom!='R')&&(prom!='N')&&(prom!='B'))||(getchar())!='\n')
            {
                printf("Invalid input! ");
                printf("Enter the promotion: ");
                while (getchar()!='\n'){}
                scanf("%c",&prom);
            }
                tempPiece=piece;
                piece=prom;
                undo[u].piece=tempPiece;
                undo[u].promotedPiece=piece;

        }

    }
    else if (turn==1)
    {
        if (y1==3)
        {
            printf("Enter the promotion: ");
            scanf("%c",&prom);
            while (((prom!='q')&&(prom!='k')&&(prom!='p')&&(prom!='r')&&(prom!='n')&&(prom!='b'))||(getchar())!='\n')
            {
                printf("Invalid input! ");
                printf("Enter the promotion: ");
                while (getchar()!='\n'){}
                scanf("%c",&prom);

            }
                tempPiece=piece;
                piece=prom;
                undo[u].piece=tempPiece;
                undo[u].promotedPiece=piece;

        }
    }
    system("cls");
    }

    else {}

}

void checkAfterMove() // check after the move is done if the opponent is in check
{
    getPathFlag=1;
    promotionFlag=0;
    if (turn==0)
    {
        x1=y1,a1=b1;
        dx=x1, da=a1;
        y1=kx2,b1=ka2;
        inSquare();
        dangerFlag=1;
        if (flag!=2)
        {checkDanger();}
        if ((flag==2)||(dangerFlag==0))
        {
            getPathFlag=0;
            checkMate();
            // if check mate print checkmate the stop by flag
            if(stop==0)
            {
                 printf("Check %s!\n",playerTwo);
            }

        }
        else
        {

            m=0;
            n=0;
            int l, k;
            for (l=0;l<9;l++)
            {
                for (k=0;k<9;k++)

                {
                    enemyPath[l][k]=0;
                }
            }

        }

    }
    else if (turn==1)
    {
        x1=y1,a1=b1;
        dx=x1, da=a1;
        y1=kx1,b1=ka1;
        inSquare();
        dangerFlag=1;
        if (flag!=2)
        {checkDanger();}
        if ((flag==2)||(dangerFlag==0))
        {

            getPathFlag=0;
            checkMate();
            // if check mate print checkmate the stop by flag

            if(stop==0)
            {
                printf("Check %s!\n",playerOne);
            }
        }
        else
        {

            m=0;
            n=0;
            int l, k;
            for (l=0;l<9;l++)
            {
                for (k=0;k<9;k++)

                {
                    enemyPath[l][k]=0;
                }
            }

        }
    }

}

void checkDanger()
{
    int i,j;
    getPathFlag=1;
    promotionFlag=0;
    dangerFlag=1;
    if (turn==1)
    {
        y1=kx1 ,b1=ka1;
     for(i=3;(i<=17)&&(dangerFlag!=0);i=i+2)
        {
            for(j=11;(j<=32)&&(dangerFlag!=0);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='k')
                {

                    moveKing();
                    if(flag==2)
                    {
                        dangerFlag=0;

                    }
                }
                else if(board[i][j]=='p')
                {
                    movePawn();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='r')
                {
                    moveRook();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='n')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='b')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
            }
        }
    }


    else if (turn==0)
    {
        y1=kx2,b1=ka2;
     for(i=3;(i<=17)&&(dangerFlag!=0);i=i+2)
        {
            for(j=11;(j<=32)&&(dangerFlag!=0);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='K')
                {
                    moveKing();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='P')
                {
                    movePawn();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='R')
                {
                    moveRook();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='N')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='B')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
                else if(board[i][j]=='Q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {
                        dangerFlag=0;
                    }
                }
            }
        }
    }
    if (dangerFlag==0)
    {
         dx=x1, da=a1;
    }

}


void checkMate() // it determine whether the king could be rescued or it is check mate (king move/eat, piece move/eat)
{
    checkFlag=0;
    tempTurn=turn;
    if (turn==0)
    {
        turn=1;
    }
    else if (turn==1)
    {
        turn=0;
    }
    kingEscape();

    if(checkFlag==0)
    {
        pieceEat();
    }
    if (checkFlag==0)
    {
        pieceMove();
    }
    turn=tempTurn;

    if(checkFlag==0)
    {
        if(turn==0)
        {
            printf("\nCHECKMATE %S wins.",playerOne);

        }
        else if(turn==1)
        {
            printf("\nCHECKMATE %s wins.",playerTwo);
        }
        stop=1;
    }


}

void pieceEat() // after a check to check if there is a piece to eat the other piece threatening the king
{
    int i,j;
    y1=dx, b1=da;
    eatFlag=0;
    checkFlag=0;
    tempBoard=board[y1][b1];
    tempPiece=piece;
    if(turn==1)
    {
        for(i=3;(i<=17)&&(eatFlag!=1);i=i+2)
        {
            for(j=11;(j<=32)&&(eatFlag!=1);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='k')
                {
                    moveKing();
                    if(flag==2)
                    {
                        board[y1][b1]='k';
                        piece='k';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='p')
                {
                    movePawn();
                    if(flag==2)
                    {
                        board[y1][b1]='p';
                        piece='p';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='r')
                {

                    moveRook();
                    if(flag==2)
                    {
                        board[y1][b1]='r';
                        piece='r';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='n')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        board[y1][b1]='n';
                        piece='n';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='b')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        board[y1][b1]='b';
                        piece='b';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {
                        board[y1][b1]='q';
                        piece='q';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }
                    }
                }
            }
        }
    }
     else if(turn==0)
    {
        for(i=3;(i<=17)&&(eatFlag!=1);i=i+2)
        {
            for(j=11;(j<=32)&&(eatFlag!=1);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='K')
                {
                    moveKing();
                    if(flag==2)
                    {
                        board[y1][b1]='K';
                        piece='K';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='P')
                {
                    movePawn();
                    if(flag==2)
                    {
                        board[y1][b1]='P';
                        piece='P';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='R')
                {
                    moveRook();
                    if(flag==2)
                    {
                        board[y1][b1]='R';
                        piece='R';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='N')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        board[y1][b1]='N';
                        piece='N';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='B')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        board[y1][b1]='B';
                        piece='B';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }                    }
                }
                else if(board[i][j]=='Q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {

                        board[y1][b1]='Q';
                        piece='Q';
                        checkMyKing();
                        if (checkFlag==1)
                        {
                            eatFlag=1;
                        }
                    }
                }
            }
        }
    }
    if (eatFlag==0)
    {
        checkFlag=0;
    }
    else
    {
        checkFlag=1;
    }
    board[y1][b1]=tempBoard;
    piece=tempPiece;
}

void kingEscape() // after a check ... check if the king can move to safe himself
{
    int escapeFlag=0; // flag if 0 means can't escape
    int tempkx1=kx1,tempka1=ka1,tempkx2=kx2,tempka2=ka2; // store the king location when it escape as it changes when we assume it moved to check if it is still under threat
    char tempBoard;
    tempPiece2=piece;
    if(turn==1)
    {
        x1=kx2;
        a1=ka2;
    }
    else if(turn==0)
    {
        x1=kx1;
        a1=ka1;
    }


    y1=x1+2;
    b1=a1+3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1+2;
    b1=a1-3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1-2;
    b1=a1+3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1-2;
    b1=a1-3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1;
    b1=a1+3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1;
    b1=a1-3;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1+2;
    b1=a1;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }
    y1=x1-2;
    b1=a1;
    inSquare();
    tempBoard=board[y1][b1];
    if (turn==0)
    {
        board[y1][b1]='K';
    }
    else if (turn==1)
    {
        board[y1][b1]='k';
    }
    kx1=y1,ka1=b1;
    kx2=y1,ka2=b1;
    checkMyKing();
    board[y1][b1]=tempBoard;
    if((flag!=0)&&(checkFlag!=0))
    {
        escapeFlag=1;
    }

    if (escapeFlag==0)
    {
        checkFlag=0;
    }
    else
    {
        checkFlag=1;
    }
    kx1=tempkx1,ka1=tempka1,kx2=tempkx2,ka2=tempka2;
    piece=tempPiece2;
}

void stalemateCheck() // at the beginning of each player turn to determine if he has moves or not
{

    promotionFlag=0;
    int i,j;
    int m=0,n=0;
    char tempPiece=piece;
    int tempCheckFlag=checkFlag;
    checkFlag=1;
    if(turn==0)
    {
        for(i=3;(i<=17)&&(stalemateFlag!=1);i=i+2)
        {
            for(j=11;(j<=32)&&(stalemateFlag!=1);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='Q')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            checkKindOfMove();
                            if((flag==2)||(flag==1))
                            {
                                piece='Q';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }

                            }
                        }

                    }
                }
                else if(board[i][j]=='R')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {

                            y1=m, b1=n;
                            moveRook();
                            if((flag==2)||(flag==1))
                            {
                                piece='R';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='B')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            moveBishop();
                            if((flag==2)||(flag==1))
                            {
                                piece='B';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='N')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;((n<=32)&&(stalemateFlag!=1));n=n+3)
                        {
                            y1=m, b1=n;
                            moveKnight();
                            if((flag==2)||(flag==1))
                            {
                                piece='N';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='K')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            moveKing();
                            if((flag==2)||(flag==1))
                            {
                                piece='K';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='P')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            movePawn();
                            if((flag==2)||(flag==1))
                            {
                                piece='P';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }

            }
        }
    }
    else if(turn==1)
    {
        for(i=3;(i<=17)&&(stalemateFlag!=1);i=i+2)
        {
                for(j=11;(j<=32)&&(stalemateFlag!=1);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='q')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            checkKindOfMove();
                            if((flag==2)||(flag==1))
                            {
                                piece='q';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='r')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {

                            y1=m, b1=n;
                            moveRook();
                            if((flag==2)||(flag==1))
                            {
                                piece='r';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='b')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            moveBishop();
                            if((flag==2)||(flag==1))
                            {
                                piece='b';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='n')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;((n<=32)&&(stalemateFlag!=1));n=n+3)
                        {
                            y1=m, b1=n;
                            moveKnight();
                            if((flag==2)||(flag==1))
                            {
                                piece='n';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='k')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            moveKing();
                            if((flag==2)||(flag==1))
                            {
                                piece='k';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }
                else if(board[i][j]=='p')
                {
                    for(m=3;(m<=17)&&(stalemateFlag!=1);m=m+2)
                    {
                        for(n=11;(n<=32)&&(stalemateFlag!=1);n=n+3)
                        {
                            y1=m, b1=n;
                            movePawn();
                            if((flag==2)||(flag==1))
                            {
                                piece='p';
                                checkMyKing();
                                if (checkFlag==1)
                                {
                                 stalemateFlag=1;
                                }                            }
                        }

                    }
                }

            }
        }
    }
    promotionFlag=1;
    piece=tempPiece;
    checkFlag=tempCheckFlag;

}

void checkMyKing() // TO CHECK IF after player's move his king is safe or not
{
    int i,j;
    int tempFlag=flag;
    flag=0;
    myKingFlag=1;
    checkFlag=0;
    tempTurn2=turn;
    tempBoard2=board[y1][b1];
    board[y1][b1]=piece;
    board[x1][a1]=ws;


    int tempx=x1,tempy=y1,tempa=a1,tempb=b1; // bec after this function the flag of the wanted motion is changed according to this new unwanted motion
    if(turn==0)
    {
        turn=1;
        if (piece!='K')
        {
        y1=kx1,b1=ka1;
        }
        else if (piece=='K')
        {
         y1=tempkx,b1=tempka;
        }
        for(i=3;(i<=17)&&(myKingFlag!=0);i=i+2)
        {
            for(j=11;(j<=32)&&(myKingFlag!=0);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='k')
                {

                    moveKing();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='p')
                {
                    movePawn();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='r')
                {
                    moveRook();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='n')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='b')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
            }
        }
    }
    else if(turn==1)
    {
        turn=0;
        if (piece!='k')
        {
        y1=kx2,b1=ka2;
        }
        else if (piece=='k')
        {
         y1=tempkx,b1=tempka;
        }
        for(i=3;(i<=17)&&(myKingFlag!=0);i=i+2)
        {
            for(j=11;(j<=32)&&(myKingFlag!=0);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='K')
                {
                    moveKing();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='P')
                {
                    movePawn();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='R')
                {
                    moveRook();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='N')
                {
                    moveKnight();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='B')
                {
                    moveBishop();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
                else if(board[i][j]=='Q')
                {
                    checkKindOfMove();
                    if(flag==2)
                    {
                        myKingFlag=0;
                    }
                }
            }
        }
    }
    if (myKingFlag==0)
    {
        checkFlag=0;
    }
    else
    {
        checkFlag=1;
    }

    flag=tempFlag;
    x1=tempx;
    y1=tempy;
    a1=tempa;
    b1=tempb;
    turn=tempTurn2;
    board[x1][a1]=piece;
    board[y1][b1]=tempBoard2;
}

void pieceMove()
{
    moveFlag=0;
    int i,j;
    int c; // it makes a loop on every square the will move in
    if(turn==1)
    {
        for(i=3;(i<=17)&&(moveFlag==0);i=i+2)
        {
            for(j=11;(j<=32)&&(moveFlag==0);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='p')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        movePawn();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='r')
                {
                    for(c=0;(c<=m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveRook();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='n')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveKnight();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='b')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveBishop();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='q')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        checkAfterMove();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
            }
        }
    }
    else if(turn==0)
    {
        for(i=3;(i<=17);i=i+2)
        {
            for(j=11;(j<=32);j=j+3)
            {
                x1=i, a1=j;
                if(board[i][j]=='P')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        movePawn();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='R')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveRook();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='N')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveKnight();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='B')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        moveBishop();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
                else if(board[i][j]=='Q')
                {
                    for(c=0;(c<m)&&(moveFlag==0);c++)
                    {
                        y1=enemyPath[c][0];
                        b1=enemyPath[c][1];
                        checkAfterMove();
                        if(flag==1)
                        {
                            moveFlag=1;
                        }
                    }
                }
            }
        }
    }
    if(moveFlag==1)
    {
        checkFlag=1;
    }
    else
    {
        checkFlag==0;
    }
}

void undoMoves()
{
    undoFlag=1;
    if (u==0)
    {
        undoFlag=0;
    }
    else
    {
    u--;
    if(undo[u].promotedPiece!=0)
    {
        if(turn==0)
        {
            board[undo[u].y][undo[u].b]=undo[u].eaten;
            board[undo[u].x][undo[u].a]='p';
        }
        else if(turn==1)
        {
            board[undo[u].y][undo[u].b]=undo[u].eaten;
            board[undo[u].x][undo[u].a]='P';
        }
    }else{
    board[undo[u].y][undo[u].b]=undo[u].eaten;
    board[undo[u].x][undo[u].a]=undo[u].piece;
    turn=undo[u].turn;
    }
    if((undo[u].eaten!=0)&&(undo[u].eaten!=ws)&&(undo[u].eaten!=bs))
    {
        if(turn==1)
        {
            if (bj==56)
            {
                bj-=2;
            }
            else if (bj==54)
            {
                bj=56;
                bi-=2;
            }
            board[bi][bj]=0;
        }
        else if(turn==0)
        {
            if (wj==50)
            {
                wj-=2;
            }
            else if (wj==48)
            {
                wj=50;
                wi-=2;
            }

            board[wi][wj]=0;
        }
    }
    }
}

void redoMoves()
{
    redoFlag=1;
    if (u==nu)
    {
        redoFlag=0;
    }
    else if(((undo[u].eaten==0)||(undo[u].eaten==ws)||(undo[u].eaten==bs))||promotionFlag==1)
    {
        if((promotionFlag==1)&&(undo[u].promotedPiece!=0))
        {
            board[undo[u].y][undo[u].b]=undo[u].promotedPiece;
        }
        else {
    promotionFlag=0;
    board[undo[u].y][undo[u].b]=undo[u].piece;
    board[undo[u].x][undo[u].a]=undo[u].eaten;
    }
    }
    if(redoFlag==1){
    if(((undo[u].eaten!=0)&&(undo[u].eaten!=ws)&&(undo[u].eaten!=bs))||(promotionFlag==1))
    {
        int found=0;
        int i,j;
        while(!found){
       for (i=3;(i<17)&&(!found);i=i+4)// white square
        {
            for (j=11;(j<32)&&(!found);j=j+6)// MAKE FLAG IF FIND
            {
                if ((undo[u].x==i)&&(undo[u].a==j))
                {
                    board[undo[u].x][undo[u].a]=ws;//
                    found=1;
                }
            }
         }
         if(found==1)
         {
             break;
         }
     for (i=5;(i<=17)&&(!found);i=i+4)// white square
     {
         for (j=14;(j<=32)&&(!found);j=j+6)// MAKE FLAG IF FOUND

             if ((undo[u].x==i)&&(undo[u].a==j))
             {
                 board[undo[u].x][undo[u].a]=ws;//
                 found=1;
             }

         }
         if(found==1)
         {
             break;
         }

     for (i=3;(i<19)&&(!found);i=i+4)// black square
     {
         for (j=14;(j<35)&&(!found);j=j+6)
         {
             if ((undo[u].x==i)&&(undo[u].a==j))
             {
                 board[undo[u].x][undo[u].a]=bs;
                 found=1;
             }
         }

     }
     if(found==1)
         {
             break;
         }
     for (i=5;(i<=19)&&(!found);i=i+4)// black square
     {
         for (j=11;(j<=35)&&(!found);j=j+6)
         {
             if ((undo[u].x==i)&&(undo[u].a==j))
             {
                 board[undo[u].x][undo[u].a]=bs;
                 found=1;
             }
         }

     }
     if(found==1)
         {
             break;
         }
        }
        if(promotionFlag!=1) board[undo[u].y][undo[u].b]=undo[u].piece;
        if((turn==1)&&(promotionFlag!=1))
        {
            if (bj==56)
            {
                board[bi][bj]=undo[u].eaten;
                bj=54;
                bi+=2;
            }
            else if (bj==54)
            {
                board[bi][bj]=undo[u].eaten;
                bj=56;
            }
        }
        else if((turn==0)&&(promotionFlag!=1))
        {
            if (wj==50)
            {
                board[wi][wj]=undo[u].eaten;
                wj=48;
                wi+=2;
            }
            else if (wj==48)
            {
                board[wi][wj]=undo[u].eaten;
                wj=50;
            }
        }
    }
    if (undo[u].turn==0)
    {
        turn=1;
    }
    else if (undo[u].turn==1)
    {
        turn=0;
    }
    u++;
    }
}




void save()
{
    char saveName[30]={0};
    char ch;
    int c='\0';
    printf("\nEnter the game name: ");
    ch=getchar();
    char getTurn;
    while (ch=='\n')
    {
        ch=getchar();
    }
    while(ch!='\n')
    {
        saveName[c]=ch;
        c++;
        ch=getchar();
    }
    //txt source
    strcat(saveName,".txt");


    FILE *fp;

    fp=fopen(saveName,"w");

    int i,j;
                if (turn==0)
            {
                fputs("0",fp);
            }
            else if (turn==1)
            {
                fputs("1",fp);
            }
        fputs("\n",fp);
        fputs(playerOne,fp);
        fputs("\n",fp);
        fputs(playerTwo,fp);
        fputs("\n",fp);
    for (i=0;i<nor;i++)
    {
        for(j=0;j<noc;j++)
        {
        fputc(board[i][j],fp);

        }
        fputs("\n",fp);
    }




    fclose(fp);


}


void load()
{
    char loadName[30]={0};
    char ch;
    char print[100];
    char z;
    int i=0,j=0;
    int c=0;
    int c1,c2;
    int saveText[5];


    printf("\nEnter the game name: ");

    ch=getchar();
    if (ch=='\n')
    {
        ch=getchar();
    }
    while(ch!='\n')
    {
        loadName[c]=ch;
        c++;
        ch=getchar();
    }
    strcat(loadName,".txt");
    FILE *fp;

    fp=fopen(loadName,"r");

    int l;
    while (fp==NULL)
    {
        printf("File not Found!\n");
        printf("Enter the game name: ");

        for(l=0;l<c+4;l++)
        {
            loadName[l]=0;
        }
        ch=getchar();
        c=0;
    if (ch=='\n')
    {
        ch=getchar();
    }
    while(ch!='\n')
    {
        loadName[c]=ch;
        c++;
        ch=getchar();
    }
    strcat(loadName,".txt");

    fp=fopen(loadName,"r");

    }

            char player1[50];
            char player2[50];
             c=0;
            z=fgetc(fp);
            turn=z-48;
            z=fgetc(fp);
            c=0,c1=0;
            z=fgetc(fp);
            while (z!='\n')
            {
                player1[c++]=z;
                z=fgetc(fp);
                c1++;
            }
            c=0;
            while(c<c1)
            {
             playerOne[c]=player1[c];
             c++;
            }
            c=0,c2=0;
            z=fgetc(fp);
            while (z!='\n')
            {

                player2[c++]=z;
                z=fgetc(fp);
                c2++;
            }
            c=0;
            while(c<c2)
            {
             playerTwo[c]=player2[c];
             c++;
            }
            z=fgetc(fp);

            while (z!=EOF)
            {
                for (i=0;i<nor;i++)
                {
                    for (j=0;(z!='\n')&&(j<noc);j++)
                    {
                        if (z!='\0')
                        {

                            board[i][j]=z;
                            z=fgetc(fp);
                        }
                        else{z=fgetc(fp);}

                    }
                    z=fgetc(fp);

                }
                z=fgetc(fp);
                while(z=='\n'){z=fgetc(fp);}

            }

            int x;
    fclose(fp);

}

void howToPlay()
    {
        HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,13);
    printf("\n");
    printf("\t\t\t\tUSER'S MANUAL\n\n");
    printf("\t\t\t      -----------------\n");
    printf("\n");
    HANDLE hConsole1;
    hConsole1=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole1,15); //white
    printf("Player one will be the one with the black pieces.\n");
    printf("Player two will be the one with the white pieces.\n\n");
    printf("You have to enter the moves you want to make in capital letters only.\n");
    printf("Yoy have to enter the move in the form of A1B2\n\n");
    printf("Where: A1 is your current place\t B2 is the place you want to move to.\n");
    printf("A and B are the names of the columns while 1 and 2 are the numbers of the rows.\n");
    printf("The columns are named from A to H only.\n");
    printf("The rows are numbered from 1 to 8 only.\n\n");
    printf("If you want to undo your last move, type \"u\" or \"U\".\n");
    printf("You can undo to the first move.\n\n");
    printf("If you want to redo your last undone move, type \"r\" or \"R\".\n");
    printf("You can redo to your last undone move.\n\n");
    printf("If you want to save your game, type \"s\" or \"S\".\n\n");
    printf("If you want to load your game, type \"l\" or \"L\".\n");
    }

