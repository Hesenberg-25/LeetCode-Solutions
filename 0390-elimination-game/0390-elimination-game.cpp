class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool from_left = true;
        while (n > 1) {
            if (from_left || n % 2 == 1)
                head += step;
            n /= 2;
            step *= 2;
            from_left = !from_left;
        }
        return head;
    }
};   