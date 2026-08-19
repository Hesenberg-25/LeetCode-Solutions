class Solution {
public:   
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> line; 
     
        for(int num : tickets){
            line.push(num);
        }
     
        while(!line.empty()){
            int first = line.front() - 1;
            line.pop();
            time++;
            
       
            if (k == 0) {
                if (first == 0) {
                    return time;
                }
                line.push(first);
                k = line.size() - 1; 
            } else {
                if (first > 0) {
                    line.push(first);
                }
                k--;
            }
        }
        return time;
    }
};