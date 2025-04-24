#include "BlackJackSim.h"
#include "deck.h"
#include "player.h"
#include "cards.h"
#include <ctime> 
#include <iostream>

void BlackJackSim::simulator(int rounds) {
	srand(time(0));

	for (int i = 0; i < rounds; ++i) {
		Deck deck;
		deck.shuffle();

		Player dealer(0), player(0);
		dealer.clearHand();
		player.clearHand();

		dealer.addCard(deck.dealCard());
		dealer.addCard(deck.dealCard());

		player.addCard(deck.dealCard());
		player.addCard(deck.dealCard());

		int startingValue = player.getHandValue();


		if (!isValidCard(startingValue)) continue;

		//randomly generate 0 or 1
			//0 -- stand 1 -- for hit
		bool randomHit = rand() % 2;

		if (randomHit) {
			player.addCard(deck.dealCard());
		}

		while (dealer.getHandValue() < 17) {
			dealer.addCard(deck.dealCard());
		}

		bool dealerBust = dealer.getHandValue() > 21;
		bool playerBust = player.getHandValue() > 21;

		Stats& stats = randomHit ? hitResults[startingValue] : standResults[startingValue];
		if (dealerBust)
			stats.win++;
		else if (dealer.getHandValue() < player.getHandValue())
			stats.win++;
		else if (playerBust)
			stats.loss++;
		else if (dealer.getHandValue() > player.getHandValue())
			stats.loss++;
		else
			stats.draw++;
	}
}

//Helper function no need for it in the .h 
bool BlackJackSim::isValidCard(int value) {
	return value >= 4 and value <= 20;
}

void BlackJackSim::display() const {
	cout << "\nAfter Runnning the Simulation of 100 thousand hands the results are: " << endl;
	cout << " Starting Value  |  Hit (W\\L\\D)  |  Stand (W\\L\\D)" << endl;
	cout << "------------------------------------------------------" << endl;
	for (int total = 4; total <= 20; ++total) {
		auto hitIt = hitResults.find(total);
		auto standIt = standResults.find(total);

		if (hitIt != hitResults.end() || standIt != standResults.end()) {
			const Stats& hit = hitIt != hitResults.end() ? hitIt->second : Stats{};
			const Stats& stand = standIt != standResults.end() ? standIt->second : Stats{};

			cout << "   " << total << "    |  "
				<< hit.win << "-" << hit.loss << "-" << hit.draw << "       |  "
				<< stand.win << "-" << stand.loss << "-" << stand.draw << "\n";
		}
	}
}