#include "player.h"
#include "board.h"
#include "controller.h"
#include "decorator.h"
#include "observer.h"
#include "textobserver.h"
#include "graphicsobserver.h"
#include "blank.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

const int BOARD_ROWS = 15;
const int BOARD_COLS = 11;

void startup(Board*& board1, Board*& board2, Player*& p1, Player*& p2, TextObserver*& to, GraphicsObserver*& go, Controller*& ctrl,
             bool textOnly, std::string scriptFile1, std::string scriptFile2, int startLevel) {
    // Set up players and controller
    board1 = new Board{BOARD_ROWS, BOARD_COLS, new Blank()};
    board2 = new Board{BOARD_ROWS, BOARD_COLS, new Blank()};
    std::string name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name);
    p1 = new Player{name, board1, scriptFile1, startLevel};
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name);
    p2 = new Player{name, board2, scriptFile2, startLevel};
    board1->setPlayer(p1);
    board2->setPlayer(p2);

    // Set up observers
    to = new TextObserver{board1, board2, BOARD_COLS, BOARD_ROWS, std::cout};
    go = nullptr;
    if (!textOnly) {
        go = new GraphicsObserver{board1, board2, BOARD_COLS, BOARD_ROWS};
    }

    ctrl = new Controller{p1, p2};
}

int main(int argc, char* argv[]) {
    std::string scriptFile1 = "sequence1.txt";
    std::string scriptFile2 = "sequence2.txt";
    int highScore = 0;
    std::string highScoreName;
    bool textOnly = false;
    int seed = 0;
    int startLevel = 0;

    // Parse command line args
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-text") {
            textOnly = true;
        } else if (arg == "-seed") {
            // Convert string to int
            std::istringstream iss{argv[++i]};
            iss >> seed;
        } else if (arg == "-scriptfile1") {
            scriptFile1 = argv[++i];
        } else if (arg == "-scriptfile2") {
            scriptFile2 = argv[++i];
        } else if (arg == "-startlevel") {
            // Convert string to int
            std::istringstream iss{argv[++i]};
            iss >> startLevel;
        }
    }
    // Set seed
    srand(seed);

    // Initialize and construct all objects
    Board* board1 = nullptr;
    Board* board2 = nullptr;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    TextObserver* to = nullptr;
    GraphicsObserver* go = nullptr;
    Controller* ctrl = nullptr;
    startup(board1, board2, p1, p2, to, go, ctrl, textOnly,
            scriptFile1, scriptFile2, startLevel);

    bool stopGame = false;

    // Main game loop
    while (!stopGame) {
        // Startup sequence
        ctrl->generateNextBlock(p1);
        ctrl->generateCurrBlock(p1);
        ctrl->generateNextBlock(p2);
        ctrl->generateCurrBlock(p2);
        ctrl->render();

        // Current game loop
        while (ctrl->takeCommand()) {}
        
        // EOF check
        if (std::cin.eof()) {
            break;
        }

        // Game over sequence
        int p1Score = p1->getScore();
        int p2Score = p2->getScore();
        std::cout << "Game Over!" << std::endl;
        std::cout << "Player " << ctrl->getWinner() << " wins!" << std::endl;
        std::cout << "Player " << p1->getName() << " score: " << p1Score << std::endl;
        std::cout << "Player " << p2->getName() << " score: " << p2Score << std::endl;

        // Set and output high scores
        if (p1Score >= highScore || p2Score >= highScore) {
            if (p1Score >= p2Score) {
                highScore = p1Score;
                highScoreName = p1->getName();
            } else {
                highScore = p2Score;
                highScoreName = p2->getName();
            }
        }
        std::cout << "High Score: " << highScore << " by " << highScoreName << std::endl;

        // Restart sequence
        while (true) {
            std::cout << "Play again? (Y/N):" << std::endl;
            std::string cmd;
            std::cin >> cmd;
            std::cin.ignore();
            if (cmd == "Y" || cmd == "y") {
                delete board1;
                delete board2;
                delete p1;
                delete p2;
                delete to;
                delete go;
                delete ctrl;
                startup(board1, board2, p1, p2, to, go, ctrl, textOnly,
                        scriptFile1, scriptFile2, startLevel);
                break;
            } else if (cmd == "N" || cmd == "n" || std::cin.eof()) {
                stopGame = true;
                break;
            }
        }
    }

    // Delete observers
    delete to;
    delete go;

    // Delete players
    delete p1;
    delete p2;

    // Delete boards
    delete board1;
    delete board2;

    // Delete controller
    delete ctrl;
}
