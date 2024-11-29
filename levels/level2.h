#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"
#include <vector>
#include <utility>

class Level2 : public Level {
    std::vector<std::pair<char, int>> blockWeights;
    int totalWeight;
  public:
    Level2();
    char nextBlock() override;
};

#endif
