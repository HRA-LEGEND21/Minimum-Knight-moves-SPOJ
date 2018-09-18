#include <cstdint>
#include <string>
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
void identation(int size_space)
{
    for(int i = 0; i < size_space; i++)
    {
        printf(" ");
    }
}
int x_move[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int y_move[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int n, m;
const int OO = INT_MAX;
const int MaxN = 2e4 + 3;
vector<vector<string>> adj;
bool board[8][8];
bool valid(pair<int, int> rc)
{
    return (rc.first >= 0 && rc.first < 8) && (rc.second > 0 && rc.second <= 8);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    string x, y;
    int T;
    cin>>T;
    while(T--)
    {
        cin.clear();
        cin>>x>>y;
        queue<pair<int, int>> q;
        pair<int, int> dist = make_pair(y[0]-'a', y[1]-'0');
        q.push(make_pair(x[0]-'a', x[1]-'0'));
 
        int level = 0;
        memset(board, 0, sizeof board);
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> p = q.front();
                q.pop();
                if(p == dist)
                {
                    cout<<level<<"\n";
                    break;
                }
                for(int u = 0; u < 8; u++)
                {
                    pair<int, int> tmp;
                    tmp.first = p.first + x_move[u];
                    tmp.second = p.second + y_move[u];
                    if(valid(tmp) && !board[tmp.first][tmp.second-1])
                    {
                        q.push(tmp);
                        board[tmp.first][tmp.second-1] = true;
                    }
                }
            }
            level++;
        }
    }
return 0;
}
