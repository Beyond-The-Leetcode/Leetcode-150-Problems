#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;
    }
};

// optimal approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxi = INT_MIN, mini = INT_MAX;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }

        return maxi;
    }
};

int main()
{

    return 0;
}