#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "card.h"

std::map<char, int> CARD_VALUES = {
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
std::vector<char> POSSIBLE_SUITS {'S', 'H', 'D', 'C'};
std::vector<char> POSSIBLE_VALUES {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

Card::Card(std::string card) {
    try {
        check_correctness(card);
        m_value = card.at(0);
        m_suit = card.at(1);
    }  catch (std::runtime_error &e) {
        throw e;
    }

}

void Card::check_correctness(std::string card) {
    std::string error_message;

    if (card.length() != 2) {
        error_message = std::string("Invalid card length. ") + card;
        throw std::runtime_error(error_message);
    }
    char value = card.at(0);
    char suit = card.at(1);

    if (std::find(POSSIBLE_VALUES.begin(), POSSIBLE_VALUES.end(), value) == POSSIBLE_VALUES.end()) {
        error_message = std::string("Invalid card value. ") + card;
        throw std::runtime_error(error_message);
    }

    if (std::find(POSSIBLE_SUITS.begin(), POSSIBLE_SUITS.end(), suit) == POSSIBLE_SUITS.end()) {
        error_message = std::string("Invalid card suit. ") + card;
        throw std::runtime_error(error_message);
    }
}

int Card::get_card_value() {
    return CARD_VALUES.at(m_value);
}

std::ostream& operator<<(std::ostream& os, const Card& poker_card) {
    os << "Card: " << poker_card.m_value << poker_card.m_suit;
    return os;
}
