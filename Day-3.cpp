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
            nums.push_back(it.first);
        }

        return nums.size();
    }
};

// better approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto it = nums.begin();

        while (it != nums.end())
        {
            if (it + 1 != nums.end())
            {
                auto ni = it + 1;
                while (ni != nums.end())
                {
                    if (*ni == *it)
                    {
                        ni = nums.erase(ni);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            it++;
        }

        return nums.size();
    }
};

// optimal
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return 1;
        else
        {
            int first = 0, vacant = 1, last = 0;
            while (last < n)
            {
                if (nums[first] != nums[last])
                {
                    nums[vacant] = nums[last];
                    first++;
                    vacant++;
                }
                last++;
            }
            return first + 1;
        }
    }
};

int main()
{

    return 0;
}