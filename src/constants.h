#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <vector>

namespace constants {
    inline std::map<char, int> CARD_VALUES = {
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
    inline std::vector<char> POSSIBLE_SUITS {'S', 'H', 'D', 'C'};
    inline std::vector<char> POSSIBLE_VALUES {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    inline int NUMBER_OF_CARDS_IN_HAND = 5;
}


#endif // CONSTANTS_H