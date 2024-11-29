#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"
#include <vector>
#include <utility>

class Level1 : public Level {
    std::vector<std::pair<char, int>> blockWeights;
    int totalWeight;
  public:
    Level1();
    char nextBlock() override;
};

#endif
