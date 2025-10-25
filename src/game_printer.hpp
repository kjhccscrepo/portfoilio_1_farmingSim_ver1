#pragma once
#include <sstream>
#include "farm_printer.hpp"

class GamePrinter {
    FarmPrinter *myFarmPrinted;
    Player *myPlayerPointer;
    std::stringstream legend_print;
    std::string legend;
    std::stringstream inventory_print;
    std::string inventory;
    std::stringstream info_print;
    std::string info;
    std::stringstream game_stream;
    std::string game;
    public:
    explicit GamePrinter(FarmPrinter *farm_printer_ptr, Player *pPointer);
    void generate_legend();
    void generate_inventory();
    void generate_info();
    std::string prettyPrint_Game();
    std::string prettyPrint_Legend();
    std::string prettyPrint_Inventory();
    static std::string getStreamLine(const std::string& input_string, const int &n);
};