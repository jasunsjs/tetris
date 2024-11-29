#include "decorator.h"
#include <iostream>


// ** Decorator Constructor and Destructor **
Decorator::Decorator(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol):
    component{component}, 
    generatedLevel{generatedLevel},
    coords{coords}, 
    symbol{symbol} {}

Decorator::~Decorator() {
    if (component) {
        delete component;
    }
}

// ** Universal Block Movement **
void Decorator::moveLeft() {
    std::vector<std::pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].first--;
    }

    if (isValid(newCoords)) {
        coords = newCoords;
        bottomLeft.first--;
    }
}

void Decorator::moveRight() {
    std::vector<std::pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].first++;
    }

    if (isValid(newCoords)) {
        
        coords = newCoords;
        bottomLeft.first++;
    }
}

void Decorator::moveDown() {
    std::vector<std::pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].second++;
    }
    if (isValid(newCoords)) {
        coords = newCoords;
        bottomLeft.second++;
    }
}

void Decorator::unconditionalMoveDown(int row) {
    for (int i = 0; i < coords.size(); ++i) {
        if (coords[i].second == row) {
            coords[i].second++;
        }
    }
}

void Decorator::drop() {
    std::vector<std::pair<int, int>> newCoords = coords;
    std::pair<int, int> newBottomLeft = bottomLeft;

    // Continuously move down until invalid position
    while (isValid(newCoords)) {
        for (int i = 0; i < newCoords.size(); ++i) {
            newCoords[i].second++;
        }
        newBottomLeft.second++;
    }

    // Go back by 1 unit
    for (int i = 0; i < coords.size(); ++i) {
        newCoords[i].second--;
    }
    newBottomLeft.second--;

    // Assign
    coords = newCoords;
    bottomLeft = newBottomLeft;
    dropped = true;
}

void Decorator::removeTile(int x, int y) {
    for (int i = 0; i < coords.size(); ++i) {
        if (coords[i].first == x && coords[i].second == y) {
            coords.erase(coords.begin() + i);
        }
    }
}

// ** Helper methods for movement and rotations **
bool Decorator::isValid(const std::vector<std::pair<int, int>> &coordinates) {
    for (std::pair<int, int> p : coordinates) {
        // Check if out of bounds and if position is already occupied
        if (p.first < 0 || p.first >= component->getCols() || p.second < 0 || p.second >= component->getRows() + 3 ||
            (blockAt(p.first, p.second) && blockAt(p.first, p.second)->dropped)) {
            return false;
        }
    }
    return true;
}

Decorator* Decorator::getComponent() const { return component; }

bool Decorator::isEmpty() { return coords.size() == 0; }

bool Decorator::canMoveDown() {
    std::vector<std::pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].second++;
    }
    return isValid(newCoords);
}

void Decorator::setComponentNull() { component = nullptr; }

int Decorator::getGeneratedLevel() const { return generatedLevel; }

bool Decorator::hasOverlap() const {
    for (auto coord : coords) {
        if (component->charAt(coord.first, coord.second) != ' ') {
            return true;
        }
    }
    return false;
}

char Decorator::charAt(int x, int y) const {
    // Check if within block
    for (std::pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return symbol;
        }
    }
    return component->charAt(x, y);
}

Decorator* Decorator::blockAt(int x, int y) {
    for (std::pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return this;
        }
    }
    if (!component) {
        return nullptr;
    }
    return component->blockAt(x, y);
}

void Decorator::transpose(std::vector<std::pair<int, int>> &coordinates, std::pair<int, int> &anchor) const {
    for (int i = 0; i < coordinates.size(); ++i) {
        std::swap(coordinates[i].first, coordinates[i].second);
    }
    std::swap(anchor.first, anchor.second);
}

void Decorator::reposition(std::vector<std::pair<int, int>> &coordinates, std::pair<int, int> &anchor) const {
    // Calculate x and y translation factors
    int xDiff = bottomLeft.first - anchor.first;
    int yDiff = bottomLeft.second - anchor.second;

    for (int i = 0; i < coordinates.size(); ++i) {
        coordinates[i].first += xDiff;
        coordinates[i].second += yDiff;
    }
    anchor = bottomLeft;
}
