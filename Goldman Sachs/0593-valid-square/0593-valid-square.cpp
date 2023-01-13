class Solution {
public:
    int dist(vector<int> &a, vector<int> &b) {
        return pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2); 
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st;
        // finding dist of each point from each point
        st.insert(dist(p1, p2));
        st.insert(dist(p1, p3));
        st.insert(dist(p1, p4));
        st.insert(dist(p2, p3));
        st.insert(dist(p2, p4));
        st.insert(dist(p3, p4));
        // size 2 for equal sides and one diagonal
        if (st.size() == 2) {
            for (auto s: st) {
                if (s == 0)     // if any of the side is zero
                    return false;
            }
            return true;
        }
        // since set size != 2
        return false;
    }
};