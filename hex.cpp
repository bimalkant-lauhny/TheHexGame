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

	void print_board();
};

void hx::print_board()
{
		cout<<"BOARD: \n\n";
		int count = 10;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=count;j++)
					cout << " ";
			if(i<12)
			{
		    	for(int j=1;j<=i;j++)
			   	{
					if(board[i][j] == human)
						cout << "B ";
					else if(board[i][j] == bot)
						cout << "R ";
					else
						cout << "0 ";
			   	 }
				 count-=1;
				 if(i==11)
				   count = 1;
				}
				else
				{
						for(int j=1;j<=(n-i);j++)
						{
								if(board[i][j] == human)
								   cout << "B ";
								else if(board[i][j] == bot)
								   cout << "R ";
								else
								   cout << "0 ";
						}
						count ++;
				}
				cout << endl;
		}
		cout<<endl;
}


int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
	hx hex;
	cout<<"Your turn(1 or 2): "; cin>>human;
	if(human == 1) bot=-1;
	else human = -1, bot=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			hex.board[i][j]=0;
		}
	}
	
	hex.print_board();
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
		if(xi<(n/2 +1) && yj>xi ) continue;
		else if(xi >= (n/2+1) && yj>n-xi) continue;
			
		hex.board[xi][yj] = turn;
		turn *= -1;
	}
	return 0;
}
