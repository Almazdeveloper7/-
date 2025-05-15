#include <iostream>
#include <random>
#include <array>
#include <climits>
using namespace std;

int board[8][8] = {0};
const int SIZE = 8;

int accessibility[SIZE][SIZE];

int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};


bool isSafe(int r, int c) {
    return (r >= 0 && r < SIZE && c >= 0  && c < SIZE && board[r][c] == 0);
}

void updateAccessibility(int r, int c) {
    for (int i{0}; i < 8; ++i) {
        int nextRow = r + vertical[i]; 
        int nextColumn  = c + horizontal[i];
        // то есть 2 + 3 = 5
        if (nextRow >= 0 && nextRow <= SIZE && nextColumn >= 0 && nextColumn <= SIZE && board[nextRow][nextColumn] == 0) {
            accessibility[nextRow][nextColumn]--; 
        } 
    }
}

int nextMove(int &r, int &c) {
    int minAccessibility = INT_MAX;
    int bestMove = -1;
    for (int i{0}; i < 8; ++i) {
        int nextRow = r + vertical[i];
        int nextColumn = c + horizontal[i];
        if (isSafe(nextRow, nextColumn) && accessibility[nextRow][nextColumn] < minAccessibility) {
            minAccessibility = accessibility[nextRow][nextColumn];
            bestMove = i;
        }
    }
    return bestMove;
}

bool SolveKnightTour(int r, int c, int moveCount) {

    board[r][c] = moveCount;

    updateAccessibility(r,c); 

    if (moveCount == SIZE * SIZE) {
        return true;
    }

    int move = nextMove(r,c);
    if (move == -1) {
        return false;
    }

    int nextRow = r + vertical[move];
    int nextColumn = c + horizontal[move];

    if (SolveKnightTour(nextRow, nextColumn, moveCount + 1)) {
        return true;
    }

    board[r][c] = 0;

    return false;
}

int countMoves(int r, int c) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nr = r + vertical[i];
        int nc = c + horizontal[i];
        if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE)
            count++;
    }
    return count;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <  SIZE; j++) {
            board[i][j] = 0;    
            accessibility[i][j] = countMoves(i, j);
        }
    }

    if (SolveKnightTour(0, 0, 1)) {
        cout << "Decision have founded!\n";
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << board[i][j] << "\t";  
            }
            cout << endl;
        }
    } else {
        cout << "Decision have not founded!" << endl;
    }

    return 0;
}
