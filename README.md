SIETE Y MEDIO

AUTHOR
Written by Lisa Chiang (clisa928@g.ucla.edu). 

SYNOPSIS
This project is a game called Siete Y Medio (seven and a half), which is the Spanish version of Black Jack or 21. Unlike the English version, there are only 10 cards. Cards 1-7 correspond to their numerical value while cards 10-12 are valued at 0.5.  The player's goal is to get as close to 7.5 as possible without busting (going over). If the player succeeds, he or she wins the money bet at the beginning of the round. Otherwise, the money is deducted. To win the game, the player has to win $1000 or the dealer has to lose $900. 

The game is coded in C++ and includes three files - sieteymedio.cpp, cards.h, cards.cpp. 
Cards.h contains all the class declarations involved in the game. This includes the classes for the cards, the player's hand, and the player's money. 
Cards.cpp contains all the class definitions for the cards.h file. More detailed descriptions, parameters, and returns can be found above each function defintion. 
Sieteymedio.cpp is the actual interface the player interacts with and it includes the code for the game as well as the code that creates a gamelog file that the player can view afterwards. 

CODE EXAMPLE
The following is an example of a round in the game: 

    You have $100. Enter bet: 99
    Your cards:
      Dos de copas        (Two of cups).
    Your total is 2. Do you want another card (y/n)? n
    Dealer's cards:	Sota de espadas     (Jack of spades).
    The dealer's total is 0.5.

    New card:
      Rey de espadas (King of spades).

The card class contains different cards and their values. The hand class is in charge of drawing and viewing the cards in the hand. The player class will keep track of how much money the player has. 

Furthermore, the user will get a gamelog.txt file after the completion of the game. This text file is similar to the console output. 

MOTIVATION
This game was created for the purpose of learning to commit, create branches, and merge using some type of GUI or the command line for homework one of the PIC10C course. 
