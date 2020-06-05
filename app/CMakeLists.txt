add_executable(app main.cpp)

target_link_libraries(app PRIVATE card)
target_link_libraries(app PRIVATE pokerhand)