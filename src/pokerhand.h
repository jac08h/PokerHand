#ifndef POKERHAND_H
#define POKERHAND_H

#include <map>

class PokerHand
{
private:
    int get_highest_card();
public:
    PokerHand(const char* pokerhand);
    int get_value();
};

#endif // POKERHAND_H
