//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_GAME_PRINTER_HPP
#define FARMING_SIMULATOR_V2C_GAME_PRINTER_HPP

#include <sstream>
#include "farm_printer.hpp"
#include "../interactions/inventory.hpp"

class GamePrinter {
    FarmPrinter *myFarmPrinted;
    inventory *myInventoryPointer;
    std::stringstream legend_print;
    std::string legend;
    std::stringstream inventory_print;
    std::string inventory_p;
    std::stringstream info_print;
    std::string info;
    std::stringstream game_stream;
    std::string game;

public:
    explicit GamePrinter(FarmPrinter *farm_printer_ptr, inventory *iIPointer);

    void generate_legend();

    void generate_inventory();

    void generate_info();

    std::string prettyPrint_Game();

    std::string prettyPrint_Legend();

    std::string prettyPrint_Inventory();

    static std::string getStreamLine(const std::string &input_string, const int &n);
};

#endif //FARMING_SIMULATOR_V2C_GAME_PRINTER_HPP