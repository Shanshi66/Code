/*
题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

//使用插入排序

class Solution {
public:
    Solution():nums(list<int>()), count(0){}
    void Insert(int num)
    {	
        if(count == 0) nums.push_front(num);
        else {
            list<int>::iterator iter = nums.begin();
    		while(iter != nums.end()){
                if(*iter > num) iter++;
                else break;
            }
            nums.insert(iter, num);
        }
        count++;
    }

    double GetMedian()
    { 
    	int i = 0;
        list<int>::iterator iter = nums.begin();
        while(i < count / 2){
            iter++;
            i++;
        }
        if(count & 1) return *iter;
        else {
            double sum = 0;
            sum += *iter--;
            sum += *iter;
            return sum / 2;
        }
    }

private:
    list<int> nums;
	int count;
};

//剑指offer做法：大顶堆存储左边元素，小顶堆存储右边元素，两个堆的元素数量相等

class Solution {
public:
    Solution():count(0){}
    void Insert(int num)
    {	
        count++;
        if(count & 1) {
            if(count == 1) {
                maxHeap.push(num);
            } else {
             	if(minHeap.top() < num) {
                    minHeap.push(num);
                    int _min = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(_min);
                } else {
                    maxHeap.push(num);
                }
            }
        }
        else {
            if(maxHeap.top() > num) {
                maxHeap.push(num);
            	int _max = maxHeap.top();
                maxHeap.pop();
                minHeap.push(_max);
            } else {
                minHeap.push(num);
            }
        }
    }

    double GetMedian()
    {
    	if(count & 1) return maxHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0;
    }

private:
   	priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
	int count;
};