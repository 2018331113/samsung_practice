/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.

Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.

Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them

Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

Output - 
1
2
2
12
15
4
*/


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool isValid(int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

vector<pair<int, int>> neighbors(int x, int y, vector<vector<int>> &space, int n)
{
    vector<pair<int, int>> v;
    if (isValid(x - 1, y, n) && space[x - 1][y] == 1)
    {
        v.push_back(make_pair(x - 1, y));
    }
    if (isValid(x + 1, y, n) && space[x + 1][y] == 1)
    {
        v.push_back(make_pair(x + 1, y));
    }
    if (isValid(x, y - 1, n) && space[x][y - 1] == 1)
    {
        v.push_back(make_pair(x, y - 1));
    }
    if (isValid(x, y + 1, n) && space[x][y + 1] == 1)
    {
        v.push_back(make_pair(x, y + 1));
    }
    return v;
}

int bfs(int i, int j, vector<vector<bool>> &elements, vector<vector<int>> &space, int m)
{
    if (space[i][j] == 0)
    {
        return 1000;
    }
    int n = space.size();

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int dis = -1;
    while (!q.empty() && m > 0)
    {
        pair<int, int> p = q.front();
        q.pop();
        if (!visited[p.first][p.second])
        {

            visited[p.first][p.second] = true;
            if (elements[p.first][p.second])
            {
                m--;
                // cout << "m: " << m << endl;
            }

            dis = dist[p.first][p.second];
            // cout << p.first << " " << p.second << " " << dis << endl;
            if (m == 0)
                break;
            vector<pair<int, int>> v = neighbors(p.first, p.second, space, n);

            for (int k = 0; k < v.size(); k++)
            {
                if (!visited[v[k].first][v[k].second])
                {
                    dist[v[k].first][v[k].second] = dist[p.first][p.second] + 1;

                    q.push(v[k]);
                }
            }
        }
    }

    return dis;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> elements(n, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            elements[x - 1][y - 1] = true;
        }
        vector<vector<int>> space(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> space[i][j];
            }
        }
        int ans = 1000;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int dis = bfs(i, j, elements, space, m);
                // cout<<i<<" "<<j<<" "<<dis<<endl;
                ans = min(ans, dis);
            }
        }

        cout << "answer: "<<ans << endl;
    }

    return 0;
}
