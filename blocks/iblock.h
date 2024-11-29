#ifndef IBLOCK_H
#define IBLOCK_H

#include "decorator.h"

class IBlock: public Decorator {
  public:
    IBlock(Decorator *component,
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{0, 3}, {1, 3}, {2, 3}, {3, 3}}, 
           char symbol = 'I');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

#endif
