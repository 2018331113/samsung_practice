class Solution
{
public:
    int fn(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {

        if (i > j || j < i)
            return 0;
        if (i == j)
            return v[i - 1] * v[i] * v[i + 1];
        if (dp[i][j] != -1)
            return dp[i][j];
        int m = INT_MIN, tmp;
        for (int k = i; k <= j; k++)
        {
            tmp = v[i - 1] * v[k] * v[j + 1] + fn(i, k - 1, v, dp) + fn(k + 1, j, v, dp);
            m = max(m, tmp);
        }
        return dp[i][j] = m;
    }

    int maxCoins(vector<int> &num)
    {

        int n = num.size();
        vector<int> v(n + 2, 1);
        for (int i = 1; i <= n; i++)
        {
            v[i] = num[i - 1];
        }
        vector<vector<int>> dp(n + 4, vector<int>(n + 4, -1));
        return fn(1, n, v, dp);
    }
};