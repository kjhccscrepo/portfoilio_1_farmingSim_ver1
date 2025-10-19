#include <iostream>
#include "src/ansi_clear.hpp"
#include "src/plants.hpp"
#include "src/items.hpp"
#include "src/seeds.hpp"

int main() {

    // all this makes a carrot, then puts it as available options in the player inventory.
    //
    // I want to try and find a way to automate at least, some of it, without introducing too much tight coupling.
    std::vector<char> states_carrot = {'v','V'};
    plantData data_Carrot(2, "carrot", states_carrot);
    lootTable selfDrop_Carrot(1, 1, 100, 0);
    lootTable seedsDrop_Carrot(1, 2, 50, 0);
    plants plant_Carrot(data_Carrot, selfDrop_Carrot, seedsDrop_Carrot);
    plants *carrot_ptr = &plant_Carrot;
    seeds seeds_Carrot("carrot", carrot_ptr);
    std::vector<items> inventory_player;
    inventory_player.push_back(seeds_Carrot);
    inventory_player.push_back(plant_Carrot.returnProduce());



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
