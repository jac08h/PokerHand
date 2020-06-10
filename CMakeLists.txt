set (CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.17)
project(PokerHand VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(app)


enable_testing()
add_subdirectory(googletest)
add_subdirectory(test)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
