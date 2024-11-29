#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "window.h"
#include <iostream>


class TextObserver : public Observer {
    std::ostream& out;

    public:
        TextObserver(Board* b1, Board* b2, int w, int h, std::ostream& o);
        ~TextObserver() override = default;

        void update() override;

};

#endif
