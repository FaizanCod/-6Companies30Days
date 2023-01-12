class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums.begin(), nums.end());       // sort a copy of nums
        sort(sorted.begin(), sorted.end());
        int r = n, l = 0;
        for (int i=0; i<n; i++) {
            if (sorted[i] != nums[i]) {                     // for each element check for the non-matching of elements
                r = min(r, i);              // r reduces and l increases
                l = max(l, i);
            }
        }
        return (l<=r) ? 0 : (l-r+1);        // if l does goes beyond r, return 0
    }
};