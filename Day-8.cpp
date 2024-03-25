#include <bits/stdc++.h>
using namespace std;

// Recursion approach
class Solution
{
public:
    int helper(int idx, int n, vector<int> &arr, int buy)
    {
        if (idx >= n)
            return 0;

        int profit = 0;
        if (buy)
        {
            profit = max(-arr[idx] + helper(idx + 1, n, arr, 0),
                         0 + helper(idx + 1, n, arr, 1));
        }
        else
        {
            profit = max(arr[idx] + helper(idx + 1, n, arr, 1),
                         0 + helper(idx + 1, n, arr, 0));
        }

        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int buy = 1, n = prices.size();
        return helper(0, n, prices, buy);
    }
};

// Memoization approach
class Solution
{
public:
    int helper(int idx, int n, vector<int> &arr, int buy, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy)
        {
            dp[idx][buy] = max(-arr[idx] + helper(idx + 1, n, arr, 0, dp),
                               0 + helper(idx + 1, n, arr, 1, dp));
        }
        else
        {
            dp[idx][buy] = max(arr[idx] + helper(idx + 1, n, arr, 1, dp),
                               0 + helper(idx + 1, n, arr, 0, dp));
        }

        return dp[idx][buy];
    }
    int maxProfit(vector<int> &prices)
    {
        int buy = 1, n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, n, prices, buy, dp);
    }
};

// Greedy approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n == 0)
            return 0;

        int buy = prices[0], profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > buy)
            {
                profit += (prices[i] - buy);
            }
            buy = prices[i];
        }

        return profit;
    }
};

int main()
{

    return 0;
}