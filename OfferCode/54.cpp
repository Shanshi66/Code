/*
题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/

class Solution
{
public:
  //Insert one char from stringstream
    Solution(): firstOccuredChar('#'){}
    void Insert(char ch)
    {
         if(occuredChar.find(ch) == occuredChar.end()){
             if(firstOccuredChar == '#') firstOccuredChar = ch;
             occuredChar[ch] = 1;
         } else {
             occuredChar[ch] += 1;
             if(firstOccuredChar == ch) {
                 firstOccuredChar = '#';
                 for(auto x: occuredChar) {
                     if(x.second == 1) {
                         firstOccuredChar = x.first;
                         break;
                     }
             	 }
             }
             
         }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	return firstOccuredChar;
    }
	map<char, int> occuredChar;
    char firstOccuredChar;
};