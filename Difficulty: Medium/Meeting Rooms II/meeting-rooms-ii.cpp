class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int count =0;
        int s=0,e=0,maxi = INT_MIN;
        while(s<start.size()){
            if(start[s] < end[e]){
                s++;
                count++;
            }
            else{
                e++;
                count--;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
