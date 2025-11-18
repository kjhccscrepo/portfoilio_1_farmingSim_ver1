#include "game_printer.hpp"
GamePrinter::GamePrinter(FarmPrinter *farm_printer_ptr, inventory *iIPointer) {
    myFarmPrinted = farm_printer_ptr;
    myInventoryPointer = iIPointer;
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
    legend_print << "q:\twater the selected plot\n";
    legend_print << "m:\tgo to the shop\n";
    legend_print << "q:\tquit the game\n";
    legend_print << "r:\treturn to the game\n";
    legend = legend_print.str();
}
void GamePrinter::generate_inventory() {
    inventory_print.str("");
    inventory_print.clear();
    std::string line;
    std::string items = (myInventoryPointer->inventory_stream().str());
    int counter = 1;
    inventory_print << "INVENTORY\n";
    int maxSize = myInventoryPointer->how_many_types_of_things();
    for (int i = 0; i < maxSize; i++) {
        inventory_print << counter << ":\t";
        inventory_print << getStreamLine(items, i);
        inventory_print << "\n";
        counter++;
    }
    inventory_print << "r:\treturn to the game\n";
    inventory_p = inventory_print.str();
}
void GamePrinter::generate_info() {
    info_print.str("");
    info_print.clear();
    info_print << "DAY:\t" << myFarmPrinted->days_to_print() << "\n";
    info_print << "Current Seed:\t" << myInventoryPointer->getSelectedSeed() << "\n";
    info_print << "l:\tview controls\n";
    info_print << "i:\tview inventory\n";
    info_print << "o:\tchange selected seed\n";
    info_print << "p:\tplant selected seed\n";
    info_print << "q:\tquit the game\n";
    info = info_print.str();
}
std::string GamePrinter::prettyPrint_Game() {
    generate_info();
    game_stream.str("");
    game_stream.clear();
    std::istringstream input_stream;
    input_stream.str(myFarmPrinted->prettyPrint().str());
    std::string farm_line;
    int i = 0;
    while (std::getline(input_stream, farm_line)) {
        game_stream << farm_line;
        if (i < 7) {
            game_stream << "\t\t";
            game_stream << getStreamLine(info, i);
            i++;
        }
        game_stream << "\n";
        game_stream << "Watering Can Amount:\t ";
        for (int w = 0; w < myInventoryPointer->getCurrentWater(); w++) {
            game_stream << "|";
        }
        game_stream << "\n";
    }
    return game_stream.str();
}
std::string GamePrinter::prettyPrint_Legend() {
    return legend;
}
std::string GamePrinter::prettyPrint_Inventory() {
    return inventory_p;
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
