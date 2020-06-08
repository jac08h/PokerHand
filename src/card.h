#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
    std::string m_card;
    char m_value, m_suit;

    void check_correctness(std::string card);
public:
    Card();
    Card(std::string card);
    int get_card_value(); // Return numeric representation of card's value
    friend std::ostream& operator<<(std::ostream& os, const Card& poker_card);
};

#endif // CARD_H