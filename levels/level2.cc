#include "level2.h"
#include <cstdlib>

Level2::Level2() : Level{2} {
    blockWeights = {
        {'I', 1},
        {'J', 1},
        {'L', 1},
        {'O', 1},
        {'S', 1},
        {'Z', 1},
        {'T', 1}
    };
    totalWeight = 7;
}

char Level2::nextBlock() {
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
