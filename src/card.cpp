#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "card.h"

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

    if (std::find(constants::POSSIBLE_VALUES.begin(), constants::POSSIBLE_VALUES.end(), value) == constants::POSSIBLE_VALUES.end()) {
        error_message = std::string("Invalid card value. ") + card;
        throw std::runtime_error(error_message);
    }

    if (std::find(constants::POSSIBLE_SUITS.begin(), constants::POSSIBLE_SUITS.end(), suit) == constants::POSSIBLE_SUITS.end()) {
        error_message = std::string("Invalid card suit. ") + card;
        throw std::runtime_error(error_message);
    }
}

int Card::get_int_value() {
    return constants::CARD_VALUES.at(m_value);
}

std::ostream& operator<<(std::ostream& os, const Card& poker_card) {
    os << "Card: " << poker_card.m_value << poker_card.m_suit;
    return os;
}
