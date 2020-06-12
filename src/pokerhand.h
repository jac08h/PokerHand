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

public:
    PokerHand(const std::string hand_string);
    const std::vector<Card> get_cards() const { return m_cards;};
    void update_hand(const std::string hand_string);
    void print_cards();
};

#endif // POKERHAND_H