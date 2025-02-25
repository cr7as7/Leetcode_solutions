class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        // vector<int> pref(n,0);
        // pref[0]=arr[0];
        // for(int i=1;i<n;i++) pref[i] = pref[i-1] + arr[i];

        int even = 1,odd=0,count=0,m=1e9+7,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                count = (count+odd) % m;
                even++;
            }else{
                count = (count+even) % m;
                odd++;
            }
        }
        return count;
    }
};