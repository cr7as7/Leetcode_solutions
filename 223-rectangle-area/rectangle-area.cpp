class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xoverlap = max(0,-max(ax1,bx1) + min(ax2,bx2));
        int yoverlap = max(0,-max(ay1,by1) + min(ay2,by2));
        int overlap = xoverlap * yoverlap;
        int A_area = (ax2-ax1) * (ay2-ay1);
        int B_area = (bx2-bx1) * (by2-by1);
        return A_area + B_area - overlap;
    }
};