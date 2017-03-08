/*
题目：LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

思路：先排序，统计王的个数。然后从前往后扫，看前后元素是否连续，如果不连续，王的个数减去需要补充的排数。如果最后王的个数小于0。则不是顺子。

注意：如果两张排相同，那也不是顺子

*/

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int zeroCnt = 0;
        if(numbers.size() > 13 || numbers.size() == 0) return false;
        typedef vector<int>::iterator iiter;
        for(iiter iter = numbers.begin(); iter < numbers.end(); iter++) {
            if(iter == numbers.end() - 1) break;
            if(*iter == 0) zeroCnt++;
            else {
                int diff = *(iter + 1) - *iter;
                if(diff == 0) zeroCnt = -1;
              	else zeroCnt -= diff - 1;
            }
        }
        if(zeroCnt < 0) return false;
       	else return true;
    }
};