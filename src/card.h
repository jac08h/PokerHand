#ifndef POKERCARD_H
#define POKERCARD_H

#include <string>

class PokerCard
{
private:
    std::string m_card;
    char m_value, m_suit;

    bool check_correctness(std::string card);

public:
    PokerCard();
    PokerCard(std::string card);
    int get_card_value();
};

#endif // POKERCARD_H
