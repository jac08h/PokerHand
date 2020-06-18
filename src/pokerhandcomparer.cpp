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
            return compare_sorted_hands(first, second);
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
            return compare_sorted_hands(first, second);
        }
    }

    return constants::Result::Tie;
}


constants::Result PokerHandComparer::compare_sorted_hands(const PokerHand &first, const PokerHand &second) 
{
    std::vector<int> sorted_first = first.get_sorted_cards_values();
    std::vector<int> sorted_second = second.get_sorted_cards_values();
    for (int i=0; i<constants::number_of_cards_in_hand; ++i) {
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