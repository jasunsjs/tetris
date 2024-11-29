#ifndef BLANK_H
#define BLANK_H

#include "decorator.h"

class Blank: public Decorator {
  public:
    Blank(Decorator *component = nullptr, 
           std::vector<std::pair<int, int>> coords = {}, 
           char symbol = ' ', 
           int generatedLevel = 0);
    char charAt(int x, int y) const override;
};

#endif
