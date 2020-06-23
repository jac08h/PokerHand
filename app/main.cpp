#include <iostream>
#include "constants.h"
#include "card.h"
#include "pokerhand.h"
#include "pokerhandranker.h"
#include "pokerhandcomparer.h"


int main()
{
    PokerHandRanker ranker = PokerHandRanker();
    PokerHandComparer comparer = PokerHandComparer();
    PokerHand first{"TD 9D 8D 7D 6D"};
    PokerHand second{"TD 9D 8D 7D 6D"};


    constants::Result res = comparer.compare_cards(first, second);
    if (res == constants::Result::Tie) {
        std::cout << "Second wins";
    }
    else if (res == constants::Result::FirstWins) {
        std::cout << "First wins";
    }
    else {
        std::cout << "Tie";
    }

    std::cout << std::endl;  // don't remove
}