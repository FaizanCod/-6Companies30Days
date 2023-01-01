void helper (int s, int e, vector<int> curr, vector<vector<int>> &res, int sz, int target) {
    // if target is 0, sum is reached
    // and the size of curr has reached the size limit sz
    if (target == 0 && sz == curr.size()) {
        res.push_back(curr);
        return ;
    }
    
    for (int i=s; i<=e; i++) {
        curr.push_back(i);      // subset starting with i
        helper(i+1, e, curr, res, sz, target-i);      // generating subsets from i+1 till end, having a target of sum - i, since i has already been added to the subset
        // for (auto x: curr)
        //     cout<<x<<" ";
        // cout<<endl;
        curr.erase(curr.end()-1);           // removing the last element so added, to get the neighbouring node of the recursive tree, so that branching can continue further from that node
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int range[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};          // all possible numbers which can be chosen at most once (can be chosen or cannot be chosen, only two options)
        // we need to choose k numbers from this range such that the sum is n
        // combinations -> subsets of range
        int s = accumulate(range, range+k, 0);
        // cout<<s<<endl;
        if (s > n)
            return {};
        s = accumulate(range+9-k, range+9, 0);
        // cout<<s<<endl;
        if (s < n)
            return {};
        vector<vector<int>> res;
        vector<int> curr;
        helper(1, 9, curr, res, k, n);            // 1-9 range of integers, result in res, k is the size limit, n is the sum limit, curr used as a temp container for backtracking
        return res;
    }
};