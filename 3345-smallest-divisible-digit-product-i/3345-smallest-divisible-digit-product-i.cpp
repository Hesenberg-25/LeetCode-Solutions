class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; i<INT_MAX; i++){
            std::string numStr = std::to_string(i);
            int product=1;
            for(char c :numStr){
                int digit=c-'0';
                product*=digit;
            }
            if(product%t==0){
                n=i;
                break;
            };
        }
        return n;
    }
};