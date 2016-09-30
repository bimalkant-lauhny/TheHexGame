#include <bits/stdc++.h>
using namespace std;
const int n = 11;
int human, bot; 
struct hx
{
	int board[n][n];
	int minimax(int board[][n],int turn, int depth);	// minimax(board,turn,depth)
	int evaluatescore(int board[][n],int depth); // evalutescore(board,depth)
	int win(int board[][n],int depth); // win(board)
};

int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
	hx hex;
	cout<<"Your turn(1 or 2): "; cin>>human;
	if(human == 1) bot=-1;
	else human = -1, bot=1;
	
	int turn = 1, x, y;
	while(1)
	{
		if(turn == human)
		{
			cout<<"Human: Enter cell i,j= "; cin>>x>>y;
			hex.board[x][y] = turn;
			turn = bot;
		}
		else
		{
			cout<<"BOT: Enter cell i,j= "; cin>>x>>y;
			hex.board[x][y] = turn; 
			turn = human;
		}
	}
	return 0;
}
