/*
题目：小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 

思路：枚举起点，然后二分查找枚举终点，时间是nlgn
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int size = sum / 2 + 1;
        vector<int> sumToK(size, 0);
        for(int i = 0; i < size; i++) {
            if(i == 0) sumToK[i] = i + 1;
            else {
                sumToK[i] = sumToK[i - 1] + i + 1;
            }
        }
        vector< vector<int> > res;
        for(int i = 0; i < size; i++) {
            int beforeSum = 0;
            if(i > 0) beforeSum = sumToK[i - 1];
            vector<int> seq;
            int seqEnd = binarySearch(sumToK, i, size - 1, beforeSum, sum);
            if(seqEnd - i + 1 < 2) continue;
            for(int j = i; j <= seqEnd; j++) {
                seq.push_back(j + 1);
            }
            res.push_back(seq);
        }
        return res;
    }
    
    int binarySearch(const vector<int> &sum, int start, int end, int beforeSum, int x){
        int left = start, right = end, m = left;
        while(left <= right){
            m = (right - left) / 2 + left;
            int tmp = sum[m] - beforeSum;
            if(tmp == x) break;
            else if(tmp < x) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        if(sum[m] - beforeSum == x) return m;
        return -1;
    }
};


/*
O(n)思路：俩指针，维持俩指针之间数字的和，如果和小于sum就将后面指针向后移，囊括更多的数，如果大于从前面删除最小的数。
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector< vector<int> > res;
        if(sum < 2) return res;
        int p1 = 1, p2 = 2, curSum = 3;
        while(p1 < p2) {
            if(curSum > sum) {
                curSum -= p1;
                p1++;
            } else if(curSum == sum) {
                vector<int> seq;
                for(int i = p1; i <= p2; i++) {
                    seq.push_back(i);
                }
                res.push_back(seq);
                curSum -= p1;
                p1++;
            } else {
                p2++;
                curSum += p2;
            }
        }
        return res;
    }
};