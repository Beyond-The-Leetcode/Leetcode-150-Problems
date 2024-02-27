#include <bits/stdc++.h>
using namespace std;

// Approach 1 --> Brute force
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // make the another array
        vector<int>arr;

        // insert the n elements from nums1 and m elem. from num2
        for(int i=0; i<m; i++){
            arr.push_back(nums1[i]);
        }
        for(int i=0; i<n; i++){
            arr.push_back(nums2[i]);
        }

        // sort the array
        sort(arr.begin(), arr.end());

        // modify the array
        for(int i=0; i<arr.size(); i++){
            nums1[i] = arr[i];
        }
    }
};

// Approach 2 --> Better
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[i+m] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};

// Approach 3 --> Optimal
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=n+m-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main(){
    
    return 0;
}