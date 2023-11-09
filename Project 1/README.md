#The Card Game

##Definitions

-Players
Players participate in the card game.
Each player has a hand of cards, pointers to their opponent, a Point Deck, and an Action Deck.

-Decks
There are two types of decks: Point Deck and Action Deck.
Decks store Point Cards and Action Cards.

-Hand
A Hand belongs to a player and contains only Point Cards.
The cards in the hand must maintain an order, where the cards drawn first are scored first.
Players can only add Point Cards to their hand through an Action Card instruction.

-Point Cards
Point Cards contain only whole numbers.
When a Player plays a Point Card from their hand, they score the number of points indicated on the card.
The only way for a Player to play a card from their hand is through an Action Card Instruction.

-Action Cards
Action Cards contain instructions in one of the following forms, where x is a positive integer:

DRAW x CARD(S): Instructs a player to draw x cards from a deck.
PLAY x CARD(S): Instructs a player to play x cards from their hand.
REVERSE HAND: Instructs a player to reverse the order of cards in their hand.
SWAP HAND WITH OPPONENT: Instructs a player to exchange their hand with their opponent's hand.