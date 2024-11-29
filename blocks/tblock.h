#ifndef TBLOCK_H
#define TBLOCK_H

#include "decorator.h"

class TBlock: public Decorator {
  public:
    TBlock(Decorator *component,
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{0, 2}, {1, 2}, {2, 2}, {1, 3}},
           char symbol = 'T');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

#endif
