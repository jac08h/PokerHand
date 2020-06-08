#ifndef POKERHAND_H
#define POKERHAND_H

#include <map>
#include <vector>
#include "card.h"

class PokerHand
{
private:
    std::vector<Card> m_cards;

    bool is_straight();
    bool is_flush();
    bool is_full_house();
    bool is_x_of_a_kind(int x);
    bool is_two_pair();

    int highest_card();

public:
    PokerHand(const char* pokerhand);
    int rank_card(); // 1 (high card) - 10 (royal flush)
    void print_cards();
};

#endif // POKERHAND_H