#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int ANS;
int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void shortestPath(int sx, int sy, int dx, int dy, int dis, vector<vector<int>> &customer, vector<bool> visited, int count)
{
    if (count == customer.size())
    {
        ANS = min(ANS, distance(sx, sy, dx, dy) + dis);
    }

    for (int i = 0; i < customer.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            int tx = customer[i][0];
            int ty = customer[i][1];
            int d = distance(sx, sy, tx, ty);
            shortestPath(tx, ty, dx, dy, dis + d, customer, visited, count + 1);
            visited[i] = false;
        }
    }
}

int main()
{

    int t = 10;
    while (t--)
    {
        ANS = INT_MAX;
        int n;
        cin >> n;
        int sx, sy, dx, dy;
        cin >> dx >> dy >> sx >> sy;
        vector<vector<int>> customer(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> customer[i][0] >> customer[i][1];
        }

        vector<bool> visited(n, false);
        shortestPath(sx, sy, dx, dy, 0, customer, visited,0);

        cout << "answer: " << ANS << endl;
    }

    return 0;
}