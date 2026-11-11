class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long onlySingles = n1 * c1 + n2 * c2;

        long long common = min(n1, n2);
        long long remainderCost = 0;
        if (n1 > n2) {
            remainderCost = (n1 - n2) * min(c1, cb);
        } else {
            remainderCost = (n2 - n1) * min(c2, cb);
        }
        long long mix = common * cb + remainderCost;

        long long onlyCombos = max(n1, n2) * cb;

        return min({onlySingles, mix, onlyCombos});
    }
};