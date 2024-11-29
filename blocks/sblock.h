#ifndef SBLOCK_H
#define SBLOCK_H

#include "decorator.h"

class SBlock: public Decorator {
  public:
    SBlock(Decorator *component, 
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{2, 2}, {1, 2}, {1, 3}, {0, 3}},
           char symbol = 'S');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

#endif
