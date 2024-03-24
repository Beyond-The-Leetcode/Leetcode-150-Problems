#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        map<int, int> mp;

        for (auto it : nums)
        {
            mp[it]++;
        }

        nums.clear();

        for (auto it : mp)
        {
            int i = 0;
            while (it.second > 0 && i < 2)
            {
                nums.push_back(it.first);
                i++;
                it.second--;
            }
        }

        return nums.size();
    }
};

// optimal approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
            return n;

        int first = 0, last = 0;
        while (last < n)
        {
            if (first - 2 >= 0 && nums[first - 2] == nums[last])
            {
                last++;
                continue;
            }

            nums[first] = nums[last];
            last++;
            first++;
        }

        return first;
    }
};

int main()
{

    return 0;
}