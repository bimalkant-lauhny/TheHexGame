#ifndef HX_IMP_HPP
#define HX_IMP_HPP

// In case not included yet
#include "hx.hpp"
#include "bfs.hpp"
#include <fstream>


void hx::print_board()
{
	//cout<<"BOARD: \n\n";
	int count = nmid-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=count;j++)
				cout << " ";
		if(i<=nmid)
		{
	    	for(int j=1;j<=i;j++)
		   	{
				if(board[i][j] == 1) cout << "B ";
				else if(board[i][j] == -1) cout << "R ";
				else cout << "0 ";
		   	}
			count-=1;
			if(i==nmid) count = 1;
		}
		else
		{
			for(int j=1;j<=(n-i)+1;j++)
			{
				if(board[i][j] == 1) cout << "B ";
				else if(board[i][j] == -1) cout << "R ";
				else cout << "0 ";
			}
			count ++;
		}
		cout << endl;
	}
	//cout<<endl;
}

void hx::print_to_file()
{
    ofstream myfile;
    myfile.open("boardOutput");
    int count = nmid-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=count;j++)
				myfile << " ";
		if(i<=nmid)
		{
	    	for(int j=1;j<=i;j++)
		   	{
				if(board[i][j] == 1) myfile << "B ";
				else if(board[i][j] == -1) myfile << "R ";
				else myfile << "0 ";
		   	}
			count-=1;
			if(i==nmid) count = 1;
		}
		else
		{
			for(int j=1;j<=(n-i)+1;j++)
			{
				if(board[i][j] == 1) myfile << "B ";
				else if(board[i][j] == -1) myfile << "R ";
				else myfile << "0 ";
			}
			count ++;
		}
		myfile << endl;
	}
}

pair<int, int> hx::move_gen()
{
    int max_score = INT_MIN, minscore = INT_MAX;
    pair <int, int> p;
    for(int i=1; i<=n; i++)
    {
    	//cout<< "in hexgeni= "<<i<<endl;
        if(i<=nmid)
        {
            for(int j=1; j<=i; j++)
            {
            	//cout<< "in hexgenj= "<<j<<endl;
                if(board[i][j] == 0)
                {
                    board[i][j] = bot;
                    int temp_score = minimax(board, bot*(-1), 0);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                        p.first = i;
                        p.second = j;
                    }
                    if(temp_score<minscore)
                    {
                    	minscore = temp_score;
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
                    int temp_score = minimax(board, bot*(-1), 0);
                    if(temp_score > max_score)
                    {
                        max_score = temp_score;
                        p.first = i;
                        p.second = j;
                    }
                    if(temp_score<minscore)
                    {
                    	minscore = temp_score;
                    }
                    board[i][j] = 0; 
                    //cout << "i j score " << i << " " << j << " " << temp_score << endl;
                }
            }
        }
    }

    if(max_score == minscore)
    {
        //cout<<"random\n";
        while(1)
        {
            int x, y;
            x = 1 + rand() % n;
            if(x<=nmid)
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
	
	//cout<<"in minimax()"<<endl;
	int result = win(board,turn*-1,depth);
	//cout<< "wineval "<<result<<endl; 
	if(result!=0)
	{
			//return 0;
			return evaluatescore(board, turn*-1, depth);
	}
	if(depth>maxd) return depth;
	//cout<<"depth = "<<depth<<endl;
	//if(depth > 2) return 0;
			
	int max_score = INT_MIN, min_score = INT_MAX;
    for(int i=1; i<=n; i++)
    {
        if(i<=nmid)
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



int hx::win(int board[][m], int turn, int depth)
{
	vector < pair<int,int> >v1;
	vector < pair<int,int> >v2; 
	int winflag=0;
	if(turn == 1) //blue winning condition
	{
		for(int i=1;i<=nmid;i++)
		{
			v1.push_back(make_pair(i,1));
		}
		for(int i=nmid;i<=n;i++)
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
		for(int i=1;i<=nmid;i++)
		{
			v1.push_back(make_pair(i,i));
		}
		for(int i=nmid;i<=n;i++)
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

#endif
