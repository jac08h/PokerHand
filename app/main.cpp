#include <iostream>
#include "card.h"
#include "pokerhand.h"

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  return Result::Loss;
}


int main()
{
    PokerHand hand ("KS 2H 5C JD TD");
    hand.print_cards();



    std::cout << std::endl;  // don't remove
}
