#include <algorithm>
#include <cassert>

#include "pokerhandcomparer.h"

std::map<int, int> PokerHandComparer::count_card_occurences(const PokerHand &h) 
{
    std::map<int, int> card_occurences;
    for (Card c: h.get_cards()) {
        card_occurences[c.get_int_value()]++;
    }
    return card_occurences;
}

int PokerHandComparer::get_value_of_x_of_a_kind(int x, const PokerHand &h)
{
    std::map<int, int> card_occurences = count_card_occurences(h);
    for (auto const& [card_value, occurences]: card_occurences) {
        if (occurences == x) {
            return card_value;
        }
    }
}


std::pair<int, int> PokerHandComparer::get_sorted_values_of_two_pairs(const PokerHand &h) 
{
    int first_pair_value = -1;
    int second_pair_value = -1;
    std::map<int, int> card_occurences = count_card_occurences(h);
    for (auto const& [card_value, occurences]: card_occurences) {
        if (occurences == 2) {
            if (first_pair_value == -1) {
                first_pair_value = card_value;
            }
            else {
                second_pair_value = card_value;
            }
        }
    }
    std::pair<int, int> sorted_values = std::minmax({first_pair_value, second_pair_value}, std::greater<>());
}

constants::Result PokerHandComparer::compare_hands_with_identical_rank(const PokerHand &first, const PokerHand &second, constants::HandRank rank) 
{
    constants::Result compared_sorted = compare_sorted_hands(first, second);
    if (compared_sorted == constants::Result::Tie) {
        return constants::Result::Tie;
    }

    if (rank == constants::HandRank::ROYAL_FLUSH) {
        return constants::Result::Tie;
    }

    if (rank == constants::HandRank::STRAIGHT_FLUSH) {
        // can't get tie, because if 2+ players have flush, they have to hold same suit -> can't get highest card of similar value
        if (first.get_highest_card() > second.get_highest_card()) {
            return constants::Result::FirstWins;
        }
        else {
            return constants::Result::SecondWins;
        }
    }
    if (rank == constants::HandRank::FOUR_OF_A_KIND) {
        // higher set wins -> higher fifth card
        int first_set_value = get_value_of_x_of_a_kind(4, first);
        int second_set_value = get_value_of_x_of_a_kind(4, second);
        if (first_set_value > second_set_value) {
            return constants::Result::FirstWins;
        }
        else if (second_set_value > first_set_value) {
            return constants::Result::SecondWins;
        }
        else { // four-of-a-kind lands on the table, last highest card decides
            return compared_sorted;
        }
    }
    if (rank == constants::HandRank::FULL_HOUSE) {
        // higher triplet -> higher pair
        int first_triplet_value = get_value_of_x_of_a_kind(3, first);
        int second_triplet_value = get_value_of_x_of_a_kind(3, second);
        if (first_triplet_value > second_triplet_value) {
            return constants::Result::FirstWins;
        }
        else if (second_triplet_value > first_triplet_value) {
            return constants::Result::SecondWins;
        }
        else {
            return compared_sorted;
        }
    }
    if (rank == constants::HandRank::FLUSH) {
        return compared_sorted;
    }
    if (rank == constants::HandRank::STRAIGHT) {
        return compared_sorted;
    }
    if (rank == constants::HandRank::THREE_OF_A_KIND) {
        // higher triplet -> fourth card -> fifth card
        int first_triplet_value = get_value_of_x_of_a_kind(3, first);
        int second_triplet_value = get_value_of_x_of_a_kind(3, second);
        if (first_triplet_value > second_triplet_value) {
            return constants::Result::FirstWins;
        }
        else if (second_triplet_value > first_triplet_value) {
            return constants::Result::SecondWins;
        }

        else {
            return compared_sorted;
        }
    }
    if (rank == constants::HandRank::TWO_PAIR) {
        std::pair<int,int> first_hand_pairs = get_sorted_values_of_two_pairs(first);
        std::pair<int,int> second_hand_pairs = get_sorted_values_of_two_pairs(second);

        if (first_hand_pairs.first > second_hand_pairs.first) {
            return constants::Result::FirstWins;
        }
        else if (second_hand_pairs.first > first_hand_pairs.first) {
            return constants::Result::SecondWins;
        }

        else {
            if (first_hand_pairs.second > second_hand_pairs.second) {
                return constants::Result::FirstWins;
            }
            else if (second_hand_pairs.second > first_hand_pairs.second) {
                return constants::Result::SecondWins;
            }
            else {
                return compared_sorted;
            }
        }
    }
    if (rank == constants::HandRank::ONE_PAIR) {
        // higher pair -> comparing cards
        int first_pair_value = get_value_of_x_of_a_kind(2, first);
        int second_pair_value = get_value_of_x_of_a_kind(2, second);
        if (first_pair_value > second_pair_value) {
            return constants::Result::FirstWins;
        }
        else if (second_pair_value > first_pair_value) {
            return constants::Result::SecondWins;
        }
        else {
            return compared_sorted;
        }
    }
    if (rank == constants::HandRank::HIGH_CARD) {
        return compared_sorted;
    }

    assert(0 && "The card should be ranked by this time.");

}


constants::Result PokerHandComparer::compare_sorted_hands(const PokerHand &first, const PokerHand &second) 
{
    std::vector<int> sorted_first = first.get_sorted_cards_values();
    std::vector<int> sorted_second = second.get_sorted_cards_values();
    for (int i=0; i<constants::number_of_cards_in_hand; i++) {
        if (sorted_first.at(i) > sorted_second.at(i)) {
            return constants::Result::FirstWins;
        }
        else if (sorted_first.at(i) < sorted_second.at(i)) {
            return constants::Result::SecondWins;
        } // if same, continue to next card
    }
    return constants::Result::Tie; // identical hands
}


constants::Result PokerHandComparer::compare_cards(const PokerHand &first, const PokerHand &second) 
{
    constants::HandRank first_rank = m_ranker.rank_hand(first);
    constants::HandRank second_rank = m_ranker.rank_hand(second);
    if (first_rank > second_rank) {
        return constants::Result::FirstWins;
    }
    else if (second_rank > first_rank) {
        return constants::Result::SecondWins;
    }
    else {
        return compare_hands_with_identical_rank(first, second, first_rank);
    }
}