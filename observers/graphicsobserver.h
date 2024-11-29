#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "window.h"

class GraphicsObserver : public Observer {
    XWindow window;
    const int pixelSize = 20;
    std::vector<std::vector<char>> board1Cache;
    std::vector<std::vector<char>> board2Cache;

    public:
        GraphicsObserver(Board* b1, Board* b2, int w, int h);
        ~GraphicsObserver() override = default;
        int mapBlockToColor(char state);
        void update() override;
};

#endif
