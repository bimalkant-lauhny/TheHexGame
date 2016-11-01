#ifndef HX_HPP
#define HX_HPP

const int n = 11, m=n/2+2;
int nmid=n/2+1;
int human, bot; 
int maxd=2;
struct hx
{
	int board[n+1][m];
	int minimax(int board[][m],int turn, int depth);	// minimax(board,turn,depth)
	int evaluatescore(int board[][m],int turn, int depth); // evalutescore(board,depth)
	int win(int board[][m],int turn, int depth); // win(board)
    pair<int, int> move_gen();
	void print_board();
};

#include "hx_impl.hpp"
#endif
