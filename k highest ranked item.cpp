  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        // we can do this question using the bfs aproach
        queue<pair<int ,int > > q;
        vector<vector<int >> ans;
        vector<pair<int , int > > index = {{-1 , 0} , {+1 , 0} , {0 , -1} , {0 , +1} };
        // these are the distance which one can move 
        pair<int ,int > temp;
        int n = grid.size();
        int m = grid[0].size();
        
        temp.first = start[0];
        temp.second = start[1];
        // vector<pair<int , int > vis(m*n , 0);
        int vis[n][m];
        memset(vis , 0 , sizeof(vis));
        multiset<vector<int>> set1;//order in which we will push the element
        vector<int > v1;
        q.push(temp);
        int cnt = 0;
        int dist = 0;
        int i;
        int l = pricing[0];
        int h = pricing[1];
        if(grid[temp.first][temp.second] >=l && grid[temp.first][temp.second] <= h )
        {
            i = grid[temp.first][temp.second];
            set1.insert({0,i , temp.first , temp.second});
        }
        while(!q.empty())
        {
            dist++;
            cnt = 0;
            
            int size = q.size();
            while(size--)
            {
                temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if(x >=0 && x<n && y>=0 && y<m)
                {
                   if(grid[x][y] == 0)
                    {
                        vis[x][y]  = 1;
                    }  
                }
                if(grid[x][y])
                {
                    vis[x][y] = 1;;
                    for(i=0; i<index.size(); i++)
                    {
                       
                        int p1 = temp.first + index[i].first;
                        int p2 = temp.second + index[i].second;
                        
                        if(p1>=0 && p1<n && p2>=0 && p2<m && vis[p1][p2] == 0)
                        {
                            q.push({p1,p2});
                            int val = grid[p1][p2];
                             if(val >= l && val <= h)
                            {
                            v1.push_back(dist);
                            v1.push_back(val);
                            v1.push_back(p1);
                            v1.push_back(p2);
                            set1.insert(v1);
                            v1.clear();
                            } 
                            vis[p1][p2] = 1;
                        }                   
                    }   
                } 
            }  
        }
        cnt = 0;
        for(auto itr:set1)
        {
             cnt++;
            ans.push_back({itr[2] , itr[3]});
            if(cnt==k)
            {
                break;
            }
           
        }
        return ans; 
    }
};
