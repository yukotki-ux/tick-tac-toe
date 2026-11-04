#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <limits>
#include "opponent.h"
#include "player.h"

class game {
    private:
        grid board;
        player human;
        opponent computer;
        bool finished;
        char winner;
        char lastMark;

        int getHumanMove() {
            while (true) {
                int position;
                std::cout << human.getName() << " (" << human.getMark()
                          << "), choose a square (1-9): ";

                if (!(std::cin >> position)) {
                    if (std::cin.eof()) {
                        finished = true;
                        return -1;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Please enter a number from 1 to 9.\n";
                    continue;
                }

                if (position < 1 || position > 9) {
                    std::cout << "Choose a square from 1 to 9.\n";
                    continue;
                }

                if (!board.isEmpty((position - 1) / 3, (position - 1) % 3)) {
                    std::cout << "That square is already occupied.\n";
                    continue;
                }

                return position;
            }
        }

    public:
        game()
            : human("Player", 'X'), computer('O'), finished(false),
              winner(' '), lastMark(' ') {}

        void gameStart() {
            std::cout << "Tic-Tac-Toe\nYou are X; the computer is O.\n";

            while (!finished) {
                board.showBoard();
                const int humanPosition = getHumanMove();
                if (finished) {
                    break;
                }

                board.placeMark(humanPosition, human.getMark());
                lastMark = human.getMark();
                checkWinner();
                if (finished) {
                    break;
                }
                if (board.isFilled()) {
                    finished = true;
                    break;
                }

                const int computerPosition = computer.chooseMove(board);
                board.placeMark(computerPosition, computer.getMark());
                std::cout << "Computer chooses square " << computerPosition << ".\n";
                lastMark = computer.getMark();
                checkWinner();
                if (!finished && board.isFilled()) {
                    finished = true;
                }
            }

            gameEnd();
        }

        void gameEnd() {
            board.showBoard();
            if (winner == human.getMark()) {
                std::cout << "You win!\n";
            } else if (winner == computer.getMark()) {
                std::cout << "The computer wins.\n";
            } else if (board.isFilled()) {
                std::cout << "It's a draw.\n";
            } else {
                std::cout << "Game ended.\n";
            }
        }

        void checkWinner() {
            if (board.checkWin()) {
                winner = lastMark;
                finished = true;
            }
        }
};

#endif