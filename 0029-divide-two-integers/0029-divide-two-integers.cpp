class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((d << i) <= n) {
                n -= (d << i);
                quotient += (1LL << i);
            }
        }

        return isNegative ? -quotient : quotient;
    }
};