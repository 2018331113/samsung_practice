#include <iostream>
#define sf scanf
using namespace std;
int findMaxPoints(int row, int col, int bombs, char matrix[][5])
{
    if (row <= 0 || col < 0 || col >= 5)
        return 0;
    int answer = 0;
    if (row > 0 && matrix[row - 1][col] != '2')
    {
        answer = max(answer, (matrix[row - 1][col] == '1' ? 1 : 0) + findMaxPoints(row - 1, col, bombs, matrix));
    }
    if (col > 0 && row > 0 && matrix[row - 1][col - 1] != '2')
    {
        answer = max(answer, (matrix[row - 1][col - 1] == '1' ? 1 : 0) + findMaxPoints(row - 1, col - 1, bombs, matrix));
    }
    if (col < 4 && row > 0 && matrix[row - 1][col + 1] != '2')
    {
        answer = max(answer, (matrix[row - 1][col + 1] == '1' ? 1 : 0) + findMaxPoints(row - 1, col + 1, bombs, matrix));
    }
    // cout<<answer<<row<<col<<endl;
    if (answer == 0 && bombs > 0)
    {
        if (row - 1 < 0)
        {
        }
        else
        {
            int k = max(0, row - 5);
            for (int i = row; i >= k; i--)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (matrix[i][j] == '2')
                        matrix[i][j] = '0';
                }
            }
        }
        answer = findMaxPoints(row, col, bombs - 1, matrix);
    }
    return answer;
}
int main()
{
    int t;
    cin >> t;
    int m = 0;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char mat[n + 1][5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> mat[i][j];
            }
        }
        cout << "#" << ++m << " " << findMaxPoints(n, 2, 1, mat) << endl;
    }
}
