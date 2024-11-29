#include "level3.h"
#include <cstdlib>

Level3::Level3() : Level{3} {
    blockWeights = {
        {'I', 1},
        {'J', 1},
        {'L', 1},
        {'O', 1},
        {'S', 2},
        {'Z', 2},
        {'T', 1}
    };
    totalWeight = 9;
}

char Level3::nextBlock() {
    if (!random) {
        char block;
        if (input >> block) {
            return block;
        }
        // Reached end of file, start from beginning
        input.clear();
        input.seekg(0);
        if (input >> block) {
            return block;
        }
        // File is empty or invalid, return default
        return 'I';
    }
    // Generate a random number from 0 to totalWeight - 1
    int randomNum = rand() % totalWeight;
    // Increment sum by weights to select block according to random number
    int currSum = 0;
    for (const auto& entry : blockWeights) {
        currSum += entry.second;
        if (randomNum < currSum) {
            return entry.first;
        }
    }
    // Invalid weights, return default
    return 'I';
}

void Level3::setRandom(bool randBool) {
    random = randBool;
}

void Level3::setSequenceFile(std::string filename) {
    if (input.is_open()) {
        input.close();
    }
    input.open(filename);
}
