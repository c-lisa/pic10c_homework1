/**************************************
@file Cards.cpp
@brief Contains class definitions for interface of a simple Card class.
@author Lisa Chiang
@date April 22, 2017

Includes class definitions for class Card, class Hand, class Player.
************************************* */

#include "cards.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "time.h"
#include <cmath>

/* *************************************************
@file Hand.cpp
@brief Contains class definitions for player's current hand, which includes whatever Cards the player has drawn.
@author Lisa Chiang
@date April 22, 2017
************************************************* */
//Constructors 
/**@ brief Hand default constructor

Blank Constructor

@param No parameters.
@return Returns nothing.
*/
Hand::Hand()
{
	;
}
/**@ brief Drawing Cards

Draws a card and pushes back into hand.

@param No parameters.
@return Returns nothing.
*/
void Hand::draw_card()
{
	Card current;
	hand.push_back(current);
}
/**@ brief Printing Current Card

Prints current card with english and spanish translations.

@param No parameters.
@return Returns nothing.
*/
void Hand::print_curr_card()
{
	Card current = hand[hand.size() - 1];
	//printing to user
	std::cout << "\t" << current.get_spanish_rank() << " de " << current.get_spanish_suit()
		<< "\t" << "(" << current.get_english_rank() << " of " << current.get_english_suit() << ").";
}
/**@ brief Viewing Entire Hand

Displays all the cards in current hand.

@param No parameters.
@return Returns nothing.
*/
void Hand::view_hand()
{
	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << "\t" << hand[i].get_spanish_rank() << " de " << hand[i].get_spanish_suit()
			<< "\t" << "(" << hand[i].get_english_rank() << " of " << hand[i].get_english_suit() << ").";
		std::cout << std::endl;
	}
}
/**@ brief Getting Total Hand

Adds up the total in hand and returns a double.

@param No parameters.
@return Returns a double that is the total of current hand.
*/
double Hand::get_total_hand()
{
	int num_of_cards = hand.size() - 1; //if size is 5, i = 4
	double sum = 0;

	for (int i = 0; i <= num_of_cards; ++i)
	{
		if (hand[i].get_rank() <= 7)
		{
			sum += hand[i].get_rank();
		}
		else
		{
			sum += 0.5;
		}
	}
	return sum;
}
/**@ brief Clearing the Hand

Resets hand for a new round

@param No parameters.
@return Returns nothing.
*/
void Hand::clear_hand()
{
	Hand A;
	hand = A.hand;
}

/* *************************************************
@file Player.cpp
@brief Contains class definitions for the Player class, which keeps track of how much money the Player has throughout
the game.
@author Lisa Chiang
@date April 22, 2017
************************************************* */
//Constructors
/**@ brief Player default constructor

Sets the money initially to $100.

@param No parameters.
@return Returns nothing.
*/
Player::Player()
{
	money = 100;
}
/**@ brief Player constructor

Sets the money initially to int m.

@param m is the amount of money the money initially has.
@return Returns nothing.
*/
Player::Player(int m)
{
	money = m;
}

//Accessors
/**@ brief Get Money

Tells you how much money the player currently has.

@param No parameters.
@return Returns an int which is the amount of money the player has.
*/
int Player::get_money() const
{
	return money;
}
/**@ brief Increasing the Money

Adds the money won from the bet to current money.

@param m is how much money is added.
@return Returns nothing.
*/
void Player::won_money(int m)
{
	money += m;
}
/**@ brief Decreasing the Money

Subtracts the money lost from the bet from current money.

@param m is how much money is subtracted.
@return Returns nothing.
*/
void Player::lost_money(int m)
{
	money -= m;
}
