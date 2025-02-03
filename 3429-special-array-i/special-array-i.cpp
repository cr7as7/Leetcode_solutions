class Solution {
public:
    bool isArraySpecial(vector<int>& a) {
        int n = a.size();
        for(int i=1;i<n;i++){
            if(a[i]%2==0 && a[i-1]%2==0) return false;
            if(a[i]%2==1 && a[i-1]%2==1) return false;
        }
        return true;
    }
};