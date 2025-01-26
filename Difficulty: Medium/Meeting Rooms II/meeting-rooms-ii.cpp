//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = 1000010; // Maximum possible time range
    vector<int> countDelta(n, 0);

    // Mark the start and end of meetings
    for (int i = 0; i < start.size(); i++) {
        countDelta[start[i]]++;  // Increment at the start time
        countDelta[end[i]]--;   // Decrement at the end time
    }

    // Perform prefix sum to calculate active meetings at each time point
    int maxRooms = 0, currentRooms = 0;
    for (int i = 0; i < n; ++i) {
        currentRooms += countDelta[i];       // Update current active rooms
        maxRooms = max(maxRooms, currentRooms); // Track the maximum rooms
    }

    return maxRooms;
    
    }
};


//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.minMeetingRooms(arr, brr);
        cout << res << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends