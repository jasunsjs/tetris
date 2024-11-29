#ifndef LEVEL_H
#define LEVEL_H

class Level {
    int levelNum;
  public:
    Level(int num) : levelNum{num} {}
    virtual ~Level() = default;
    virtual char nextBlock() = 0;
    int getLevelNum() const { return levelNum; }
};

#endif
