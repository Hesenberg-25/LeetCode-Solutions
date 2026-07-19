class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> sq;
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!sq.empty() && sq.front() <= i - k) {
                sq.pop_front();
            }

            while (!sq.empty() && arr[sq.back()] <= arr[i]) {
                sq.pop_back();
            }

            sq.push_back(i);
            
            if (i >= k - 1) {
                ans.push_back(arr[sq.front()]);
            }
        }
        return ans;
    }
};