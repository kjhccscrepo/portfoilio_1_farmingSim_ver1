#include "game_printer.hpp"
GamePrinter::GamePrinter(FarmPrinter *farm_printer_ptr, Player *pPointer) {
    myFarmPrinted = farm_printer_ptr;
    myPlayerPointer = pPointer;
    generate_info();
}
void GamePrinter::generate_legend() {
    legend_print.str("");
    legend_print.clear();
    legend_print << "CONTROLS\n";
    legend_print << "w:\tmove up\n";
    legend_print << "s:\tmove down\n";
    legend_print << "a:\tmove left\n";
    legend_print << "d:\tmove right\n";
    legend_print << "i:\tview inventory\n";
    legend_print << "p:\tplant selected seed\n";
    legend_print << "o:\tchange selected seed\n";
    legend_print << "h:\tharvest grown crop\n";
    legend_print << "e:\tend the day\n";
    legend_print << "q:\tquit the game\n";
    legend_print << "r:\treturn to the game\n";
    legend = legend_print.str();
}
void GamePrinter::generate_inventory() {
    inventory_print.str("");
    inventory_print.clear();
    std::string line;
    std::string items = (myPlayerPointer->getInventoryString());
    int counter = 1;
    inventory_print << "INVENTORY\n";
    int maxSize = myPlayerPointer->how_many_types_of_things();
    for (int i = 0; i < maxSize; i++) {
        inventory_print << counter << ":\t";
        inventory_print << getStreamLine(items, i);
        inventory_print << "\n";
        counter++;
    }
    inventory_print << "r:\treturn to the game\n";
    inventory = inventory_print.str();
}
void GamePrinter::generate_info() {
    info_print.str("");
    info_print.clear();
    info_print << "Current Seed:\t" << myPlayerPointer->getSelectedSeed() << "\n";
    info_print << "l:\tview controls\n";
    info_print << "i:\tview inventory\n";
    info_print << "q:\tquit the game\n";
    info = info_print.str();
}
std::string GamePrinter::prettyPrint_Game() {
    game_stream.str("");
    game_stream.clear();

    std::istringstream input_stream;
    input_stream.str(myFarmPrinted->prettyPrint().str());
    std::string farm_line;
    int i = 0;
    while (std::getline(input_stream, farm_line)) {
        game_stream << farm_line;
        if (i < 4) {
            game_stream << "\t\t";
            game_stream << getStreamLine(info, i);
            i++;
        }
        game_stream << "\n";
    }
    return game_stream.str();
}
std::string GamePrinter::prettyPrint_Legend() {
    return legend;
}
std::string GamePrinter::prettyPrint_Inventory() {
    return inventory;
}
std::string GamePrinter::getStreamLine(const std::string &input_string, const int &n) {
    std::string line;
    std::istringstream input_stream;
    std::stringstream ss_buffer;
    input_stream.str(input_string);
    int iterations = 0;
    while (std::getline(input_stream, line)) {
        if (iterations == n) {
            return line;
        }
        ss_buffer >> line;
        iterations++;
    }
    return "notfound";
}
