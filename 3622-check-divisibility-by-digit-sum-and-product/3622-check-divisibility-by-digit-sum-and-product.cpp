class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int mul=1;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            mul*=rem;
            n=n/10;
        }
        int grp=sum+mul;
        if(grp==0) return false;
        return (num%grp)==0;
    }
};