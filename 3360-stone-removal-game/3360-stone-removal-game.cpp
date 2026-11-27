class Solution {
public:
    bool canAliceWin(int n) {
        int removal = 10;
        bool aliceTurn = true;

        while (n >= removal) {
            n -= removal;
            removal--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};