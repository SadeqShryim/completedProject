#ifndef DECK_H
#define DECK_H

#include <vector>
#include "cards.h"
using namespace std;

class Deck 
{
private:
	vector<Card> cards;
	const int RESHUFFLE_THRESHOLD = 100;

public:
	Deck();
	void shuffle();
	Card dealCard();
	bool needsReshuffle() const;


};

#endif