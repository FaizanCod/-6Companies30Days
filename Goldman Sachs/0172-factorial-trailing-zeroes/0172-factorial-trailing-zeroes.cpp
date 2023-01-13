class Solution {
public:
    int trailingZeroes(int n) {
        // Number of trailing zeroes in n! = Number of times n! is divisible by 10 = Highest power of 10 which divides n! = Highest power of 5 in n! (since 2 is not the delimiter)
        if (n < 5)
            return 0;
        if (n == 5)
            return 1;
        long long c = 0;
        while (n >= 5) {
            c += floor(n / 5);
            n /= 5;
        }
        return c;
    }
};