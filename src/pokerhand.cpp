#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <exception>

#include "pokerhand.h"
#include "card.h"
#include "constants.h"

PokerHand::PokerHand(const std::string hand_string) 
{
    m_cards = string_to_cards(hand_string);
}


std::vector<int> PokerHand::get_sorted_cards_values() const
{
   std::vector<int> card_values; 
   for (Card c: m_cards) {
       card_values.push_back(c.get_int_value());
   }
   std::sort(card_values.begin(), card_values.end(), std::greater<>());
   return card_values;
}

int PokerHand::get_highest_card() const
{
    int highest_card = -1;
    for (Card c:m_cards) {
        highest_card = std::max(c.get_int_value(), highest_card);
    }
    return highest_card;
}

std::vector<Card> PokerHand::string_to_cards(const std::string hand_string) 
{
    std::stringstream ss(hand_string);
    std::vector<std::string> cards_as_string;
    std::vector<Card> cards;

    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ' ');
        cards_as_string.push_back(substr);
    }

    for (std::string card_string:cards_as_string) {
        Card c{card_string};
        cards.push_back(c);
    }

    if (cards.size() != constants::number_of_cards_in_hand) {
        std::string error_message = std::string("Invalid number of cards."); 
        throw std::runtime_error(error_message);
    }
    return cards;
}


void PokerHand::update_hand(const std::string hand_string) 
{
    m_cards = string_to_cards(hand_string);
}


void PokerHand::print_cards() 
{
    for (Card card: m_cards) {
        std::cout << card << std::endl;
    }
    std::cout << "end print cards";
}
