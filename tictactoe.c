/*
 * TIC TAC TOE
 *
 * Requirements:
 * Create a CLI Tic Tac Toe game for two users
 */

#include <stdio.h>
#include <ncurses.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);


void markBoard(char mark) {
    if (choice == 1 && square[1] == '1') {
        square[1] = mark;
    } else if (choice == 2 && square[1] == '2') {
        square[1] = mark;
    } else if (choice == 3 && square[1] == '3') {
        square[1] = mark;
    } else if (choice == 4 && square[1] == '4') {
        square[1] = mark;
    } else if (choice == 5 && square[1] == '5') {
        square[1] = mark;
    } else if (choice == 6 && square[1] == '6') {
        square[1] = mark;
    } else if (choice == 7 && square[1] == '7') {
        square[1] = mark;
    } else if (choice == 8 && square[1] == '8') {
        square[1] = mark;
    } else if (choice == 9 && square[1] == '9') {
        square[1] = mark;
    } else {
        printf("Invalid move ");
        player--;
        getch();
    }
}


void displayBoard() {
    clear();
    printf("Player 1 (X) - Player 2 (O) \n\n\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", square[1], square[2], square[3]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", square[4], square[5], square[6]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", square[7], square[8], square[9]);
    printf("       |       |       \n\n");
}


int checkForWin() {
    if (square[1] == square[2] && square[2] == square[3]) {
        return 1;
    } else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if (square[7] == square[8] && square[8] == square[9]) {
        return 1;
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    } else if (square[3] == square[6] && square[6] == square[9]) {
        return 1;
    } else if (square[1] == square[5] && square[5] == square[9]) {
        return 1;
    } else if (square[3] == square[5] && square[5] == square[7]) {
        return 1;
    } else if (
            square[1] != 1 &&
            square[2] != 2 &&
            square[3] != 3 &&
            square[4] != 4 &&
            square[5] != 5 &&
            square[6] != 6 &&
            square[7] != 7 &&
            square[8] != 8 &&
            square[9] != 9
            ) {
        return 0;
    } else {
        return -1;
    }
}

int main(void) {
    int gameStatus;
    char mark;

    player = 1;

    do {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        printf("Player %d enter a number", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        markBoard(mark);
        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);

    if (gameStatus == 1) {
        printf("==>\aPlayer %d win", --player);
    } else {
        printf("==>\aGame draw");
    }
    return 0;
}
