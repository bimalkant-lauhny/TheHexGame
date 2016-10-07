#include <bits/stdc++.h>
using namespace std;
#include "hx.hpp"


int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
    srand(time(NULL));
	// initialize hex object
	hx hex;
    pair <int, int> move;
	cout<<"Your turn (1 or 2): "; 
	cin >> human;

	// 1- blue , and -1 - red
	if(human == 1)
		bot = -1;
	else 
		human = -1;
    	bot = 1;

    // initialize board to all zeros
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			hex.board[i][j]=0;
		}
	}

    // debug: Print Board	
	hex.print_board();
	int turn = 1, xi, yj;
	while(1)
	{
		if(turn == human)
		{
			cout << "Human: Enter cell i,j= "; 
			cin >> xi >> yj;
		}
		else
		{   move = hex.move_gen();
            xi = move.first;
            yj = move.second;
			cout << "Bot chose: " << xi << " " << yj << endl;
		}
		
		if((hex.board[xi][yj] != 0))
		{
		    cout << "Position Already Occupied\n";
		    continue;
		}
		if(xi < (n/2 +2) && yj > xi) 
		{
		    cout << "Invalid Position\n";
	    	continue;
		}
		else if(xi >= (n/2+2) && yj > n-xi+1) 
		{
		    cout << "Invalid Position\n";
		    continue;	
		}

		hex.board[xi][yj] = turn;
		int winning = hex.win(hex.board,turn,0);
		turn *= -1;
		hex.print_board();
		//if(winning == human) printf("You won\n");
		//else if(winning== bot) printf("THE BOT WINS\n");
		//cout<<"winning= "<<winning<<endl;
		if(winning !=0) 
		    break;
	}
	return 0;
}
