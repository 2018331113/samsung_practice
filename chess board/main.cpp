#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

int mv[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
vector<pair<int, int>> moves(int x, int y, int n, int m)
{
    vector<pair<int, int>> v;
    for(int i = 0; i < 8; i++)
    {
        int a = x + mv[i][0];
        int b = y + mv[i][1];
        if(isValid(a, b, n, m))
        {
            v.push_back(make_pair(a, b));
        }
    }
    return v;
}

int bfs(int x, int y, vector<vector<int>> &chess)
{

    int n = chess.size();
    int m = chess[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(chess[p.first][p.second]==1){
            return dist[p.first][p.second];
        }
        vector<pair<int, int>> v = moves(p.first, p.second, n, m);
        for (int i = 0; i < v.size(); i++)
        {
            int a = v[i].first;
            int b = v[i].second;
            if (dist[a][b] > dist[p.first][p.second] + 1)
            {
                dist[a][b] = dist[p.first][p.second] + 1;
                q.push({a, b});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int r, c, s, k;
        cin >> r >> c >> s >> k;
        vector<vector<int>> chess(n, vector<int>(m, 0));

        chess[s - 1][k - 1] = 1;
        cout <<"answer: " <<bfs(r - 1, c - 1, chess)<<endl;
    }
}