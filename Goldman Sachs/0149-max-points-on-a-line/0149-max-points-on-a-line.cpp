class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mx = 1;               // no of max points that is possible = 1 (point itself)
        
        for (int i=0; i<n-1; i++) {
            unordered_map<double,int> mp;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=i+1; j<n; j++) {     // going to the next points after ith point
                int x2 = points[j][0], y2 = points[j][1];
                // cout<<"x2: "<<x2<<" y2: "<<y2<<" x1: "<<x1<<" y1: "<<y1<<endl;
                if (x1 != x2) {
                    double slope = (double)(y2 - y1) / (double) (x2 - x1);
                    mp[slope]++;
                }
                else {
                    mp[DBL_MAX]++;
                }
            }
            int tmp_mx = 0;                             // max points in a line after the ith point
            for (auto x: mp)
                tmp_mx = max(tmp_mx, x.second+1);       // including the point itself, if we need to update tmp_mx      
            mx = max(mx, tmp_mx);
        }
        return mx;
    }
};