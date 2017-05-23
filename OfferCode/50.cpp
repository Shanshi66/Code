/*
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。

思路：hash
*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length < 2) return false;
        vector<bool> arr(length, false);
        bool dupExist = false;
        for(int i = 0; i < length; i++) {
        	if(arr[numbers[i]] == true) {
                dupExist = true;
                *duplication = numbers[i];
                break;
            } else {
                arr[numbers[i]] = true;
            }
        }
        return dupExist;
    }
};


/*
剑指offer上的解法：

思路：因为数字范围是0~n，如果排好序，那么数字x应该是放在下标为x的位置上。可以通过交换的方式将数字正确放在位置上，然后如果在其他位置上有数字和它一样救说明这个数字是重复数字
*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length < 2) return false;
        int i = 0;
        bool dupExist = false;
        while(i < length){
            if(numbers[i] != i) {
                if(numbers[i] == numbers[numbers[i]]) {
                    dupExist = true;
                    *duplication = numbers[i];
                    break;
                } else {
                    swap(numbers[i], numbers[numbers[i]]);
                }
            } else {
                i++;
            }
        }
        return dupExist;
    }
};