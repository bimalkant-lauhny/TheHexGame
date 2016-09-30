#include <bits/stdc++.h>
using namespace std;
const int n = 21, m=12 ;
int human, bot; 
struct hx
{
	int board[n+1][m];
	int minimax(int board[][m],int turn, int depth);	// minimax(board,turn,depth)
	int evaluatescore(int board[][m],int turn, int depth); // evalutescore(board,depth)
	int win(int board[][m],int turn, int depth); // win(board)
    pair<int, int> move_gen();
	void print_board();
};

void hx::print_board()
{
		//cout<<"BOARD: \n\n";
		int count = 10;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=count;j++)
					cout << " ";
			if(i<12)
			{
		    	for(int j=1;j<=i;j++)
			   	{
					if(board[i][j] == 1)
						cout << "B ";
					else if(board[i][j] == -1)
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
						for(int j=1;j<=(n-i)+1;j++)
						{
								if(board[i][j] == 1)
								   cout << "B ";
								else if(board[i][j] == -1)
								   cout << "R ";
								else
								   cout << "0 ";
						}
						count ++;
				}
				//cout << endl;
		}
		cout<<endl;
}

pair<int, int> hx::move_gen()
{
    int max_score = INT_MIN;
    pair <int, int> p;
    for(int i=1; i<=n; i++)
    {
    	//cout<< "in hexgeni= "<<i<<endl;
        if(i<12)
        {
            for(int j=1; j<=i; j++)
            {
            	//cout<< "in hexgenj= "<<j<<endl;
                if(board[i][j] == 0)
                {
                    board[i][j] = bot;
                    int temp_score = minimax(board, bot*(-1), 1);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                        p.first = i;
                        p.second = j;
                    }
                    board[i][j] = 0; 
                    //cout << "i j score " << i << " " << j << " " << temp_score << endl;
                }
            }
        }
        else
        {
            for(int j=1; j<=n-i+1; j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = bot;
                    int temp_score = minimax(board, bot*(-1), 1);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                        p.first = i;
                        p.second = j;
                    }
                    board[i][j] = 0; 
                    //cout << "i j score " << i << " " << j << " " << temp_score << endl;
                }
            }
        }
    }

    if(max_score == 0)
    {
        while(1)
        {
            int x, y;
            x = 1 + rand() % 21;
            if(x<=11)
                y = 1 + rand() % x;
            else
                y= 1 + rand() % (n-x+1);
            if(board[x][y] == 0)
            {
                p.first = x;
                p.second = y;
                break;
            }
        }
    }

    return p;
}

int hx::minimax(int board[][m], int turn, int depth)
{	
		if(depth>2) return 0;
		//cout<<"in minimax()"<<endl;
		int result = win(board,turn*-1,depth);
		//cout<< "wineval "<<result<<endl; 
		if(result!=0)
		{
				//return 0;
				return evaluatescore(board, turn*-1, depth);
		}
		//cout<<"depth = "<<depth<<endl;
		//if(depth > 2) return 0;
				
		int max_score = INT_MIN, min_score = INT_MAX;
    for(int i=1; i<=n; i++)
    {
        if(i<12)
        {
            for(int j=1; j<=i; j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = turn;
                    int temp_score = minimax(board, turn*(-1), depth+1);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                    }
					if(temp_score < min_score)
					{
							min_score = temp_score;
					}
                    board[i][j] = 0; 
                }
            }
        }
        else
        {
            for(int j=1; j<=n-i+1; j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = turn;
                    int temp_score = minimax(board, turn*(-1), depth+1);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                    }
					if(temp_score < min_score)
					{
							min_score = temp_score;
					}
                    board[i][j] = 0; 
                }
            }
        }
    }
	if(turn == human)
			return min_score;
	else
			return max_score;
}

