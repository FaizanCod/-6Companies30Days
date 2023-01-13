class Solution {
public:
    int numberOfSubstrings(string s) {
        // three pointers for a, b, c
        // We will check if i is greater than 1
        // If i is greater than 1, we will add the minimum of the three pointers to the result
        // The minimum of the three pointers will give us the index of the last character in the substring
        int a = -1, b = -1, c = -1;
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a')
                a = i;
            if (s[i] == 'b')
                b = i;
            if (s[i] == 'c')
                c = i;
            if (i > 1)
                // +1 to nullify -1 index, and if the lowest index is i the substrings starting with i and ending with the last index of occurrence of a/b/c so formed are i+1
                ans += min({a, b, c}) + 1;
        }
        return ans;
    }
};