class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());             // after sorting, this question is equivalent to 300. Longest Increasing Subsequence, with Tabulation and O(n) space
        vector<int> dp(n, 1), prevIndex(n);
        // prevIndex used to trace back the LIS so formed so as to print the LIS
        for (int ind=0; ind<n; ind++) {
            prevIndex[ind] = ind;               // storing the initial values of the prevIndex array
            for (int prev=0; prev<=ind-1; prev++) {
                if (nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]) {
                    // since elements are stored in sorted ascending, if a number nums[prev] divides nums[ind] and if there is another larger number nums[k] which divides nums[ind], then nums[prev] will divide nums[k]
                    // Ex: [3,6,18], 3 divides 6, 6 divides 18, that implies 3 divides 18 too
                    dp[ind] = 1 + dp[prev];
                    prevIndex[ind] = prev;        // storing the element to trace back to for LIS printing
                }
            }
        }
        auto itr = max_element(dp.begin(), dp.end());
        int i = itr - dp.begin();
        vector<int> ans;
        ans.push_back(nums[i]);
        while (prevIndex[i] != i) {
            i = prevIndex[i];
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};