int bfs(int board[][m],pair<int,int> s,vector< pair<int,int> > v2)
{
	queue< pair<int,int> > q;
	int visited[n+1][m]={0};
	q.push(s);
	visited[s.first][s.second]=1;
	int present=0;
	while(!q.empty())
	{
		pair<int,int> node = q.front();
		q.pop();
		int i=node.first,j=node.second;
		
		for(int ii= 0; ii<v2.size();ii++)
		{
			if(i == v2[ii].first && j == v2[ii].second)
			{
				present = 1;
				break;
			}
		}
		if(present == 1) break;
		
		//1 i-1,j-1
		if(i-1>0 && j-1>0 && board[i-1][j-1]== board[s.first][s.second] && visited[i-1][j-1]==0)
		{
			q.push(make_pair(i-1,j-1));
			visited[i-1][j-1]=1;
		}
		//2 i-1,j
		if(i-1>0 && j>0 && board[i-1][j]== board[s.first][s.second] && visited[i-1][j]==0)
		{
			q.push(make_pair(i-1,j));
			visited[i-1][j]=1;
		}
		//3 i,j-1
		if(i>0 && j-1>0 && board[i][j-1]== board[s.first][s.second] && visited[i][j-1]==0)
		{
			q.push(make_pair(i,j-1));
			visited[i][j-1]=1;
		}
		//4 i,j+1
		if(i>0 && j+1<m && board[i][j+1]== board[s.first][s.second] && visited[i][j+1]==0)
		{
			q.push(make_pair(i,j+1));
			visited[i][j+1]=1;
		}
		//5 i+1,j
		if(i+1<=n && j>0 && board[i+1][j]== board[s.first][s.second] && visited[i+1][j]==0)
		{
			q.push(make_pair(i+1,j));
			visited[i+1][j]=1;
		}
		//6 i+1, j+1
		if(i+1<=n && j+1<m && board[i+1][j+1]== board[s.first][s.second] && visited[i+1][j+1]==0)
		{
			q.push(make_pair(i+1,j+1));
			visited[i+1][j+1]=1;
		}
	} 
	return present;
}

int hx::win(int board[][m], int turn, int depth)
{
	vector < pair<int,int> >v1;
	vector < pair<int,int> >v2; 
	int winflag=0;
	if(turn == 1) //blue winning condition
	{
		for(int i=1;i<12;i++)
		{
			v1.push_back(make_pair(i,1));
		}
		for(int i=11;i<=n;i++)
		{
			v2.push_back(make_pair(i,n-i+1));
		}
		
		for(int i=0;i<v1.size();i++)
		{
			int icord=v1[i].first, jcord=v1[i].second;
			if(board[icord][jcord]== turn)
			{
				winflag = bfs(board,v1[i],v2);
				if(winflag == 1)
				{
					break;
				}
			}
		}
	}
	else //red wining condition 
	{
		for(int i=1;i<12;i++)
		{
			v1.push_back(make_pair(i,i));
		}
		for(int i=11;i<=n;i++)
		{
			v2.push_back(make_pair(i,1));
		}
		for(int i=0;i<v1.size();i++)
		{
			int icord=v1[i].first, jcord=v1[i].second;
			if(board[icord][jcord]== turn)
			{
				winflag = bfs(board,v1[i],v2);
				if(winflag == 1)
				{
					break;
				}
			}
		}
	}
	if(winflag==1) return turn;
	else return 0; 
}

int hx::evaluatescore(int board[][m], int turn, int depth)
{
   int result = win(board, turn, depth);
   if(result == human)
       return depth - 100;
   else if(result == bot)
       return 100 - depth;
   else
       return 0;
}

int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
    srand(time(NULL));
	hx hex;
    pair <int, int> move;
	//cout<<"Your turn(1 or 2): "; 
	cin>>human;
	if(human == 1) bot=-1;
	else human = -1, bot=1;
	// 1- blue , and -1 - red
	for(int i=0;i<=n;i++)
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
			//cout<<"Human: Enter cell i,j= "; 
			cin>>xi>>yj;
		}
		else
		{   move = hex.move_gen();
            xi = move.first;
            yj = move.second;
			cout<<xi<< " " << yj<<endl;
		}
		if(hex.board[xi][yj]!=0) continue;
		if(xi<(n/2 +2) && yj>xi ) continue;
		else if(xi >= (n/2+2) && yj>n-xi+1) continue;	
		hex.board[xi][yj] = turn;
		int winning=hex.win(hex.board,turn,0);
		turn *= -1;
		hex.print_board();
		//if(winning == human) printf("You won\n");
		//else if(winning== bot) printf("THE BOT WINS\n");
		//cout<<"winning= "<<winning<<endl;
		if(winning !=0) break;
	}
	return 0;
}
