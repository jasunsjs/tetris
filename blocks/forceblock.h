#ifndef FORCEBLOCK_H
#define FORCEBLOCK_H

#include "decorator.h"


class ForceBlock: public Decorator {
  public:
    ForceBlock(Decorator *component,
               int generatedLevel,
               std::vector<std::pair<int, int>> coords = {{5, 3}},
               char symbol = '*');
};

#endif
