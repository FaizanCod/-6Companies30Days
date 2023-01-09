// reordering
// (nums1[i] - nums2[i]) - (nums1[j] - nums2[j]) <= diff
// nums[i] - nums[j] <= diff                    // bringing i and j indexes together, i < j
// OR nums[i] <= nums[j] + diff

// once we fix a value of nums[j] on RHS, we just need to find the value of i in the other divided array where nums[i] <= constant value
// create a new array nums where nums[i] = nums1[i] - nums2[i]

class Solution {
public:
    long long res = 0;
    void merge(vector<int> &nums, int s, int mid, int e, int diff) {
        vector<int> temp(e-s+1);            // the temp array to store the merging
        int i = s;
        int j = mid+1;
        int idx = 0;
        
        while (i <= mid && j<=e) {
            if (nums[i] <= diff + nums[j]) {
                res += (e - j + 1);             // all of the elements from 0 till j are the answers, since the array is sorted
                i++;
            }
            else
                j++;
        }
        
        // merging the array back
        i = s;
        j = mid+1;
        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j])
                temp[idx++] = nums[i++];
            else
                temp[idx++] = nums[j++];
        }
        // merging left out parts
        while (i<=mid)
            temp[idx++] = nums[i++];
        while (j<=e)
            temp[idx++] = nums[j++];
        
        // storing back the sorted array in nums after pairs counted
        idx = 0;
        for (int i=s; i<=e; i++, idx++)
            nums[i] = temp[idx];
    }
    
    void mergeSort(int s, int e, vector<int> &nums, int diff) {
        if (s >= e)
            return;
        int mid = s + (e-s) / 2;
        // now since we have broken down the array into two separate parts, we can sort them and apply binary search to find nums[i] <= const
        mergeSort(s, mid, nums, diff);
        mergeSort(mid+1, e, nums, diff);
        merge(nums, s, mid, e, diff);
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums;
        int n = nums1.size();
        for (int i=0; i<n; i++)
            nums.push_back(nums1[i] - nums2[i]);
        
        // divide and conquer, we divide the array into two parts each time, one part gives i other gives j, and then we combine results to a single array
        mergeSort(0, n-1, nums, diff);
        return res;
    }
};