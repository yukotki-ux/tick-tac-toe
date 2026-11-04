#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
    private:
        std::string name;
        char mark;

    public:
        player(const std::string& playerName, char playerMark)
            : name(playerName), mark(playerMark) {}

        std::string getName() const {
            return name;
        }

        char getMark() const {
            return mark;
        }
};

#endif