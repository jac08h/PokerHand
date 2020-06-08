#include <iostream>
#include <string>
#include <sstream>

#include "pokerhand.h"
#include "card.h"

PokerHand::PokerHand(const char* pokerhand) 
{
    std::string pokerhand_string = std::string(pokerhand);
    std::stringstream ss(pokerhand);
    std::vector<std::string> cards_as_string;
    std::vector<Card> m_cards;

    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ' ');
        cards_as_string.push_back(substr);
    }

    for (std::string card_string:cards_as_string) {
        std::cout << card_string << std::endl;
        Card c{card_string};
        m_cards.push_back(c);
    }
}


void PokerHand::print_cards() 
{
    for (Card card: m_cards) {
        std::cout << card;
    }
    std::cout << "end print cards";
}