#include <iostream>
#include "card.h"
#include "pokerhand.h"

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  return Result::Loss;
}


int main()
{
    PokerHand hand{"KS QH AC JS TD"};


    std::cout << std::endl;  // don't remove
}
