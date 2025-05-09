#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board {
private:
    vector<vector<char>> grid;
    int rows;
    int cols;
    int filledCells;

public:
    Board(int r = 3, int c = 3) : rows(r), cols(c), filledCells(0) {
        grid.resize(rows, vector<char>(cols, ' '));
    }

    void drawBoard() const {
        cout << string(cols * 4 + 1, '-') << endl;
        for (int i = 0; i < rows; i++) {
            cout << "| ";
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " | ";
            }
            cout << endl << string(cols * 4 + 1, '-') << endl;
        }
    }

    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == ' ');
    }

    void makeMove(int row, int col, char symbol) {
        if (isValidMove(row, col)) {
            grid[row][col] = symbol;
            filledCells++;
        }
    }

    bool checkWin(char symbol) const {
        for (int i = 0; i < rows; i++) {
            bool win = true;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        for (int j = 0; j < cols; j++) {
            bool win = true;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        if (rows == cols) {
            bool win = true;
            for (int i = 0; i < rows; i++) {
                if (grid[i][i] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;

            win = true;
            for (int i = 0; i < rows; i++) {
                if (grid[i][rows - i - 1] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        return false;
    }

    bool isFull() const {
        return filledCells == rows * cols;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

class TicTacToe {
private:
    Board board;
    string playerNames[2];
    char playerSymbols[2];
    int currentPlayerIndex;

public:
    TicTacToe(int rows = 3, int cols = 3) : board(rows, cols), currentPlayerIndex(0) {
        playerSymbols[0] = 'X';
        playerSymbols[1] = 'O';
        playerNames[0] = "Player X";
        playerNames[1] = "Player O";
    }

    void switchTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    void play() {
        int row, col;
        cout << "Tic-Tac-Toe" << endl;

        while (!board.isFull()) {
            board.drawBoard();
            cout << playerNames[currentPlayerIndex] << " (" << playerSymbols[currentPlayerIndex]
                 << "), enter row (1 through " << board.getRows() << ") and column (1 through " << board.getCols() << "): ";
            cin >> row >> col;
            row--; col--;

            if (board.isValidMove(row, col)) {
                board.makeMove(row, col, playerSymbols[currentPlayerIndex]);
                if (board.checkWin(playerSymbols[currentPlayerIndex])) {
                    board.drawBoard();
                    cout << playerNames[currentPlayerIndex] << " wins!" << endl;
                    return;
                }
                switchTurn();
            } else {
                cout << "Invalid, try again." << endl;
            }
        }

        board.drawBoard();
        cout << "It's a draw!" << endl;
    }
};

int main() {
    int p;
    int rows, cols;
    cout << "Enter # of rows for the board: ";
    cin >> rows;
    cout << "Enter # of columns for the board: ";
    cin >> cols;

    TicTacToe game(rows, cols);
    game.play();
    cout << "Game Over!" << endl;
    cout << "Thanks for playing." << endl;
    cout << "Play again? Y or N" << endl;
    cin >> p;
    if (p == 'y' || p == 'Y') {
        TicTacToe game(rows, cols);
        game.play(); } 
        else {
        cout << "Goodbye!" << endl;
    }
    return 0;
}