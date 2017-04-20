/**************************************
@file Siete Y Medio.cpp
@brief Main.cpp - game interface that user interacts with.
@author Lisa Chiang
@date April 22, 2017
************************************* */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

int main()
{
	srand(time(0)); //srand
	int dealer_loss = 0; //dealer's loss
	int bet = 0; //how much you bet
	bool cont = true; //whether or not to continue 
	std::string y_n; //whether or not to draw
	
	//initializing Players (money) and Hand (cards)
	Player You(100); Player Dealer(100);
	Hand Your_hand; Hand Dealer_hand;

	//continue rounds until player hits $0 or dealer loses more than $900
	while (You.get_money() > 0 && dealer_loss < 900)
	{
		//initial amount of money
		std::cout << "You have $" << You.get_money() << ". Enter bet: ";
		std::cin >> bet; std::cin.ignore();

		//keep betting within range 
		while (You.get_money() < bet)
		{
			std::cout << "You only have $" << You.get_money() << " to bet. Enter bet: ";
			std::cin >> bet;
		}

		//beginning the game - player drawing ONE CARD to begin 
		std::cout << "Your cards: " << std::endl;
		Your_hand.draw_card(); Your_hand.print_curr_card();
		std::cout << std::endl;

		//giving total and option to keep drawing unless busted
		while (cont)
		{
			std::cout << "Your total is " << Your_hand.get_total_hand() << ".";
			if (7.5 < Your_hand.get_total_hand()) //if total is greater than 7.5
			{
				std::cout << std::endl << "You busted!";
				std::cout << std::endl;
				cont = false;
			}
			else
			{
				std::cout << " Do you want another card (y/n)? ";
				std::cin >> y_n; std::cin.ignore();
				if (y_n == "n" || y_n == "N")	//no more cards
				{
					cont = false;
				}
				else if (y_n == "Y" || y_n == "y") //more cards
				{
					std::cout << std::endl;
					std::cout << "New card:" << std::endl;
					Your_hand.draw_card(); Your_hand.print_curr_card();
					std::cout << std::endl << std::endl;
					std::cout << "Your cards: " << std::endl; Your_hand.view_hand();
				}
				//false input
				else
				{
					std::cout << "That is not a valid response. " << std::endl;
				}
			}
		}

		//Dealer's turn
		std::cout << std::endl;
		Dealer_hand.draw_card(); //draw
		std::cout << "Dealer's cards: " << std::endl;
		Dealer_hand.view_hand(); //view hand  
		std::cout << std::endl << "The dealer's total is " << Dealer_hand.get_total_hand() << "." << std::endl << std::endl; //total

		//continue to draw for dealer while dealer's total is less than player's OR dealer's total is less than 5.5 
		while (Dealer_hand.get_total_hand() < Your_hand.get_total_hand() || Dealer_hand.get_total_hand() <= 5.5)
		{
			std::cout << "New Card:" << "\t" << std::endl;
			Dealer_hand.draw_card(); Dealer_hand.print_curr_card(); //draw
			std::cout << std::endl << "Dealer's cards:" << std::endl; //show hand 
			Dealer_hand.view_hand();
			std::cout << "The dealer's total is " << Dealer_hand.get_total_hand() << "." << std::endl << std::endl; //total 
		}

		//if you busted (whether or not dealer busted)
		if (Your_hand.get_total_hand() > 7.5)
		{
			std::cout << "Too bad. You lose " << bet << ".";
			You.lost_money(bet);
		}
		//if dealer busted and you didn't 
		else if (Dealer_hand.get_total_hand() > 7.5)
		{
			std::cout << "You win " << bet << ".";
			You.won_money(bet);
			dealer_loss += bet; //inc dealer loss 
		}
		//if none of you busted
		else
		{
			//you were closer to 7.5
			if (Your_hand.get_total_hand() > Dealer_hand.get_total_hand())
			{
				std::cout << "You win " << bet << ".";
				You.won_money(bet);
				dealer_loss += bet; //inc dealer loss 
			}
			//tied 
			else if (Your_hand.get_total_hand() == Dealer_hand.get_total_hand())
			{
				std::cout << "Nobody wins! ";
			}
			//dealer closer to 7.5 
			else
			{
				std::cout << "Too bad. You lose " << bet << ".";
				You.lost_money(bet);
			}
		}

		std::cout << std::endl << std::endl;

		//reset 
		Your_hand.clear_hand(); Dealer_hand.clear_hand();
		cont = true;
	}
		
	return 0;
}