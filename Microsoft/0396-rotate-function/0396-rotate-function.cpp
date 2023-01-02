class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int mx = INT_MIN;
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> dp(n, 0);
        int sum = 0, curr = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];                         // sum stores the sum of elements of nums, while curr stores the modified sum of the current configuration of nums (without rotation)
            curr += (i*nums[i]);
        }
        mx = dp[0] = curr;                          // initialising the dp with the current configuration
        for (int i=1; i<n; i++) {                   // if we want to rotate the ith element we simply use math from the previous config of nums and add sum to it which is just (size * (n-i)th element) greater than the required rotation function for the ith rotation
            dp[i] = dp[i-1] + sum - n*nums[n-i];
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};


/* 
F[i] = F[i-1] + sum - n* nums[n-i-1]
ex: [p,q,r,s] sum = p+q+r+s F[0] = q+2r+3s

after rotation [s,p,q,r]
sum = p+q+r+s
F[1] = p+2q+3r
F[0] + sum = q+2r+3s + p+q+r+s = p+2q+3r+4s
F[0] + sum - n*(n-1)th element = p + 2q + 3r = F[1]
*/