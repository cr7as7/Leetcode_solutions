class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && a[i] != ele2) {
                ele1 = a[i];
                cnt1++;
            } else if (cnt2 == 0 && a[i] != ele1) {
                ele2 = a[i];
                cnt2++;
            } else if (ele1 == a[i])
                cnt1++;
            else if (ele2 == a[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1 == a[i]) cnt1++;
            if(ele2 == a[i]) cnt2++;
        }
        int mini = (int)(n/3) + 1;
        vector<int> ans;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};