class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // probability of nth seat being correct or not = 0.5
        // probability of choosing 1 seat out of n seats = 1/n
        // total probability out of n seats = ((1/n * 0.5) + (1/n * 0.5) + (1/n * 0.5) + ...) * n = 0.5
        
        // base cases, n = 1 , p = 1
        // n = 2 = p = 1/2
        
        if (n == 1)
            return 1.00000;
        else
            return 0.50000;
    }
};