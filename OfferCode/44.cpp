/*
题目：牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

思路：先反转每个单词，在把整个句子反转
*/

class Solution {
public:
    string ReverseSentence(string str) {
        typedef string::iterator siter;
        siter begin = str.begin();
        while(begin < str.end()){
            if(*begin == ' ') {
                begin++;
            } else {
                siter end = begin;
                while(end < str.end() && *end != ' ') end++;
                reverse(begin, end);
                begin = end;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};