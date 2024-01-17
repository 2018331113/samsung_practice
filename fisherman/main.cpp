#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int g1, g2, g3, n1, n2, n3;
    cin >> g1 >> n1 >> g2 >> n2 >> g3 >> n3;
    int mn = INT_MAX;
    for (int i = 1; i <= n - n2 - n3; i++)
    {
        for (int j = i + n1; j <= n - n3; j++)
        {
            for (int k = j + n2; k <= n; k++)
            {
                int d = 0;
                for (int p = i; p < i + n1; p++)
                {
                    d += abs(g1 - p);
                }
                for (int p = j; p < j + n2; p++)
                {
                    d += abs(g2 - p);
                }
                for (int p = k; p < k + n3; p++)
                {
                    d += abs(g3 - p);
                }
                d += n1 + n2 + n3;
                mn = min(mn, d);
            }
        }
    }
    cout << mn << endl;
}