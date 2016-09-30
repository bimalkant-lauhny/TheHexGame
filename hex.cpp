#include <bits/stdc++.h>
using namespace std;
const int n = 22, m=12 ;
int human, bot; 
struct hx
{
	int board[n][m];
	int minimax(int board[][m],int turn, int depth);	// minimax(board,turn,depth)
	int evaluatescore(int board[][m],int depth); // evalutescore(board,depth)
	int win(int board[][m],int depth); // win(board)
};


int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
	hx hex;
	cout<<"Your turn(1 or 2): "; cin>>human;
	if(human == 1) bot=-1;
	else human = -1, bot=1;
	
	int turn = 1, xi, yj;
	while(1)
	{
		if(turn == human)
		{
			cout<<"Human: Enter cell i,j= "; cin>>xi>>yj;
		}
		else
		{
			cout<<"BOT: Enter cell i,j= "; cin>>xi>>yj;
		}
		if(xi<(n/2 +1) && yj>i ) continue;
		else if(xi >= (n/2+1) && yj>n-xi) continue;
			
		hex.board[x][y] = turn;
		turn *= -1;
	}
	return 0;
}
