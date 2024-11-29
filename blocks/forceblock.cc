#include "forceblock.h"
#include <iostream>

ForceBlock::ForceBlock(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}
