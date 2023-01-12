class Solution {
public:
    string longestPrefix(string s) {
//         vector<string> prefix, suffix;
        int n = s.size();
//         string prev, temp;
//         for (int i=0; i<n-1; i++) {
//             prev += s[i];
//             temp = s.substr(i+1, n-i);
//             prefix.push_back(prev);
//             suffix.push_back(temp);
//         }     
        
//         for (int i=n-2; i>=0; i--) {
//             if (find(suffix.begin(), suffix.end(), prefix[i]) != suffix.end())
//                 return prefix[i];
//         }
        
        vector<int> prefix(n, 0);
        int i=1, j=0;
         // refer nptes
        while (i<n) {
            if (s[i] == s[j]) {
                prefix[i] = j+1;
                i++;
                j++;
            }
            else if (j == 0)
                i++;
            else
                j = prefix[j-1];
        }
        
//         for (auto x: prefix) {
//             cout<<x<<endl;
//         }
        
//         for (auto x: suffix) {
//             cout<<x<<endl;
//         }
        return s.substr(0,j);
    }
};