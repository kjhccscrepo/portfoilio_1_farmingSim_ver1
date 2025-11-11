#ifndef GAME_PRINTER_H
#define GAME_PRINTER_H
#include <sstream>
#include "farm_and_friends/farm_printer.hpp"
#include "inventory.hpp"

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
    static std::string getStreamLine(const std::string& input_string, const int &n);
};
#endif
