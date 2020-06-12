#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <exception>

#include "pokerhandranker.h"
#include "pokerhand.h"
#include "card.h"
#include "constants.h"


std::map<int, int> PokerHandRanker::count_card_occurences() 
{
    std::map<int, int> card_occurences;
    for (Card c: m_cards) {
        card_occurences[c.get_int_value()]++;
    }
    return card_occurences;
}

int PokerHandRanker::highest_card() 
{
    int max_value = 0;
    int current_value = 0;
    for (Card card : m_cards) {
        max_value = std::max(max_value, card.get_int_value());
    }
    return max_value;
}

bool PokerHandRanker::is_straight() 
{
    std::vector<int> card_values{};
    for (Card card:m_cards) {
        card_values.push_back(card.get_int_value());
    }
    std::sort(card_values.begin(), card_values.end());

    int current_value = card_values.at(0);
    int next_value;
    for (int i=1;i<constants::number_of_cards_in_hand-1;i++) {
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


bool PokerHandRanker::is_flush() 
{
    char current_suit = m_cards.at(0).get_suit();
    for (int i=1;i<constants::number_of_cards_in_hand;i++) {
        if (m_cards.at(i).get_suit() != current_suit) {
            return false;
        }
    }
    return true;
}


bool PokerHandRanker::is_two_of_a_kind() 
{
    std::map<int, int> card_occurences = count_card_occurences();
    int pairs = 0;
    for (auto const& [card_value,occurences] : card_occurences ) {
        if (occurences == 2) {
            ++pairs;
        }
    }
    if (pairs == 2) {
        return true;
    }
    return false;

}

bool PokerHandRanker::is_royal_flush() 
{
    if (is_flush() && is_straight() && highest_card() == constants::highest_card_value) {
        return true;
    }
    return false;
}


bool PokerHandRanker::is_straight_flush() 
{
    if (is_flush() && is_straight() && highest_card() != constants::highest_card_value) {
        return true;
    }
    return false;
    
}

bool PokerHandRanker::is_x_of_a_kind(int x) 
{
    std::map<int, int> card_occurences = count_card_occurences();
    for (auto const& [card_value, occurences]: card_occurences) {
        if (occurences == x) {
            return true;
        }
    }
    return false;
}    

bool PokerHandRanker::is_full_house() 
{
    if (is_x_of_a_kind(3) && is_x_of_a_kind(2)) {
        return true;
    }
    return false;
}

int PokerHandRanker::rank_hand(const PokerHand &h) 
{
    m_cards = h.get_cards();

    if (is_royal_flush()) { return 10;}
    if (is_straight_flush()) {return 9;}
    if (is_x_of_a_kind(4)) {return 8;}
    if (is_full_house()) {return 7;}
    if (is_flush()) {return 6;}
    if (is_straight()) {return 5;}
    if (is_x_of_a_kind(3)) {return 4;}
    if (is_two_of_a_kind()) {return 3;}
    if (is_x_of_a_kind(2)) {return 2;}
    return 1; // high card
}