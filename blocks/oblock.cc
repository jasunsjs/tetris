#include "oblock.h"


OBlock::OBlock(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void OBlock::rotateClockwise() {
    return;
}

void OBlock::rotateCounterClockwise() {
    return;
}
