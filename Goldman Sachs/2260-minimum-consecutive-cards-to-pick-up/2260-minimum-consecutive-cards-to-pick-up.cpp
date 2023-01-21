class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int ans = INT_MAX;
        // TLE
        // for (int i=0; i<n-1; i++) {
        //     for (int j=i+1; j<n; j++) {
        //         if (cards[i] == cards[j])
        //             ans = min(ans, j-i+1);
        //     }
        // }
        
        unordered_map<int, int> mp;         // element, index
        for (int i=0; i<n; i++) {
            if (mp.find(cards[i]) != mp.end())
                // finding the previous index from map
                ans = min(ans, i-mp[cards[i]]+1);
            mp[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};