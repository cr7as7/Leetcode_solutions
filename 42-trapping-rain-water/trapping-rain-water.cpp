class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int ans =0;
        vector<int> leftMax(n),rightMax(n);
        leftMax[0] = h[0];
        rightMax[n-1]= h[n-1];
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],h[i]);
            rightMax[n-i-1] = max(rightMax[n-i],h[n-i-1]);
        }
        for(int i = 0;i<n;i++){
            ans+=min(leftMax[i],rightMax[i]) - h[i];
        }
        return ans;
    }
};