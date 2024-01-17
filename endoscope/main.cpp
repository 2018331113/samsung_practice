#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool forUp(int value)
{
    if (value == 1 || value == 2 || value == 5 || value == 6)
    {
        return true;
    }
    return false;
}

bool forDown(int value)
{
    if (value == 1 || value == 2 || value == 4 || value == 7)
    {
        return true;
    }
    return false;
}

bool forLeft(int value)
{
    if (value == 1 || value == 3 || value == 4 || value == 5)
    {
        return true;
    }
    return false;
}

bool forRight(int value)
{
    if (value == 1 || value == 3 || value == 6 || value == 7)
    {
        return true;
    }
    return false;
}
vector<pair<int, int>> getNeighbours(int i, int j, vector<vector<int>> &map)
{
    vector<pair<int, int>> v;
    int n = map.size();
    int m = map[0].size();
    if (map[i][j] == 1)
    {
        // cout << "for 1: " << i << " " << j << endl;
        if (isValid(i - 1, j, n, m) && forUp(map[i - 1][j]))
        {
            // cout << "for up: " << i - 1 << " " << j << endl;
            v.push_back(make_pair(i - 1, j));
        }
        if (isValid(i + 1, j, n, m))
        {
            if (forDown(map[i + 1][j]))
            {
                v.push_back(make_pair(i + 1, j));
            }
        }
        if (isValid(i, j - 1, n, m))
        {
            if (forLeft(map[i][j - 1]))
            {
                v.push_back(make_pair(i, j - 1));
            }
        }
        if (isValid(i, j + 1, n, m))
        {
            if (forRight(map[i][j + 1]))
            {
                v.push_back(make_pair(i, j + 1));
            }
        }
    }
    else if (map[i][j] == 2)
    {
        if (isValid(i - 1, j, n, m))
        {
            if (forUp(map[i - 1][j]))
            {
                v.push_back(make_pair(i - 1, j));
            }
        }
        if (isValid(i + 1, j, n, m))
        {
            if (forDown(map[i + 1][j]))
            {
                v.push_back(make_pair(i + 1, j));
            }
        }
    }
    else if (map[i][j] == 3)
    {
        if (isValid(i, j - 1, n, m))
        {
            if (forLeft(map[i][j - 1]))
            {
                v.push_back(make_pair(i, j - 1));
            }
        }
        if (isValid(i, j + 1, n, m))
        {
            if (forRight(map[i][j + 1]))
            {
                v.push_back(make_pair(i, j + 1));
            }
        }
    }
    else if (map[i][j] == 4)
    {
        if (isValid(i - 1, j, n, m))
        {
            if (forUp(map[i - 1][j]))
            {
                v.push_back(make_pair(i - 1, j));
            }
        }
        if (isValid(i, j + 1, n, m))
        {
            if (forRight(map[i][j + 1]))
            {
                v.push_back(make_pair(i, j + 1));
            }
        }
    }
    else if (map[i][j] == 5)
    {
        if (isValid(i + 1, j, n, m))
        {
            if (forDown(map[i + 1][j]))
            {
                v.push_back(make_pair(i + 1, j));
            }
        }
        if (isValid(i, j + 1, n, m))
        {
            if (forRight(map[i][j + 1]))
            {
                v.push_back(make_pair(i, j + 1));
            }
        }
    }
    else if (map[i][j] == 6)
    {
        if (isValid(i + 1, j, n, m))
        {
            if (forDown(map[i + 1][j]))
            {
                v.push_back(make_pair(i + 1, j));
            }
        }
        if (isValid(i, j - 1, n, m))
        {
            if (forLeft(map[i][j - 1]))
            {
                v.push_back(make_pair(i, j - 1));
            }
        }
    }
    else if (map[i][j] == 7)
    {
        if (isValid(i - 1, j, n, m))
        {
            if (forUp(map[i - 1][j]))
            {
                v.push_back(make_pair(i - 1, j));
            }
        }
        if (isValid(i, j - 1, n, m))
        {
            if (forLeft(map[i][j - 1]))
            {
                v.push_back(make_pair(i, j - 1));
            }
        }
    }
    return v;
}

void bfs(int x, int y, int l, vector<vector<int>> &map, int &cnt)
{

    queue<pair<int, int>> q;
    vector<vector<int>> level(map.size(), vector<int>(map[0].size(), 0));
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    q.push(make_pair(x, y));
    level[x][y] = 1;
    visited[x][y] = true;
    while (!q.empty() && level[q.front().first][q.front().second] <= l)
    {
        pair<int, int> p = q.front();
        q.pop();
        cnt++;

        vector<pair<int, int>> v = getNeighbours(p.first, p.second, map);

        for (int i = 0; i < v.size(); i++)
        {
            if (!visited[v[i].first][v[i].second])
            {
                q.push(v[i]);
                visited[v[i].first][v[i].second] = true;
                level[v[i].first][v[i].second] = level[p.first][p.second] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int r, c;
        cin >> r >> c;
        int l;
        cin >> l;
        vector<vector<int>> map(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
            }
        }
        int cnt = 0;
        if (map[r][c] == 0)
        {
            cout << 0 << endl;
            continue;
        }
        bfs(r, c, l, map, cnt);
        cout << cnt << endl;
    }

    return 0;
}

/*
2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1

*/