#include "player.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Player::Player(const std::string& name, Board* b, const std::string& filename, int startLevel)
    : playerName{name},
      inputFilename{filename},
      board{b} {
    level = new Level0{inputFilename};
    setLevel(startLevel);
}

Player::~Player() {
    delete level;
}

void Player::setEffect(Effect e) {
    currEffect = e;
}

void Player::setLevel(int levelNum) {
    switch (levelNum) {
        case 0:
            delete level;
            level = new Level0{inputFilename};
            break;
        case 1:
            delete level;
            level = new Level1();
            break;
        case 2:
            delete level;
            level = new Level2();
            break;
        case 3:
            delete level;
            level = new Level3();
            break;
        case 4:
            delete level;
            level = new Level4();
            break;
    }
}

std::string Player::getName() const {
    return playerName;
}

Level* Player::getLevel() const {
    return level;
}

int Player::getScore() const {
    return score;
}

Board* Player::getBoard() const {
    return board;
}

Effect Player::getEffect() const {
    return currEffect;
}

void Player::addScore(int increase) {
    score += increase;
}

void Player::applyEffect() {
    return;
}
