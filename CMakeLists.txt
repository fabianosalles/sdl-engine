cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

add_custom_target(
    copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/src/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

include_directories(src/Sheeva)
file(GLOB SOURCES "src/Sheeva/*.cpp")

project(sheeva)
    add_executable(sheeva src/Sheeva/main.cpp ${SOURCES})
    add_dependencies(sheeva copy_assets)
    target_link_libraries(sheeva SDL2 SDL2main SDL2_mixer SDL2_image)
    target_link_libraries(sheeva SDL2 SDL2main SDL2_mixer SDL2_image)