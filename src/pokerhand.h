#ifndef POKERHAND_H
#define POKERHAND_H

#include <map>
#include <vector>
#include <string>
#include "card.h"
#include "constants.h"

class PokerHand
{
private:
    std::vector<Card> m_cards;

    std::vector<Card> string_to_cards(const std::string hand_string);

    bool is_full_house();
    bool is_x_of_a_kind(int x);
    bool is_two_pair();
    int highest_card();
    bool is_straight();
    bool is_flush();

    bool is_royal_flush();
    bool is_straight_flush();



public:
    PokerHand(const std::string hand_string);
    void update_hand(const std::string hand_string);
    int rank_hand(); // 1 (high card) - 10 (royal flush)
    void print_cards();
};

#endif // POKERHAND_H