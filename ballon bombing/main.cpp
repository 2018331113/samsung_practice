#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int burstBallon1(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if (i > j || j < i)
        return 0;

    if (i == j)
        return v[i - 1] * v[i] * v[i + 1];

    if (dp[i][j] != -1)
        return dp[i][j];

    int m = INT_MIN, temp;

    for (int k = i; k <= j; k++)
    {
        temp = v[i - 1] * v[k] * v[j + 1] + burstBallon1(i, k - 1, v, dp) + burstBallon1(k + 1, j, v, dp);
        m = max(m, temp);
    }
    return dp[i][j] = m;
}

int burstBallon2(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if (i > j || j < i)
        return 0;

    if (i == j)
        return v[i - 1] * v[i + 1];

    if (dp[i][j] != -1)
        return dp[i][j];

    int m = INT_MIN, temp;

    for (int k = i; k <= j; k++)
    {
        if (i == 1 && j == v.size() - 2)
        {
            temp = v[k] + burstBallon1(i, k - 1, v, dp) + burstBallon1(k + 1, j, v, dp);
        }
        else
        {
            temp = v[i - 1] * v[k] * v[j + 1] + burstBallon1(i, k - 1, v, dp) + burstBallon1(k + 1, j, v, dp);
        }
        m = max(m, temp);
    }
    return dp[i][j] = m;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 2);
    nums[0] = nums[n + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> dp(n + 4, vector<int>(n + 4, -1));

    cout << "ans: " << burstBallon1(1, n, nums, dp) << endl;

    return 0;
}