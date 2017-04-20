/**************************************
@file Cards.h
@brief Contains class declarations for interface of a simple Card class
@author Lisa Chiang
@date April 22, 2017

This card class allows you to play Siete y Medio using class Cards, class Hand, class Player.
************************************* */
//rikis-salazar

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//OROS = golden coins, spades = 1 / COPAS = cups || church, hearts = 2 / ESPADAS = swords || military, diamonds = 3 / BASTOS = peasants, clubs = 4
enum suit_t { OROS, COPAS, ESPADAS, BASTOS };
/* The values for this type start at 0 and increases by one until SIETE (7).
The rank reported by the function Card::get_rank() below is the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

/* *************************************************
@file Cards.h
@brief Contains class declarations the Card class, which includes the ranks and suits of cards in the game of Siete Y Medio
@author Lisa Chiang
@date April 22, 2017
************************************************* */
class Card {
public:
	//Constructor
	Card();

	//Accessors 
	std::string get_spanish_suit() const;
	std::string get_spanish_rank() const;
	std::string get_english_suit() const;
	std::string get_english_rank() const;
	int get_rank() const;

	//Overloading Operators
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};

/* *************************************************
@file Hand.h
@brief Contains class declarations for player's current hand, which includes whatever Cards the player has drawn.
@author Lisa Chiang
@date April 22, 2017
************************************************* */
class Hand {
public:
	//Constructor
	Hand();

	//Mutators
	void draw_card();
	void clear_hand();

	//Accessors
	void print_curr_card();
	void view_hand();
	double get_total_hand();

private:
	std::vector<Card> hand;
};

/* *************************************************
@file Player.h
@brief Contains class declarations for the Player class, which keeps track of how much money the Player has throughout
the game.
@author Lisa Chiang
@date April 22, 2017
************************************************* */
class Player {
public:
	//Constructors
	Player();
	Player(int m);

	//Accessors
	int get_money() const;

	//Mutators
	void won_money(int m);
	void lost_money(int m);

private:
	int money;
};

#endif
