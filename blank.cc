#include "blank.h"
#include <iostream>

Blank::Blank(Decorator *component, std::vector<std::pair<int, int>> coords, char symbol, int generatedLevel):
    Decorator{component, generatedLevel, coords, symbol} {}

char Blank::charAt(int x, int y) const {
    return ' ';
}
