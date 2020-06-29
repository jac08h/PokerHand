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
    PokerHand first{"AS AD QS QD 2S"};
    PokerHand second{"AS AD JS JD 2S"};

    constants::Result res = comparer.compare_cards(first, second);

    if (res == constants::Result::Tie) {
        std::cout << "Tie";
    }
    else if (res == constants::Result::FirstWins) {
        std::cout << "First wins";
    }
    else {
        std::cout << "Second wins";
    }

    std::cout << std::endl;
}