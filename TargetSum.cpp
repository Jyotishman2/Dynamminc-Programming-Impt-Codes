
#include<bits/stdc++.h>
using namespace std;

class Solution {
       long long countSubsets(vector<int>& nums, int ind, int target, vector<vector<long long>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2; 
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        long long notPick = countSubsets(nums, ind - 1, target, dp);

        long long pick = 0;
        if (nums[ind] <= target)
            pick = countSubsets(nums, ind - 1, target - nums[ind], dp);

        return dp[ind][target] = pick + notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;

   
        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0)
            return 0;

        int subsetSum = (totalSum - target) / 2;

        vector<vector<long long>> dp(n, vector<long long>(subsetSum + 1, -1));

        return (int)countSubsets(nums, n - 1, subsetSum, dp);
    }
};