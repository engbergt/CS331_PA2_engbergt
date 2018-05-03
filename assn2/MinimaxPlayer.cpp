/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include "MinimaxPlayer.h"


using std::vector;



/* Start: Tarren's functions */


bool terminal(OthelloBoard state) { // returns true if 'state' is a terminal state. 
	if(state::has_legal_moves_remaining(state::get_p1_symbol()) || state::has_legal_moves_remaining(state::get_p2_symbol())){
		return false;
	}
	else {
		return true;
	}
}

std::vector<OthelloBoard> successors(OthelloBoard state) { // (AKA 'actions') needs to return an set of legal board states. There should already be a function for state legality.

	std::vector<OthelloBoard> validSuccessors;

	for(int c = 0; c < state::get_num_cols(); c++){
		for(int r = 0; c < state::get_num_rows(); r++){
			if(state::is_cell_empty(c,r) && state::is_legal_move(c,r,????)){
				OthelloBoard tempBoard = state; // Clone the board ?? Ask Glen.
				tempBoard::play_move(c,r,????) // Add a piece to this c,r space, on the clone.
				
				validSuccessors.push_back(state); // Push clone to the possible successors 
			}
		}
	}
}

int utility(OthelloBoard state) { 
	int p1score = state::count_score(state::get_p1_symbol);
	int p2score = state::count_score(state::get_p2_symbol);
	return p1score - p2score; // the utility of a board state is the max players on board points subtract the min players on board points.
}

int maxValue(OthelloBoard state){
	if(terminal(state)){
		return utility(state);
	}
	value = -INT16_MAX; // negative infinity.
	for(int& i: successors(state)) {
		value = std::max(value, minValue(state));
	}
}

int minValue(OthelloBoard state){
	if(terminal(state)){
		return utility(state);
	}
	value = +INT16_MAX; // positive infinity.
	for(int& i: successors(state)) {
		value = std::min(value, minValue(state));
	}
}

OthelloBoard minimax(OthelloBoard state) {

	int value = maxValue(state);
	return successors(state)[value];

}



/* End: Tarren's functions */



MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
    // To be filled in by you

	colAndRow = minimax(b)

	colAndRow.col >> col;
	colAndRow.row >> row;
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
