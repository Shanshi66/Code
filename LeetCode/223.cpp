class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_a = (C - A) * (D - B), area_b = (G - E) * (H - F), area_cross;
        if(B > H || F > D) area_cross = 0;
        else if(C < E || G < A) area_cross = 0;
        else{
            if(B > F){
                swap(A, E); swap(B, F); swap(C, G); swap(D, H);
            }
            if(E < A){
                if(G < C){
                    if(H < D) area_cross = (G - A) * (H - F);
                    else area_cross = (G - A) * (D - F);
                }else{
                    if(H < D) area_cross = (C - A) * (H - F);
                    else area_cross = (C - A) * (D - F);
                }
            }else {
                if(G < C){
                    if(H < D) area_cross = (G - E) * (H - F);
                    else area_cross = (G - E) * (D - F);
                }else{
                    if(H < D) area_cross = (C - E) * (H - F);
                    else area_cross = (C - E) * (D - F);
                }
            }
        }
        return area_a + area_b - area_cross;
    }
};