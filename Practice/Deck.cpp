#include "Deck.h"
#include <algorithm>


Deck::Deck()
{

}


Deck::~Deck()
{
	for (int i = 0; i < numOfCardsInthedeck; i++) {
		delete cardsList[i];
	}
}

void Deck::CreateDeck() {
	int k = 0;
	for (int i = 0; i < numOfSuits; i++)
	{
		for (int j = 0; j < numOfCardsInTheSuit; j++) {
			Card* card = new Card();
			card->cardSuit = Suit(i);
			card->value = cardValues[j];
			cardsList[k++] = card;
		}
	}
}

void Deck::ShuffleDeck() {

	std::random_shuffle(&cardsList[0], &cardsList[51]);

}


int Deck::DealCards(int numOfPlayers, int numOfCards = 5) {

	// Dynamically allocating a 2D Array
	Card** PlayerHand = new Card*[numOfPlayers];
	for (int i = 0; i < numOfPlayers; i++)
		PlayerHand[i] = new Card[numOfCards];

	int dealtCardsPerPlayer = 0;
	int highestValueOfHand = 0;
	int playerNumber = 0;
	while (dealtCardsPerPlayer < numOfCards) {
		for (int i = 0; i < numOfPlayers; i++) {
			PlayerHand[i][dealtCardsPerPlayer] = *(cardsList[numOfCardsInthedeck - 1 - i -(dealtCardsPerPlayer*numOfCards)]);
		}
		dealtCardsPerPlayer++;
	}
	for (int i = 0; i < numOfPlayers; i++)
	{
		int tempSum = 0;
		for (int j = 0; j < numOfCards; j++) 
		{

			if (PlayerHand[i][j].value == "A") {
				tempSum += 1;
			}
			else	if (PlayerHand[i][j].value == "J" || PlayerHand[i][j].value =="Q" || PlayerHand[i][j].value == "K") {
				tempSum += 10;
			}
			else
			{
				tempSum += std::stoi(PlayerHand[i][j].value);
			}
			
		}
		if (highestValueOfHand < tempSum)
		{
			highestValueOfHand = tempSum;
			playerNumber = i+1;
		}
	}
	for (int i = 0; i < numOfPlayers; i++)
	{
		delete[] PlayerHand[i];
	}
	delete[] PlayerHand;
	std::cout << "The player number" << playerNumber << "Has the highest Value of hand: " << highestValueOfHand <<endl;
	return playerNumber;
}

