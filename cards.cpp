#include "cards.h"
#include <string>
using namespace std;

Card::Card(string suit, string rank) : suit(suit), rank(rank) {}

int Card::getValue() const
{
	if (rank == "J" || rank == "Q" || rank == "K")
	{
		return 10; // returning ten since each face card is worth 10
	}
	else if (rank == "A")
	{
		return 11;
	}
	else 
	{
		return stoi(rank);
	}
}

string Card::toString() const {
	return rank + " of " + suit;
}