#pragma once
#include <iostream>>
#include<vector>
#include <string>
using namespace std;
class Deck
{

	enum Suit { DIAMONDS, HEARTS, CLUBS,SPADES};
	struct Card {
		Suit cardSuit;
		string value;
	};
private:
	const int numOfCardsInthedeck = 52;
	const int numOfCardsInTheSuit = 13;
	const int numOfSuits = 4;
	
	Card* cardsList[52];			// List of Cards

public:
	const string cardValues[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	// Create the deck of cards with 52 cards in it
	void CreateDeck();

	// Shuffle the card deck randomly
	void ShuffleDeck();

	int DealCards(int numOfPlayers, int numOfCards);

	Deck();
	~Deck();
};

