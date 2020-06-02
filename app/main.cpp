#include <iostream>
#include "card.h"
#include "pokerhand.h"

enum class Result {Win, Loss, Tie};


Result compare(const PokerHand &player, const PokerHand &opponent) {
    return Result::Loss;
}



int main()
{
    Card p = Card{"3D"};
    std::cout << p << std::endl;
}
