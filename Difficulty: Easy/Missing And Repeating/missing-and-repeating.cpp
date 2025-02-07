//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef long long ll;
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
         ll n = arr.size();
        ll sum=0,sum_sq=0,nsum=(n*(n+1))/2,nsq_sum = (n*(n+1)*(2*n+1))/6;
    
        for(auto i : arr){
            sum +=i;
            sum_sq +=(1ll*i*i); 
        }
        ll  x_minus_y=sum-nsum;
        ll  x_minu_y_sq=sum_sq - nsq_sum;
        ll  x_plus_y = x_minu_y_sq/x_minus_y;
        ll x = (x_minus_y + x_plus_y)/2;
        ll y = (x_plus_y - x);
        return {x,y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends