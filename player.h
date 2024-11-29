#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "effect.h"
#include "board.h"
#include "level.h"

class Player {
    std::string playerName, inputFilename;
    Effect currEffect = Effect::NONE;
    int score = 0;
    Board* board;
    Level* level;
  public:
    Player(const std::string& name, Board* b, const std::string& filename, int startLevel);
    ~Player();
    
    void addScore(int increase);
    void applyEffect();

    // Getters and setters
    std::string getName() const;
    Level* getLevel() const;
    int getScore() const;
    Board* getBoard() const;
    Effect getEffect() const;

    void setEffect(Effect e);
    void setLevel(int levelNum);
};

#endif
