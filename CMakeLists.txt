cmake_minimum_required(VERSION 3.24)

project("Farming Simulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)


add_executable(main main.cpp
        src/ansi_clear.hpp
        src/farm.cpp
        src/farm_brain.cpp
        src/items.cpp
        src/plants.cpp
        src/player.cpp
        src/soil.cpp
        src/produce.cpp
        src/seeds.cpp
        src/plantData.cpp
        src/lootTable.cpp
)
add_executable(farm_test tests/farm_test.cpp
        src/farm.cpp
        src/soil.cpp
        src/plants.cpp
        src/seeds.cpp
        src/items.cpp
        src/produce.cpp
        src/plantData.cpp
        src/lootTable.cpp)
add_executable(farm_brain_test tests/farm_brain_test.cpp
        src/farm_brain.cpp
        src/farm.cpp
        src/soil.cpp
        src/plants.cpp
        src/seeds.cpp
        src/items.cpp
        src/produce.cpp
        src/plantData.cpp
        src/lootTable.cpp
        src/player.cpp)
add_executable(items_test tests/items_test.cpp
        src/items.cpp)
add_executable(plants_test tests/plants_test.cpp
        src/plants.cpp
        src/items.cpp
        src/produce.cpp
        src/plantData.cpp
        src/lootTable.cpp
        )
add_executable(player_test tests/player_test.cpp
        src/player.cpp
        src/farm_brain.cpp
        src/plants.cpp
        src/items.cpp
        src/produce.cpp
        src/seeds.cpp)
add_executable(soil_test tests/soil_test.cpp
        src/soil.cpp
        src/plants.cpp
        src/seeds.cpp
        src/items.cpp
        src/produce.cpp
        src/plantData.cpp
        src/lootTable.cpp)
add_executable(produce_test tests/produce_test.cpp
        src/produce.cpp
        src/items.cpp)
add_executable(seeds_test tests/seeds_test.cpp
        src/seeds.cpp
        src/items.cpp)

target_link_libraries(farm_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(farm_brain_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(items_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(plants_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(player_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(soil_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(produce_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(seeds_test PRIVATE Catch2::Catch2WithMain)
