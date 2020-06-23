#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <vector>

namespace constants {
    inline std::map<char, int> card_values = {
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'T', 10},
        {'J', 11},
        {'Q', 12},
        {'K', 13},
        {'A', 14},
    };
    inline std::vector<char> possible_suits {'S', 'H', 'D', 'C'};
    inline std::vector<char> possible_values {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    inline int number_of_cards_in_hand = 5;
    inline int highest_card_value = 14;

    enum class Result { FirstWins, Tie, SecondWins};
    enum class HandRank {
        HIGH_CARD,
        ONE_PAIR,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH,
        ROYAL_FLUSH,
        };
}


#endif // CONSTANTS_H