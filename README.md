# PokerHand

## Structure
*  **Card** class
    * Individual card from a standard 52 cards deck
*  **PokerHand** class
    * Holds a hand containing 5 **Card**s
* **PokerHandRanker** class
    * Rank a card on a scale 0 (High Card) to 9 (Royal Flush)
* **PokerHandComparer** class
    * Compare two hands
    * Uses **PokerHandRanker** to find the rank. If the rank is the same, uses tie-breaking rules to determine the winner or a tie.