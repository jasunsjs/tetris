#ifndef DECORATOR_H
#define DECORATOR_H

#include <utility>
#include <vector>
#include "board.h"

enum class RotationState {
    Default,      // Default orientation
    Rotated90,    // Assume clockwise be default
    Rotated180,
    Rotated270
};

class Decorator : public Board {
  protected:
    Decorator *component;
    std::vector<std::pair<int, int>> coords; // Vector of 4 pairs representing each block cell's position
    char symbol;
    int generatedLevel;
    bool dropped = false;
    RotationState state = RotationState::Default;
    std::pair<int, int> bottomLeft = {0, 3}; // Anchor point for rotations, default set
  public:
    Decorator(Decorator *component, int generatedLevel, std::vector<std::pair<int, int>> coords, char symbol);
    virtual ~Decorator();

    // Universal movement across all blocks
    void moveLeft();
    void moveRight();
    void moveDown();
    void unconditionalMoveDown(int row);
    void drop();
    void removeTile(int x, int y);
    bool isEmpty();
    bool canMoveDown();
    void setComponentNull();
    Decorator* blockAt(int x, int y);
    bool hasOverlap() const;

    // Block specific, virtual
    virtual void rotateClockwise() {}
    virtual void rotateCounterClockwise() {}
    virtual char charAt(int x, int y) const;
    
    // Helper methods for movement and rotations
    bool isValid(const std::vector<std::pair<int, int>> &coordinates);
    void transpose(std::vector<std::pair<int, int>> &coordinates, 
                   std::pair<int, int> &anchor) const; // Swap x and y values
    void reposition(std::vector<std::pair<int, int>> &coordinates,
                    std::pair<int, int> &anchor) const; // Translate block back to designated anchor point

    // Getters
    Decorator* getComponent() const;
    int getGeneratedLevel() const;
};

#endif
