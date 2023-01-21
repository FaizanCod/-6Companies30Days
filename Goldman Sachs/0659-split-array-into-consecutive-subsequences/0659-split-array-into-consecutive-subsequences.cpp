class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        // nums is sorted
        // we can traverse linearly and check if there is an availability for an element to join an existing subsequence or to create its own
        
        unordered_map<int, int> freq;
        // hypothetical map to visualize if there is any upcoming element in nums that can be added to the already existing subsequence ending with the current element
        // key -> value : next element -> no of requirements to fill already existing subsequences
        unordered_map<int, int> hypo;
        
        for (auto x: nums)
            freq[x]++;
        
        for (auto x: nums) {
            if (freq[x] == 0)
                continue;
            // checking if there is any place for the curr element to fit into the existing subsequences
            if (hypo[x] > 0) {
                // decrementing the curr requirement
                hypo[x]--;
                // incrementing the next (curr+1) element's requirement
                hypo[x+1]++;
                // curr element taken care of
                freq[x]--;
            }
            // generating a new subsequence of length atleast three by checking if there are available elements
            else if (freq[x] > 0 && freq[x+1] > 0 && freq[x+2] > 0) {
                // creating space for the next element to be a part of subsequence if it is in nums
                hypo[x+3]++;
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
            }
            // if there cannot be a subsequence of length 3 due to unavailibility of elements in nums
            else
                return false;
        }
        return true;
    }
};