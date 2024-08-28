#include <iostream>
using namespace std;
void drawBoard(char board[3][3]);
bool makeMove(char board[3][3], int move, char player);
bool checkWinner(char board[3][3], char player);
bool isBoardFull(char board[3][3]);
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int move;
    bool gameWon = false;
	cout << "Welcome to the Game\n";
    cout << "\t\t\"Tic-Tac-Toe\"!\n";
    while (true) {
        drawBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        if (makeMove(board, move, currentPlayer)) {
            if (checkWinner(board, currentPlayer)) {
                drawBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
            } else if (isBoardFull(board)) {
                drawBoard(board);
                cout << "The game is a draw!\n";
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Please try again.\n";
        }
        if (gameWon) {
            char playAgain;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y') {
                // Reset the board and start a new game
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        board[i][j] = ' ';
                    }
                }
                currentPlayer = 'X';
                gameWon = false;
            } else {
                break;
            }
        }
    }
    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
void drawBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}
bool makeMove(char board[3][3], int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (move >= 1 && move <= 9 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
bool checkWinner(char board[3][3], char player) {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
