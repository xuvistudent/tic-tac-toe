#include <stdio.h>
#include <stdbool.h>

char square[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkWin() {
    if (square[0] == square[1] && square[1] == square[2]) {
        return true;
    } else if (square[0] == square[4] && square[4] == square[8]) {
        return true;
    } else if (square[0] == square[3] && square[3] == square[6]) {
        return true;
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return true;
    } else if (square[2] == square[4] && square[4] == square[6]) {
        return true;
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return true;
    } else if (square[3] == square[4] && square[4] == square[5]) {
        return true;
    } else if (square[6] == square[7] && square[7] == square[8]) {
        return true;
    } else {
        return false;
    }
}

void drawBoard(const char* square) {
    printf("    %c    |    %c    |    %c    \n", square[0], square[1], square[2]);
    printf("----------------------------\n");
    printf("    %c    |    %c    |    %c    \n", square[3], square[4], square[5]);
    printf("----------------------------\n");
    printf("    %c    |    %c    |    %c    \n", square[6], square[7], square[8]);
}

void playerPick(char* square, unsigned int index, const unsigned int player) {
    printf("Player %d pick an index: ", player % 2 ? 1 : 2);
    scanf("%d",&index);
    square[index-1] = player % 2 ? 'X' : 'O';
}

int main() {
    unsigned int player = 1, index;
    drawBoard(square);
    while(!checkWin() && (player < 10)) {
        playerPick(square, index, player);
        drawBoard(square);
        ++player;
    }
    if (checkWin()) {
        printf("Player %d Win\n", --player % 2 ? 1 : 2);
    } else {
        printf("Draw!\n");
    }
    return 0;
}
