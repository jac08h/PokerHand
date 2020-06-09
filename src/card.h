#ifndef CARD_H
#define CARD_H

#include <string>
#include "constants.h"

class Card
{
private:
    std::string m_card;
    char m_value, m_suit;

    void check_correctness(std::string card);
public:
    Card();
    Card(std::string card);
    int get_int_value(); // Return numeric representation of card's value
    char get_char_value() {return m_value;};
    char get_suit() {return m_suit;};
    friend std::ostream& operator<<(std::ostream& os, const Card& poker_card);
};

#endif // CARD_H