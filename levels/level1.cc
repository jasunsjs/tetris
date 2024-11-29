#include "level1.h"
#include <cstdlib>

Level1::Level1() : Level{1} {
    blockWeights = {
        {'I', 2},
        {'J', 2},
        {'L', 2},
        {'O', 2},
        {'S', 1},
        {'Z', 1},
        {'T', 2}
    };
    totalWeight = 12;
}

char Level1::nextBlock() {
    // Generate a random number from 0 to totalWeight - 1
    int random = rand() % totalWeight;
    // Increment sum by weights to select block according to random number
    int currSum = 0;
    for (const auto& entry : blockWeights) {
        currSum += entry.second;
        if (random < currSum) {
            return entry.first;
        }
    }
    // Invalid weights, return default
    return 'I';
}
