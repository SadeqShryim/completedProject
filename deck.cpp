#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

Deck::Deck()
{
   string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades" };
   string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

   for (int i = 0; i < 6; ++i)
   {
       for (const string& suit : suits)
       {
           for (const string& rank : ranks)
           {
               cards.push_back(Card(suit, rank)); // Fix: Pass `rank` instead of `ranks` to the Card constructor
           }
       }
   }

   shuffle();
}

void Deck::shuffle()
{
   random_device rd;
   mt19937 g(rd());
   std::shuffle(cards.begin(), cards.end(), g); // Fix: Use std::shuffle instead of shuffle
}

Card Deck::dealCard()
{
	if (needsReshuffle())
	{
		shuffle();
	}

	Card topCard = cards.back();
	cards.pop_back();
	return topCard;
}

bool Deck::needsReshuffle() const
{
	return cards.size() < RESHUFFLE_THRESHOLD;
}