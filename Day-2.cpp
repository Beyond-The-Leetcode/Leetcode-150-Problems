#include <bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // make the extra array
        vector<int>ans;

        for(auto it : nums){
            // check the cond.
            if(it != val){
                ans.push_back(it);
            }
        }

        // erase the given array
        nums.clear();

        // modify the array
        for(auto it : ans){
            nums.push_back(it);
        }

        return ans.size();
    }
};

// Better approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // set the iterator at the beginning
        auto it = nums.begin(); // type --> int

        // traverse acc. to cond.
        while(it != nums.end()){
            if( *it == val ){
                it = nums.erase(it);
            }
            else{
                it++;
            }
        }

        return nums.size();
    }
};

// Optimal approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first = 0;
        int last = 0;
        int n = nums.size();

        while( last < n ){
            if(nums[last] != val){
                nums[first] = nums[last];
                first++;
                last++;
            }
            else{
                last++;
            }
        }

        return first;
    }
};

int main(){
    
    return 0;
}