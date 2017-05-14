#ifndef INITIALBOARD_H_INCLUDED
#define INITIALBOARD_H_INCLUDED
#define nor 23
#define noc 59

int friendPath[8][2]={0};
int enemyPath[8][2]={0};
int moveFlag=0;
int m,n; //counters for friend path
int s,k; //counters for enemy path
int testFlag=0; //to test whether if any element in the friend path array equals any element in the enemy path array

char playerOne[50];
char playerTwo[50];

char board[nor][noc]={0};
//struct counter[81];
char moves[500][3];
int reScan1=1,reScan2=1,reScan3=1,reScan4=1; //flag
int turn=0; //player's turn 0is for player one
//char kom;//kind of move
int wi=4,wj=48; //counters for dead white pieces
int bi=4,bj=54; //counters for dead square pieces
int changeTurn=1;// flag to know if to change turn or replay
int kx1=3,ka1=23;//player one king place
//int tx,ta;//temp value any king in checkAfterMove function
int kx2=17,ka2=23;//player two king place
//no of rows=nor,no of columns = noc.
int tempkx,tempka;
int u=0; //counter for the undo array
int nu=0;//number of undo
// black square=bs, white square =ws
char ws=219;
char bs=176;
char a,b;
int x,y;//INPUT FROM USER
int a1,b1,x1,y1;//CONVERTED INPUT
char piece;// finding char in square
char temp; //temporary value for the eaten pieces
char prom; // takes the value of promotion
int flag; // flag for invalid / move / eat
int promotionFlag;//stop promotion in checkAfterMove function
int dx,da; //places for the danger piece
int checkFlag=1; //flag to know if there are available moves after check 0--check OR check mate
int stop=0; //flag for stopping the game
int m,n; // counter for enemy path
int l;
int stalemateFlag=0;//---- o means  stalemate
int undoFlag=1;
int redoFlag=1;// 1 -- keep redoing
int tempTurn; // stores the true turn value when checking (piece eat / king escape / piece move)
int tempTurn2; // stores in check my king .. to prevent tempTurn from changing
char tempPiece,tempPiece2;// used in functions not to lose original piece
int myKingFlag; // used in check my king function
int eatFlag; // to check in piece eat
int tempBoard ;// stores the original board when trying a move
int tempBoard2;
int getPathFlag ; // flag used to give permission to store the enemy path .. it is activated in checkAfter Move . after check after move if it flag=2 , the path is stored . otherwise it is reset to zero
int dangerFlag; // in checkDanger



struct Undo
    {
        char piece;
        int x;
        int a;
        int y;
        int b;
        int turn;
        char eaten; //if equal zero therefore y1,b1 will be empty, else y1,b1 not empty
        char promotedPiece;



    } undo[500];

void initialBoard();
void printBoard();
void playerTurn();
void scanMove();
void convertMoves();
void checkInput();
void inSquare();
void checkKindOfMove();
//void movingType();
void movingVertical();
void movingHorizontal();
void movingDiagonal();
void movePawn();
void moving();
void eating();
void moveRook();
void moveBishop();
void moveKnight();
void checkAfterMove();
void checkMate();




struct Path
{
    int m;
    int n;
}path;


/*HANDLE hConsole;
hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,4);*/




/*HANDLE hConsole;
hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,4);*/


#endif // INITIALBOARD_H_INCLUDED
