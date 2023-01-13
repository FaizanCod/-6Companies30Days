class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int boomerangs = 0;
        int n = points.size();
        
        for (int i=0; i<n; i++) {
            // to store distances with the count
            unordered_map<int, int> distances;
            for (int j=0; j<n; j++) {
                // no need to find distance of point from itself
                if (i != j) {
                    int dist = pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2);
                    distances[dist]++;
                }
            }
            for (auto x: distances)
                boomerangs += x.second*(x.second-1);
        }
        return boomerangs;
    }
};

/*
Considering points A,B,C,D,E, where distance of each pt from A is k
Possible pairs A-> (BC,BD,BE,CD,CE,DE, CB,DB,EB,DC,EC,ED) = 12 = 2 * 6 = 2 * 4C2 = 4 * (4-1)
(nCr => n, number of points at dist k, r, number of choice to make (in our case we want pairs, r=2)) 
= n(n-1)
*/