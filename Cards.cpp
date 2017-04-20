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
@file Cards.cpp
@brief Contains class definitions the Card class, which includes the ranks and suits of cards in the game of Siete Y Medio
@author Lisa Chiang
@date April 22, 2017
************************************************* */

//Card Constructors
/**@brief Card Default Constructor

Randomly assigns a suit and rank

@param No parameters.
@return No returns.
*/
Card::Card() {
	int r = 1 + (rand() % 4); //4 suits possible 
	switch (r) //matches r (assigned randomly) with cases below
	{
	case 1: suit = OROS; break; //example, if r = 1, suit is oros 
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break; //default is exit 
	}
	r = 1 + (rand() % 10); //10 possible ranks {1, 2, 3, 4, 5, 6, 7, 1/2, 1/2, 1/2}
	switch (r)
	{
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

//Card Accessors
/**@ brief Get Spanish Suit

Returns a string with the suit of the card in Spanish.

@param No parameters.
@return Returns a string which is the suit in Spanish.
*/
std::string Card::get_spanish_suit() const {
	std::string suitName;
	switch (suit) //basically return what the contructor assigned the suit to be but in string terms 
	{
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName; //return Spanish name 
}
/**@ brief Get Spanish Rank

Returns a string with the rank of the card in Spanish.

@param No parameters.
@return Returns a string which is the rank in Spanish.
*/
std::string Card::get_spanish_rank() const {
	std::string rankName;
	switch (rank)
	{
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}

	return rankName;
}
/**@ brief Get English Suit

Returns a string with the suit of the card in English.

@param No parameters.
@return Returns a string which is the suit in English.
*/
std::string Card::get_english_suit() const {
	std::string suitName;
	switch (suit)
	{
	case OROS:
		suitName = "coins";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "swords";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}
	return suitName; //return English name 
}
/**@ brief Get English Rank

Returns a string with the rank of the card in English.

@param No parameters.
@return Returns a string which is the rank in English.
*/
std::string Card::get_english_rank() const {
	std::string rankName;
	switch (rank)
	{
	case AS:
		rankName = "One";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}
/**@ brief Get Rank

Returns an int which is the rank.

@param No parameters.
@return Returns the rank as an int.
*/
int Card::get_rank() const {

	return static_cast<int>(rank) + 1;
}
/**@ brief < Operator

Compares two cards and returns true if implicit is smaller.

@param card2 is the Card that is being compared against the implicit Card.
@return Returns true if implicit is less than card2 and false otherwise.
*/
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}
