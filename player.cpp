#include "player.h"

using namespace std;

Player::Player(int straightBalance) : balance(straightBalance){ //intitilizes balance
}

void Player::addCard(const Card& card) {
	hand.push_back(card);
}

int Player::getHandValue() const {
	int total = 0, Aces = 0;

	for (size_t i = 0; i < hand.size(); i++) {
		int value = hand[i].getValue();
		total += value;
		if (value == 11) {
			++Aces;
		}
	}

	while (total > 21 and Aces > 0) {
		total -= 10;
		--Aces;
	}

	return total;
}

string Player::showHand() const {
	string playerHand = "";

	size_t i = 0;
	while (i < hand.size()) {
		playerHand += hand[i].toString() + "\n";
		++i;
	}
	return playerHand;
}

int Player::getBalance() const {
	return balance;
}

void Player::updateBalance(int amount) {
	balance += amount;
}

bool Player::isLose() const {
	return getHandValue() > 21;
}

void Player::clearHand() {
	hand.clear();
}

Card Player::getCardAt(int index) const {
	return hand[index];
}

const vector <Card>& Player::getHand() const {
	return hand;
}