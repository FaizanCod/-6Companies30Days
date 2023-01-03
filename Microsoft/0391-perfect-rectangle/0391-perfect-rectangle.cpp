class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int a = INT_MAX, b = INT_MAX;
        // (a, b) represent the bottom left corner of the resultant rectangle
        int c = INT_MIN, d = INT_MIN;
        // (C, D) represent the top right corner of the resultant rectangle
        long long area = 0;
        unordered_set<string> coord;                    // we also need to store all the 4 coordinates of the rectangle and if the point repeats we remove that point
        for (auto rect: rectangles) {
            long long height = rect[3] - rect[1], width = rect[2] - rect[0];
            // adding up areas of each individual rectangles
            area += (height) * abs(width);
            // cout<<"area: "<<area<<endl;
            a = min(a, rect[0]);
            b = min(b, rect[1]);
            c = max(c, rect[2]);
            d = max(d, rect[3]);                            // finding out the coordinates of the resultant rectangle 
            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            
            // storing coordinates in set
            string s1 = to_string(rect[0]) + ", " + to_string(rect[1]);         // points are (x1, y1), (x1, y2), (x2, y1) and (x2, y2)
            string s2 = to_string(rect[0]) + ", " + to_string(rect[3]);
            string s3 = to_string(rect[2]) + ", " + to_string(rect[1]);
            string s4 = to_string(rect[2]) + ", " + to_string(rect[3]);
            
            if (coord.find(s1) == coord.end()) coord.insert(s1);  else coord.erase(s1);
            if (coord.find(s2) == coord.end()) coord.insert(s2);  else coord.erase(s2);
            if (coord.find(s3) == coord.end()) coord.insert(s3);  else coord.erase(s3);
            if (coord.find(s4) == coord.end()) coord.insert(s4);  else coord.erase(s4);
            // if the set doesnt contain the coord, insert it, otherwise erase it
        }
        if (
            coord.find(to_string(a) + ", " + to_string(b)) == coord.end() ||
            coord.find(to_string(a) + ", " + to_string(d)) == coord.end() ||
            coord.find(to_string(c) + ", " + to_string(b)) == coord.end() ||
            coord.find(to_string(c) + ", " + to_string(d)) == coord.end() ||
            coord.size() != 4
           )
            return false;                                                   
        // if the coordinate of the resultant rectangle doesnt exist in the set, it cannot be a covered rectangle, also the size of the remaining set must be 4, ie, the sides of the resultant rectangle
        
        long long resArea = (long long)(c-a) * (long long)(d-b);
        // cout<<"resArea: "<<resArea<<endl;
        if (area != resArea)
            return false;
        return true;
    }
};