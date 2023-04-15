#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

int main()
{

    char winner = ' ';
    char response;

    do{

        winner = ' ';
        response = ' ';
        resetBoard();

        while(winner!=0 && checkFreeSpaces != 0){

            printBoard();
            playerMove();

            computerMove();

            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }

        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play it again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
    
        response = toupper(response);

    }while(response = 'Y');

    printf("Thanks for playing");

    return 0;
}


void resetBoard(){
    for(int i = 0; i<3;i++){
        for(int y = 0; y<3; y++){
            board[i][y] = ' ';
        }
    }
}

void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces(){

    int freeSpaces = 9;

    for(int i =0;i<3;i++){
        for(int y=0; y<3; y++){
            if(board[i][y] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(){

    int x,y;

   do{

        printf("Enter row number (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column number (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }

   }while(board[x][y] != ' ');

}

void computerMove(){
    //check seeds
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces()>0){
        
        do{
            x = rand()%3;
            y = rand()%3;
        }while(board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else{
        printWinner(' ');
    }

}

char checkWinner(){

    //check rows
    for(int i =0; i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    //check column
    for(int y=0;y<3;y++){
        if(board[0][y]==board[1][y] && board[0][y] == board[2][y]){
            return board[0][y];
        }
    }

    //check diagonals
    if(board[0][0]==board[1][1]==board[2][2]){
        return board[0][0];
    }
    if(board[0][2]==board[1][1]==board[2][0]){
        return board[0][2];
    }

}   

void printWinner(char winner){
    if(winner == PLAYER){
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER){
        printf("YOU LOSE!");
    }
    else{
        printf("IT'S A TIE!");
    }
}