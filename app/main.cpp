#include <iostream>
#include "constants.h"
#include "card.h"
#include "pokerhand.h"
#include "pokerhandranker.h"
#include "pokerhandcomparer.h"


int main()
{
    PokerHandRanker ranker = PokerHandRanker();
    PokerHand hand{"AS QS KS JS TS"};
    std::cout << static_cast<int>(ranker.rank_hand(hand)); 

    std::cout << std::endl;  // don't remove
}