#ifndef OPPONENT_H
#define OPPONENT_H

#include <cstdlib>
#include "grid.h"

class opponent {
    private:
        char mark;

    public:
        explicit opponent(char opponentMark) : mark(opponentMark) {}

        char getMark() const {
            return mark;
        }

        int chooseMove(const grid& board) const {
            int availablePositions[9];
            int availableCount = 0;

            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    if (board.isEmpty(row, column)) {
                        availablePositions[availableCount] = row * 3 + column + 1;
                        ++availableCount;
                    }
                }
            }

            if (availableCount == 0) {
                return -1;
            }

            return availablePositions[std::rand() % availableCount];
        }
};

#endif