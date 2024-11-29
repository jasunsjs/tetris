#ifndef OBSERVER_H
#define OBSERVER_H
#include "board.h"
#include <unordered_map>
#include <string>
#include <vector>

class Observer {
  protected:
    Board *s1, *s2;
    int width;
    int height; 
    const std::unordered_map<char, std::vector<std::string>> blockShapes = {
        {'I', {"IIII ", "     "}},          // I-block
        {'J', {" J   ", " JJJ "}},    // J-block
        {'L', {"  L  ", "LLL  "}},    // L-block
        {'O', {"  OO ", "  OO "}},      // O-block
        {'S', {"  SS ", " SS  "}},    // S-block
        {'Z', {" ZZ  ", "  ZZ "}},    // Z-block
        {'T', {" TTT ", "  T  "}}     // T-block
    };
    Observer(Board* b1, Board* b2, int width, int height)
    : s1(b1), s2(b2), width(width), height(height) {}
  public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

#endif
