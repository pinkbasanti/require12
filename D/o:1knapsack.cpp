#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack problem using dynamic programming

struct item
{
    int weight;
    int value;
};

int knapsack(int W, item arr[], int n)
{
    // create a 2D array to store the results of subproblems
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[i - 1].weight <= j)
            {
                /*if the weight of the item is less than or equal to the capacity of the knapsack then we have two options
                either we include the item or we don't include the item in the knapsack and we take the maximum of the two
                values */
                dp[i][j] = max(arr[i - 1].value + dp[i - 1][j - arr[i - 1].weight], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << "Enter the weight and value of each item: ";
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].weight >> arr[i].value;
    }
    cout << "Maximum value that can be put in knapsack is: " << knapsack(W, arr, n);

    return 0;
}
