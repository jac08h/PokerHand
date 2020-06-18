#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <exception>
#include <cassert>

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


bool PokerHandRanker::is_two_pair() 
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

HandRank PokerHandRanker::rank_hand(const PokerHand &h) 
{
    m_cards = h.get_cards();

    if (is_royal_flush()) { return HandRank::ROYAL_FLUSH;}
    if (is_straight_flush()) {return HandRank::STRAIGHT_FLUSH;}
    if (is_x_of_a_kind(4)) {return HandRank::FOUR_OF_A_KIND;}
    if (is_full_house()) {return HandRank::FULL_HOUSE;}
    if (is_flush()) {return HandRank::FLUSH;}
    if (is_straight()) {return HandRank::STRAIGHT;}
    if (is_x_of_a_kind(3)) {return HandRank::THREE_OF_A_KIND;}
    if (is_two_pair()) {return HandRank::TWO_PAIR;}
    if (is_x_of_a_kind(2)) {return HandRank::ONE_PAIR;}
    return HandRank::HIGH_CARD;
}

int PokerHandRanker::get_value_of_x_of_a_kind(int x, const PokerHand &h)
{
    std::map<int, int> card_occurences = count_card_occurences();
    for (auto const& [card_value, occurences]: card_occurences) {
        if (occurences == x) {
            return card_value;
        }
    }
}

Result PokerHandRanker::compare_hands_with_identical_rank(const PokerHand &first, const PokerHand &second, HandRank rank) 
{
    Result compared_sorted = compare_sorted_hands(first, second);
    if (compared_sorted == Result::Tie) {
        return Result::Tie;
    }

    if (rank == HandRank::ROYAL_FLUSH) {
        return Result::Tie;
    }

    if (rank == HandRank::STRAIGHT_FLUSH) {
        // can't get tie, because if 2+ players have flush, they have to hold same suit -> can't get highest card of similar value
        if (first.get_highest_card() > second.get_highest_card()) {
            return Result::FirstWins;
        }
        else {
            return Result::SecondWins;
        }
    }
    if (rank == HandRank::FOUR_OF_A_KIND) {
        // higher set wins -> higher fifth card
        int first_set_value = get_value_of_x_of_a_kind(4, first);
        int second_set_value = get_value_of_x_of_a_kind(4, second);
        if (first_set_value > second_set_value) {
            return Result::FirstWins;
        }
        else if (second_set_value > first_set_value) {
            return Result::SecondWins;
        }
        else { // four-of-a-kind lands on the table, last highest card decides
            return compare_sorted_hands(first, second);
        }
    }


    if (rank == HandRank::FULL_HOUSE) {
        // higher triplet -> higher pair
        int first_triplet_value = get_value_of_x_of_a_kind(3, first);
        int second_triplet_value = get_value_of_x_of_a_kind(3, second);
        if (first_triplet_value > second_triplet_value) {
            return Result::FirstWins;
        }
        else if (second_triplet_value > first_triplet_value) {
            return Result::SecondWins;
        }
        else {
            return compare_sorted_hands(first, second);
        }
    }

    return Result::Tie;
}


Result PokerHandRanker::compare_sorted_hands(const PokerHand &first, const PokerHand &second) 
{
    std::vector<int> sorted_first = first.get_sorted_cards_values();
    std::vector<int> sorted_second = second.get_sorted_cards_values();
    for (int i=0; i<constants::number_of_cards_in_hand; ++i) {
        if (sorted_first.at(i) > sorted_second.at(i)) {
            return Result::FirstWins;
        }
        else if (sorted_first.at(i) < sorted_second.at(i)) {
            return Result::SecondWins;
        } // if same, continue to next card
    }
    return Result::Tie; // identical hands
}

Result PokerHandRanker::compare_cards(const PokerHand &first, const PokerHand &second) 
{
    HandRank first_rank = rank_hand(first);
    HandRank second_rank = rank_hand(second);
    if (first_rank > second_rank) {
        return Result::FirstWins;
    }
    else if (second_rank > first_rank) {
        return Result::SecondWins;
    }
    else {
        return compare_hands_with_identical_rank(first, second, first_rank);
    }
}