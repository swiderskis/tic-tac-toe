/*
A program designed to play tic-tac-toe within the console.
The players input their moves by typing the coordinates they wish to put their symbol in.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(int board[3][3]);
bool checkAllowedInput(int board[3][3], int posX, int posY);
int changeBoard(int board[3][3]);
int checkWinCondition(int board[3][3]);
void printTurnText(int turn);

int main() {
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int winCondition = 0;
    int turn = 1; // Specifies if it is player 1 or player 2's turn
    int round = 1; // Counts the number of rounds played (tic-tac-toe can never go over 9 rounds)
    int posX = 0;
    int posY = 0;
    bool allowedInput = false;

    while (winCondition == 0 && round < 10) {
        allowedInput = false;

        // Loop takes player input and determines if it is valid
        while (allowedInput == false) {
            system("cls");
            printBoard(board);
            printf("\nPlayer %d, input your position (in format e.g. 1 2):\n", turn);
            scanf("%d %d", &posY, &posX);
            allowedInput = checkAllowedInput(board,posX,posY);
        }

        // Assigns player input to board
        switch(turn) {
        case 1:
            board[posX-1][posY-1] = 1;
            break;
        case 2:
            board[posX-1][posY-1] = -1;
            break;
        }

        winCondition = checkWinCondition(board);
        round++;

        // Prints outcome if win condition has been met
        if (winCondition != 0) {
            system("cls");
            printBoard(board);
            printf("\nPlayer %d wins!\n",turn);
        } else if (round == 10) {
            system("cls");
            printBoard(board);
            printf("\nDraw!\n");
        }

        turn = turn%2 + 1;
    }

    return 0;
}

// Prints current state of board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch(board[i][j]) {
            case 1:
                printf("X ");
                break;
            case -1:
                printf("O ");
                break;
            case 0:
                printf("_ ");
                break;
            }
        }

        printf("\n");
    }
}

// Checks player input to see if input is allowed
bool checkAllowedInput(int board[3][3], int posX, int posY) {
    bool allowedInput = false;
    if (posX > 3 || posX < 1 || posY > 3 || posY < 1) {
        return allowedInput;
    } else if (board[posX-1][posY-1] != 0) {
        return allowedInput;
    } else {
        allowedInput = true;
        return allowedInput;
    }
}

// Checks current board to see if a win condition is met
int checkWinCondition(int board[3][3]) {
    int winCondition = 0;
    int checkHor[3] = {0,0,0}; // Checks on horizontal rows
    int checkVer[3] = {0,0,0}; // Checks on vertical columns
    int checkDiag[2] = {0,0}; // Checks on diagonals

    for (int i = 0; i < 3; i++) {
        checkHor[i] = board[i][0] + board[i][1] + board[i][2];

        if (abs(checkHor[i]) == 3) {
            winCondition = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        checkVer[i] = board[0][i] + board[1][i] + board[2][i];

        if (abs(checkVer[i]) == 3) {
            winCondition = 1;
        }
    }

    checkDiag[0] = board[0][0] + board[1][1] + board[2][2];
    checkDiag[1] = board[0][2] + board[1][1] + board[2][0];

    if (abs(checkDiag[0]) == 3 || abs(checkDiag[1]) == 3) {
        winCondition = 1;
    }

    return winCondition;
}
