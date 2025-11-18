

cmake_minimum_required(VERSION 3.24)

project("Farming Simulator - v2b")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(main main.cpp)


#[[
add_executable(soil_test tests/soil_test.cpp
        src/soil.cpp
)

add_executable(beet_test tests/plant_tests/beet_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(brussels_sprouts_test tests/plant_tests/brussels_sprouts_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(carrot_test tests/plant_tests/carrot_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(lettuce_test tests/plant_tests/lettuce_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(melon_test tests/plant_tests/melon_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(onion_test tests/plant_tests/onion_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(spinach_test tests/plant_tests/spinach_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(zucchini_test tests/plant_tests/zucchini_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(inventory_test tests/inventory_test.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(farm_test tests/farm_test.cpp
        src/farm.cpp
        src/player.cpp
        src/items/seeds.cpp
        src/items/produce.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(farm_printer_test tests/farm_printer_test.cpp
        src/farm_printer.cpp
        src/player.cpp
        src/inventory.cpp
        src/items/produce.cpp
        src/items/seeds.cpp
        src/farm.cpp
)
add_executable(game_printer_test tests/game_printer_test.cpp
        src/game_printer.cpp
        src/farm_printer.cpp
        src/player.cpp
        src/inventory.cpp
        src/farm.cpp
        src/soil.cpp
        src/plant.cpp
        src/items/seeds.cpp
        src/items/produce.cpp
)

add_executable(seeds_test tests/seeds_test.cpp
        src/items/seeds.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(produce_test tests/produce_test.cpp
        src/items/produce.cpp
        src/plant.cpp
        src/inventory.cpp
)
add_executable(player_test tests/player_test.cpp
        src/player.cpp
        src/inventory.cpp
        src/items/seeds.cpp
        src/items/produce.cpp
        src/plant.cpp
)
add_executable(shop_test tests/shop_test.cpp
        src/shop.cpp )


add_executable(cupid_test tests/cupid_test.cpp
        src/cupid.cpp)


target_link_libraries(farm_printer_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(game_printer_test PRIVATE Catch2::Catch2WithMain)

target_link_libraries(inventory_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(farm_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(player_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(soil_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(seeds_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(produce_test PRIVATE Catch2::Catch2WithMain)

target_link_libraries(beet_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(brussels_sprouts_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(carrot_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(lettuce_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(melon_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(onion_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(spinach_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(zucchini_test PRIVATE Catch2::Catch2WithMain)

target_link_libraries(cupid_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(shop_test PRIVATE Catch2::Catch2WithMain)
]]

