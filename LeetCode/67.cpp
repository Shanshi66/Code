class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length(), b_len = b.length(), carry = 0;
        if(!a_len && !b_len) return string("0");
        if(a_len < b_len)swap(a, b), swap(a_len, b_len);
        for(int i = a_len - 1, j = b_len - 1; i >= 0 || j >= 0; i--, j--){
            char bb = j < 0 ? '0' : b[j];
            if(a[i] == '1' && bb == '1') a[i] = carry + '0', carry = 1;
            else if(a[i] == '1' || bb == '1'){
                if(carry) a[i] = '0', carry = 1;
                else a[i] = '1', carry = 0;
            }else {
                a[i] = carry + '0';
                carry = 0;
            }
        }
        if(carry) a = string("1") + a;
        return a;
    }
};