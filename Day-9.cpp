#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution
{
public:
    bool helper(int idx, int n, vector<int> &arr, vector<int> &dp)
    {
        if (idx >= n)
            return false;
        if (idx == n - 1)
            return true;
        if (dp[idx] != -1)
            return dp[idx];

        int range = arr[idx];
        bool ans = false;

        for (int i = 1; i <= range; i++)
        {
            if (idx + i < n)
            {
                ans = ans || helper(idx + i, n, arr, dp);
            }
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(0, n, nums, dp);
    }
};

// Positional Distance
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reachable = 0;

        for (int i = 0; i < n; i++)
        {
            if (reachable < i)
            {
                return false;
            }

            reachable = max(reachable, i + nums[i]);
        }

        return true;
    }
};

int main()
{

    return 0;
}