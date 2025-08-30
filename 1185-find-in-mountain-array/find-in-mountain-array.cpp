/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &A) {
    int l = 0, r = A.length() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (A.get(m) < A.get(m + 1)) l = m + 1;
        else r = m;
    }
    return l; // or r; l == r
}
    int bs(MountainArray &A,int l,int r,int target){
        int res = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(A.get(m)==target) {
                res = m ;
                r=m-1;
            }else if(A.get(m) > target) r=m-1;
            else l=m+1;
        }
        return res;
    }
    int rbs(MountainArray &A,int l,int r,int target){
        int res = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(A.get(m)==target) {
                res = m ;
                r=m-1;
            }else if(A.get(m) > target) l=m+1;
            else r=m-1;
        }
        return res;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peak(mountainArr);
        int res = bs(mountainArr,0,idx,target);
        if(res ==-1){
            res = rbs(mountainArr,idx+1,n-1,target);
        }
        return res;
    }
};