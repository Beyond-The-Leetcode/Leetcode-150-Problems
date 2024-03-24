#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto it : nums)
        {
            mp[it]++;
        }

        int elem = 0, maxi = -1;
        for (auto it : mp)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
                elem = it.first;
            }
        }

        int n = nums.size();
        if (maxi > (n / 2))
        {
            return elem;
        }
        return -1;
    }
};

// optimal approach (kadane algo)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, elem = -1;

        for (auto it : nums)
        {
            if (cnt == 0)
            {
                cnt = 1;
                elem = it;
            }
            else if (elem == it)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        int freq = 0;
        for (auto it : nums)
        {
            if (it == elem)
            {
                freq++;
            }
        }

        int n = nums.size();
        return (freq > (n / 2) ? elem : -1);
    }
};

int main()
{

    return 0;
}