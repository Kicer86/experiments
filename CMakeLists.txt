cmake_minimum_required(VERSION 2.6)
project(queue)

add_executable(queue queue.cpp)
add_executable(roulette roulette.cpp)

install(TARGETS queue RUNTIME DESTINATION bin)
install(TARGETS roulette RUNTIME DESTINATION bin)
