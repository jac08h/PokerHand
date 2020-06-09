#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "pokerhand.h"
#include "card.h"
#include "constants.h"

PokerHand::PokerHand(const char* pokerhand) 
{
    // TODO: Handle invalid output
    std::string pokerhand_string = std::string(pokerhand);
    std::stringstream ss(pokerhand);
    std::vector<std::string> cards_as_string;

    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ' ');
        cards_as_string.push_back(substr);
    }

    for (std::string card_string:cards_as_string) {
        Card c{card_string};
        m_cards.push_back(c);
    }

    if (m_cards.size() != constants::NUMBER_OF_CARDS_IN_HAND) {
        std::string error_message = std::string("Invalid number of cards."); 
        throw std::runtime_error(error_message);
    }
}


void PokerHand::print_cards() 
{
    for (Card card: m_cards) {
        std::cout << card << std::endl;
    }
    std::cout << "end print cards";
}
int PokerHand::highest_card() 
{
    int max_value = 0;
    int current_value = 0;
    for (Card card : m_cards) {
        max_value = std::max(max_value, card.get_int_value());
    }
    return max_value;
}

bool PokerHand::is_straight() 
{
    std::vector<int> card_values{};
    for (Card card:m_cards) {
        card_values.push_back(card.get_int_value());
    }
    std::sort(card_values.begin(), card_values.end());
    for (int value: card_values) {
        std::cout << value << std::endl;
    }

    int current_value = card_values.at(0);
    int next_value;
    for (int i=1;i<constants::NUMBER_OF_CARDS_IN_HAND-1;i++) {
        next_value = card_values.at(i);
        if (next_value == current_value + 1) {
            current_value = next_value;
            next_value = card_values.at(i+1);
        }
        else {
            return false;
        }
    }
    return true;
}


bool PokerHand::is_flush() 
{
    char current_suit = m_cards.at(0).get_suit();
    for (int i=1;i<constants::NUMBER_OF_CARDS_IN_HAND;i++) {
        if (m_cards.at(i).get_suit() != current_suit) {
            return false;
        }
    }
    return true;
}