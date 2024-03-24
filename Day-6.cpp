#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        while (k > 0)
        {
            auto it = nums.end() - 1;
            int temp = *it;
            it = nums.erase(it);
            nums.insert(nums.begin(), temp);
            k--;
        }
    }
};
// optimal approach
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{

    return 0;
}