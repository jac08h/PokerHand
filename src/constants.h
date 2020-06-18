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
        ROYAL_FLUSH,
        STRAIGHT_FLUSH,
        FOUR_OF_A_KIND,
        FULL_HOUSE,
        FLUSH,
        STRAIGHT,
        THREE_OF_A_KIND,
        TWO_PAIR,
        ONE_PAIR,
        HIGH_CARD,
        };
}


#endif // CONSTANTS_H