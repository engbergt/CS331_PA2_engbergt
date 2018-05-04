/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 * 	Ammended on : May 4th, 2018
 * 		Author: engbergt
 */

#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include "MinimaxPlayer.h"


/* Start: Tarren's functions */

struct action {
	int column;
	int row;
	OthelloBoard *resultantBoard;
};


bool terminal(OthelloBoard *state) { // returns true if 'state' is a terminal state. 
	if(state->has_legal_moves_remaining(state->get_p1_symbol()) || state->has_legal_moves_remaining(state->get_p2_symbol())){
		return false;
	}
	else {
		return true;
	}
}

std::vector<action> successors(OthelloBoard *state, char playerSymbol) { // (AKA 'actions') needs to return an set of legal board states. There should already be a function for state legality.

	std::vector<action> validSuccessors;

	for(int c = 0; c < state->get_num_cols(); c++){
		for(int r = 0; c < state->get_num_rows(); r++){
			if(state->is_legal_move(c, r, playerSymbol)){
				action tempAction;
				tempAction.resultantBoard = state; // Clone the board ?? Ask Glen.
				tempAction.resultantBoard->play_move(c, r, playerSymbol);
				tempAction.column = c;
				tempAction.row = r;
				validSuccessors.push_back(tempAction);
				// OthelloBoard tempBoard = state; // Clone the board ?? Ask Glen.
				// tempBoard->play_move(c,r,????) // Add a piece to this c,r space, on the clone.
				// validSuccessors.push_back(state); // Push clone to the possible successors 
			}
		}
	}
}

int utility(OthelloBoard *state) { 
	int p1score = state->count_score(state->get_p1_symbol());
	int p2score = state->count_score(state->get_p2_symbol());
	return p1score - p2score; // the utility of a board state is the max players on board points subtract the min players on board points.
}



// Minimax functions

int maxValue(OthelloBoard *state){
	if(terminal(state)){
		return utility(state);
	}

	int value = -INT16_MAX; // negative "infinity".
	std::vector<action> succs = successors(state, state->get_p1_symbol());

	for(int i = 0; i < succs.size(); i++){
		value = std::max(value, minValue(succs[i].resultantBoard));
	}
	return value;
}

int minValue(OthelloBoard *state){
	if(terminal(state)){
		return utility(state);
	}
	int value = +INT16_MAX; // positive "infinity".
	std::vector<action> succs = successors(state, state->get_p2_symbol());

	for(int i = 0; i < succs.size(); i++){
		value = std::min(value, minValue(succs[i].resultantBoard));
	}
	return value;
}

action minimax(OthelloBoard *state) {

	int value = maxValue(state);
	std::vector<action> succs = successors(state, state->get_p2_symbol()); // not right.. we need to return an action.. ?
	
	return 0;
}



/* End: Tarren's functions */



MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
    // To be filled in by you

	action ourMove = minimax(b);
	ourMove.column >> col;
	ourMove.row >> row;
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
