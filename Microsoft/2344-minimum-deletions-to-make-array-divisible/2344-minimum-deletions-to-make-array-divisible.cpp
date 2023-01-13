class Solution {
public:
    int gcd (int a, int b) {
        if (a == 0)
          return b;
        return gcd(b % a, a);
    }

    int findGCD(vector<int> &arr) {
        int res = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++) {
          res = gcd(arr[i], res);
          if(res == 1)
              return 1;
        }
        return res;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = findGCD(numsDivide);
        // finding out the gcd of numbers in numsDivide
        
        sort(nums.begin(), nums.end());
        // so that all minimum numbers to be deleted come at start
        
        for (int i=0; i<nums.size(); i++) {
            // if the gcd is divided by the ith nums element, the indexes before it can be deleted
            if (gcd % nums[i] == 0)
                return i;
        }
        return -1;
    }
};