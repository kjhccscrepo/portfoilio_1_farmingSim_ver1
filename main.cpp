#include <iostream>
#include "src/ansi_clear.hpp"

int main() {

    bool gameOver = false;


    std::string userInput;

    while (!gameOver) {
        std::cout << "gameboard!!!!" << "\n";
        ansi_clear();
        std::getline(std::cin, userInput);
        if (userInput == "exit") {     // quit game
            gameOver = true;
        } else if (userInput == "a") { // move left

        } else if (userInput == "d") { // move right

        } else if (userInput == "w") { // move up

        } else if (userInput == "s") { // move down

        } else if (userInput == "p") { // plant something

        } else if (userInput == "o") { // harvest something

        } else if (userInput == "i") { // open inventory

        }
        // update the LOG
        // make a row on the bottom called like "information": blahblahblah
    }
    std::cout << "thank you for playing!";
    return 0;
}
