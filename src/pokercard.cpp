#include <map>
#include <vector>
#include <algorithm>

#include "pokercard.h"

std::map<char, int> card_values = {
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
    {'K', 14},
    {'A', 15},
};

std::vector<char> POSSIBLE_SUITS {'S', 'H', 'D', 'C'};
std::vector<char> POSSIBLE_VALUES {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

PokerCard::PokerCard(std::string card) {
    try {
        check_correctness(card);
        m_value = card.at(0);
        m_suit = card.at(1);
    }  catch (int x) {
        throw x;
    }

}

bool PokerCard::check_correctness(std::string card) {
    if (card.length() != 2) {
        throw -1; // invalid length
    }
    char value = card.at(0);
    char suit = card.at(1);

    if (std::find(POSSIBLE_VALUES.begin(), POSSIBLE_VALUES.end(), value) != POSSIBLE_VALUES.end()) {
        throw -1;  // // invalid value
    }

    if (std::find(POSSIBLE_SUITS.begin(), POSSIBLE_SUITS.end(), suit) != POSSIBLE_SUITS.end()) {
            throw -1;  // // invalid suite
    }
}


int PokerCard::get_card_value() {
}
