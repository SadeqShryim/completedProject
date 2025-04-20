#ifndef CARDS_H
#define CARDS_H

#include <string>
using namespace std;

class Card
{
private:
	string suit;
	string rank;

public:
	Card(string suit, string rank);
	
	int getValue() const;
	string toString() const;
};
#endif