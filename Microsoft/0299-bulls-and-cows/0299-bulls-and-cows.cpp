class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> mp;            // element, freq
        for (int i=0; i<n; i++) {
            if (secret[i] == guess[i])          // if the ith elements match, increment bulls
                bulls++;
            else
                mp[secret[i]]++;                // else update the freq of the ith character from secret in map
        }
        for (int i=0; i<n; i++) {
            if (secret[i] != guess[i]) {            // if the ith elements differ
                if (mp[guess[i]] > 0) {             // if the freq of the ith element in guess is still non-zero, we update cows for each element in guess
                    cows++;
                    mp[guess[i]]--;
                    // if the element is non-existent in secret, the map wont contain the element
                    // if the guess contains more no of elements than freq, the map simply runs out of freq for that element
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};