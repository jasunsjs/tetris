#include "zblock.h"

ZBlock::ZBlock(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void ZBlock::rotateClockwise() {
    std::vector<std::pair<int, int>> newCoords = coords;
    std::pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[0].first = newCoords[2].first;
        newCoords[3].first = newCoords[1].first;
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;

        newCoords[0].second = newCoords[1].second;
        newCoords[3].second = newCoords[2].second;
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;

        // Change state
        if (state == RotationState::Default) {
            state = RotationState::Rotated90;
        } else {
            state = RotationState::Default;
        }
    }
}

void ZBlock::rotateCounterClockwise() {
    rotateClockwise();
}
