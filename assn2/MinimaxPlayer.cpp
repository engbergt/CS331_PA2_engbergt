/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"

using std::vector;



/* Start: Tarren's functions */

playerSymbol player(state) { // whose turn it is

}

state results(state, action){ // the board state after 'action' is taken on 'state'.

}

boolean terminal(state) { // returns true if 'state' is a terminal state. 

}

successors(state) { // (AKA 'actions') needs to return an set of legal board states. There should already be a function for state legality.

}

int utility(state, player) { 

}

minimax(state) {
	if(terminal(state)){
		return utility(state);
	}
	if(player(state) == MAX){
		// take the minimax of each child and return the smallest.
	}
	if(player(state) == MIN){
		// take the minimax of each child and return the largest.
	}
}


/* End: Tarren's functions */



MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
    // To be filled in by you
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
