#include "graphicsobserver.h"

GraphicsObserver::GraphicsObserver(Board* b1, Board* b2, int w, int h)
: Observer(b1, b2, w, h), window(1000, 650), board1Cache(h+3, std::vector<char>(w, '-')), 
 board2Cache(h+3, std::vector<char>(w, '-')) {
    s1->attach(this);
    s2->attach(this);
}

int GraphicsObserver::mapBlockToColor(char state){
        int color;
        //determines color based on the type of block we encounter
        if(state == 'I'){
            color = XWindow::Red;
        } else if (state == 'T') {
            color = XWindow::Green;
        } else if (state == 'Z') {
            color = XWindow::Blue;
        } else if (state == 'O') {
            color = XWindow::Yellow;
        } else if (state == 'L') {
            color = XWindow::Magenta;
        } else if (state == 'J') {
            color = XWindow::Orange;
        } else if (state == 'S') {  
            color = XWindow::Cyan;
        } else if (state == ' ') {
            color = XWindow::Black;
        } else if (state == '*') {
            color = XWindow::Brown;
        } else {
            color = XWindow::White;
        }

        return color;
}

void GraphicsObserver::update() {
    const int board1OffsetX = 4 * pixelSize;
    const int board2OffsetX = 20 * pixelSize;
    const int uiHeight = 100;

    window.fillRectangle(board1OffsetX - 10, 0, 600, 100, XWindow::White);

    // Draw Player 1 UI
    window.drawString(board1OffsetX + 10, 20, "Player 1: " + s1->getPlayerName());
    window.drawString(board1OffsetX + 10, 40, "Level: " + std::to_string(s1->getLevelNum()));
    window.drawString(board1OffsetX + 10, 60, "Score: " + std::to_string(s1->getScore()));

    // Draw Player 2 UI
    window.drawString(board2OffsetX + 10, 20, "Player 2: " + s2->getPlayerName());
    window.drawString(board2OffsetX + 10, 40, "Level: " + std::to_string(s2->getLevelNum()));
    window.drawString(board2OffsetX + 10, 60, "Score: " + std::to_string(s2->getScore()));

    // Draw Boards
    for (int y = 0; y < height + 3; y++) {
        for (int x = 0; x < width; x++) {
            // Board 1
            char state1 = s1->getState(x, y);
            if (state1 != board1Cache[y][x]) {
                int color1 = mapBlockToColor(state1);
                int x1 = board1OffsetX + x * pixelSize;
                int y1 = uiHeight + y * pixelSize;
                window.fillRectangle(x1, y1, pixelSize, pixelSize, color1);
                if(state1 == '?') window.drawString(x1 + 7, y1  + 12 , "?");
                board1Cache[y][x] = state1;
            }

            // Board 2
            char state2 = s2->getState(x, y);
            if (state2 != board2Cache[y][x]) {
                int color2 = mapBlockToColor(state2);
                int x2 = board2OffsetX + x * pixelSize;
                int y2 = uiHeight + y * pixelSize;
                window.fillRectangle(x2, y2, pixelSize, pixelSize, color2);
                if(state2 == '?') window.drawString(x2 + 7, y2 + 12, "?");
                board2Cache[y][x] = state2;
            }
        }
    }

    int nextBlockOffsetY = uiHeight + (height+3) * pixelSize + 20;

    // Draw Next Block for Player 1
    window.drawString(board1OffsetX + 10, nextBlockOffsetY, "Next Block:");
    char nextBlock1 = s1->getNextBlock();
    auto it1 = blockShapes.find(nextBlock1);
    if (it1 != blockShapes.end()) {
        const std::vector<std::string>& shape = it1->second;
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];
                int x = board1OffsetX + 10 + j * pixelSize;
                int y = nextBlockOffsetY + 20 + i * pixelSize;
                if (cell != ' ') {
                    int blockColor = mapBlockToColor(cell);
                    window.fillRectangle(x, y, pixelSize, pixelSize, blockColor);
                } else {
                    window.fillRectangle(x, y, pixelSize, pixelSize, XWindow::White);
                }
            }
        }
    }

    // Draw Next Block for Player 2
    window.drawString(board2OffsetX + 10, nextBlockOffsetY, "Next Block:");
    char nextBlock2 = s2->getNextBlock();
    auto it2 = blockShapes.find(nextBlock2);
    if (it2 != blockShapes.end()) {
        const std::vector<std::string>& shape = it2->second;
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];
                int x = board2OffsetX + 10 + j * pixelSize;
                int y = nextBlockOffsetY + 20 + i * pixelSize;
                if (cell != ' ') {
                    int blockColor = mapBlockToColor(cell);
                    window.fillRectangle(x, y, pixelSize, pixelSize, blockColor);
                } else {
                    window.fillRectangle(x, y, pixelSize, pixelSize, XWindow::White);
                }
            }
        }
    }
}
