#include "jblock.h"
#include "blank.h"
#include <iostream>

JBlock::JBlock(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void JBlock::rotateClockwise() {

    std::vector<std::pair<int, int>> newCoords = coords;
    std::pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default || state == RotationState::Rotated180) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[2].first = newCoords[0].first;
        newCoords[3].first = newCoords[0].first;
        swap(newCoords[0], newCoords[1]);
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;

        newCoords[0].first = newCoords[3].first;
        swap(newCoords[1], newCoords[3]);
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;
        state = static_cast<RotationState>((static_cast<int>(state) + 1) % 4); // Change state
    }
}

void JBlock::rotateCounterClockwise() {
    for (int i = 0; i < 3; ++i) {
        rotateClockwise();
    }
}
