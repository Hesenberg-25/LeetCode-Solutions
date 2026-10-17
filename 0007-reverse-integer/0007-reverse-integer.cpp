class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;

        bool sign = false;
        if (x < 0) sign = true;

        int num = abs(x);
        int count = 0;

        if (num == 0) return 0;

        int temp = num;
        while (temp > 0) {
            temp /= 10;
            count++;
        }

        long long ans = 0;
        for (int i = count - 1; i >= 0; i--) {
            ans += (long long)(num % 10) * round(pow(10, i));
            num /= 10;
        }

        if (sign) ans = -ans;
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }

        return (int)ans;
    }
};