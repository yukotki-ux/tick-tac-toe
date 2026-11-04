#ifndef GRID_H
#define GRID_H

#include <iostream>

class grid {
    private:
        char board[3][3];

    public:
        grid() {
            createGrid();
        }

        void createGrid() {
            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    board[row][column] = ' ';
                }
            }
        }

        void showBoard() const {
            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    char cell = board[row][column];
                    if (cell == ' ') {
                        cell = static_cast<char>('1' + row * 3 + column);
                    }
                    std::cout << ' ' << cell << ' ';
                    if (column < 2) {
                        std::cout << '|';
                    }
                }
                std::cout << '\n';
                if (row < 2) {
                    std::cout << "---+---+---\n";
                }
            }
        }

        bool isEmpty() const {
            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    if (board[row][column] != ' ') {
                        return false;
                    }
                }
            }
            return true;
        }

        bool isEmpty(int row, int column) const {
            return row >= 0 && row < 3 && column >= 0 && column < 3
                && board[row][column] == ' ';
        }

        bool isFilled() const {
            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    if (board[row][column] == ' ') {
                        return false;
                    }
                }
            }
            return true;
        }

        bool checkWin() const {
            for (int index = 0; index < 3; ++index) {
                if (board[index][0] != ' '
                    && board[index][0] == board[index][1]
                    && board[index][1] == board[index][2]) {
                    return true;
                }
                if (board[0][index] != ' '
                    && board[0][index] == board[1][index]
                    && board[1][index] == board[2][index]) {
                    return true;
                }
            }

            return (board[0][0] != ' '
                    && board[0][0] == board[1][1]
                    && board[1][1] == board[2][2])
                || (board[0][2] != ' '
                    && board[0][2] == board[1][1]
                    && board[1][1] == board[2][0]);
        }

        bool placeMark(int position, char mark) {
            if (position < 1 || position > 9) {
                return false;
            }

            const int row = (position - 1) / 3;
            const int column = (position - 1) % 3;
            if (!isEmpty(row, column)) {
                return false;
            }

            board[row][column] = mark;
            return true;
        }
};

#endif