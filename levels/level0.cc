#include "level0.h"

Level0::Level0(std::string filename) : Level{0} {
    if (input.is_open()) {
        input.close();
    }
    input.open(filename);
}

Level0::~Level0() {
    if (input.is_open()) {
        input.close();
    }
}

char Level0::nextBlock() {
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
