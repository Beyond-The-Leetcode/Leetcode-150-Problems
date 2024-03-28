#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    int helper(int idx, int n, vector<int> &arr)
    {
        if (idx == n - 1)
            return 0;

        int jump = arr[idx], mini = 1e9;
        for (int i = idx + 1; i <= min(idx + jump, n - 1); i++)
        {
            int val = 1 + helper(i, n, arr);
            mini = min(mini, val);
        }

        return mini;
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        return helper(0, n, nums);
    }
};

// memoization
class Solution
{
public:
    int helper(int idx, int n, vector<int> &arr, vector<int> &dp)
    {
        if (idx == n - 1)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int jump = arr[idx], mini = 1e9;
        for (int i = idx + 1; i <= min(idx + jump, n - 1); i++)
        {
            int val = 1 + helper(i, n, arr, dp);
            mini = min(mini, val);
        }

        return dp[idx] = mini;
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(0, n, nums, dp);
    }
};

// greedy
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, cnt = 0;

        while (j < n - 1)
        {
            int maxi = 0;
            for (int pos = i; pos <= j; pos++)
            {
                maxi = max(maxi, pos + nums[pos]);
            }

            i++;
            j = maxi;
            cnt++;
        }

        return cnt;
    }
};

int main()
{

    return 0;
}