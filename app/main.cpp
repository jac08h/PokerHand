#include <iostream>
#include "card.h"
#include "pokerhand.h"
#include "pokerhandranker.h"


int main()
{
    PokerHandRanker ranker = PokerHandRanker();
    PokerHand hand{"AS QS KS JS TS"};
    std::cout << ranker.rank_hand(hand);


    std::cout << std::endl;  // don't remove
}