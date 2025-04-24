#include <iostream>
#include "player.h"
#include "deck.h"
#include "cards.h"
#include "BlackJack.h"
#include "BlackJackSim.h"
using namespace std;


int main() {
	cout << "Blackjack Strategy Simulator" << endl;
	cout << "Simulating 100,000 random hands..." << endl << endl;

	BlackJackSim simulator;
	simulator.simulator();
	simulator.display();
	cout << "\nSimulation complete.\n";
	//player test
	/*Deck deck;
	Player player(100);

	player.addCard(deck.dealCard());
	player.addCard(deck.dealCard());

	cout << "Hand of Player: " << endl;
	cout << player.showHand();

	cout << "Value of Players Hand: " << player.getHandValue() << endl;

	cout << (player.isLose() ? "You lose the hand\n" : "You are still in \n");*/

	/*blackjack test - part 1
	Player player(100);
	Player dealer(0);
	BlackJack testGame(dealer, player);

	cout << "BLACK JACK" << endl;

	testGame.reset();
	testGame.dealCards();

	testGame.playerHand();
	testGame.dealerHand(false);

	testGame.playerTurn();*/
	//test day 9
	//Player player(100);
	//Player dealer(0);

	//BlackJack testGame(dealer, player);

	//cout << "Welcome!!!" << endl;

	//do {

	//	testGame.playRound();
	//	cout << "your current balance is: $" << player.getBalance() << endl;
	//
	//} while (testGame.anotherRound());

	//cout << "Thank you for playing. Youur final balance is: $" << player.getBalance() << endl;
	return 0;
}