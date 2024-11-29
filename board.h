#ifndef BOARD_H
#define BOARD_H
#include "subject.h"
#include <string>

class Decorator; // Forward declaration
class Player; // Forward declaration

class Board : public Subject {
    int rows = 15;
    int cols = 11;
    Decorator* picture;
    Player* player = nullptr;
    char nextBlock;
    int nextBlockLevelNum;
  public:
    Board();
    Board(int row, int col, Decorator *picture);
    ~Board();

    void removeLayer(int row);
    int checkBoard();
    void replaceBlock(char block);
    bool moveBlock(int rows, int cols);
    void rotateBlock(bool clockwise);
    void dropBlock();

    // Getters and setters
    char getState(int x, int y) const override;
    int getRows() const;
    int getCols() const;
    int getScore() const;
    int getLevelNum() const;
    int getBlockLevel() const;
    char getNextBlock() const;
    int getNextBlockLevelNum() const;
    std::string getPlayerName() const;

    void setPlayer(Player* p);
    bool setBlock(char block, int level);
    void setNextBlock(char block, int level);
};

#endif
