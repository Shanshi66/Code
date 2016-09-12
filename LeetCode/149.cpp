/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /*
        TLE solution
    */
    int maxPoints(vector<Point>& points) {
        int point_num = points.size(), ans = 0;
        double min_slope = INT_MAX, max_slope = INT_MIN;
        for(int i = 0; i < point_num; i++){
            for(int j = 0; j < point_num; j++){
                if(points[i].x != points[j].x){
                    double slope = (double)(points[i].y - points[j].y)/(points[i].x - points[j].x);
                    max_slope = max(max_slope, slope);
                    min_slope = min(min_slope, slope);
                }
            }
        }
        // 垂直
        for(int i = 0; i < point_num; i++){
            int x = points[i].x, tmp = 1;
            for(int j = 0; j < point_num; j++){
                if(i == j) continue;
                if(points[j].x == x) tmp++;
            }
            ans = max(tmp, ans); 
        }
        // 水平
        for(int i = 0; i < point_num; i++){
            int y = points[i].y, tmp = 1;
            for(int j = 0; j < point_num; j++){
                if(i == j) continue;
                if(points[j].y == y) tmp++;
            }
            ans = max(tmp, ans);
        }
        // else
        // double delta = 1e-3;
        // cout << (max_slope - min_slope) / delta << endl;
        double delta = (max_slope - min_slope)/100000;
        for(double i = min_slope; i <= max_slope; i += delta){
            if(isZero(max_slope - min_slope)) break;
            for(int j = 0; j < point_num; j++){
                int tmp = 1;
                for(int s = 0; s < point_num; s++){
                    if(s == j) continue;
                    if(points[s].x == points[j].x && points[s].y == points[j].y) {
                        tmp++;
                    }
                    else if(points[s].x == points[j].x) continue;
                    else{
                        if(isZero(double(points[j].y - points[s].y) / 
                                 (points[j].x - points[s].x) - i)){
                            tmp++;
                        }
                    }
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
    bool isZero(double x){
        const double eps = 1e-3;
        if(abs(x) <= eps) return true;
        else return false;
    }
};


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int point_num = points.size(), result = 0;
        for(int i = 0; i < point_num; i++){
            map<double, int> slope_count;
            int same_points = 1;
            for(int j = i + 1; j < point_num; j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    same_points++;
                }else if(points[i].x == points[j].x){
                    slope_count[INT_MAX]++;
                }else{
                    double slope = (double)(points[i].y - points[j].y)/(points[i].x - points[j].x);
                    slope_count[slope]++;
                }
            }
            int local_max = 0;
            for(auto iter = slope_count.begin(); iter != slope_count.end(); iter++){
                local_max = max(local_max, iter->second);
            }
            local_max += same_points;
            result = max(result, local_max);
        }
        return result;
    }   
};

