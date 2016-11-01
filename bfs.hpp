#ifndef BFS_HPP
#define BFS_HPP
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

#endif
