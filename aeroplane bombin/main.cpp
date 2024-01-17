#include <bits/stdc++.h>

using namespace std;

int aeroplaneBombing(int r, int c, vector<vector<char>> &space, bool bomb, int isSafe, int coin)
{
    // base case
    if (r < 0 || c < 0 || c >= 5)
    {
        return coin;
    }

    // recursive case
    if (space[r][c] == '1')
    {
        coin++;
    }
    else if (space[r][c] == '2')
    {
        if (bomb)
        {
            bomb = false;
            isSafe = 5;
        }
        else if (isSafe <= 0)
        {
           return coin;
        }
    }
    
    if(bomb==false) isSafe--;

    int s = aeroplaneBombing(r - 1, c, space, bomb, isSafe, coin);
    int l = aeroplaneBombing(r - 1, c - 1, space, bomb, isSafe, coin);
    int rr = aeroplaneBombing(r - 1, c + 1, space, bomb, isSafe, coin);

    return max(s, max(l, rr));
}

int main()
{
   // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int cnt=1;
    int t;
    cin >> t;
    while (t--)
    {
        int level;
        cin >> level;
        vector<vector<char>> space(level, vector<char>(5));
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> space[i][j];
            }
        }

        int s = aeroplaneBombing(level - 1, 2, space, true, 0, 0);
        int l = aeroplaneBombing(level - 1, 1, space, true, 0, 0);
        int r = aeroplaneBombing(level - 1, 3, space, true, 0, 0);

        cout << "#"<<cnt++<<" "<<max(s, max(l, r)) << endl;
    }

    return 0;
}
