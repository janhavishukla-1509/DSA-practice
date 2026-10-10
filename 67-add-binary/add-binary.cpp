class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int n = a.size() - 1;
        int m = b.size() - 1;
        int carry = 0;
        while(m >= 0 || n >= 0 || carry){
            int sum = carry;
            if(n >= 0){
                sum += a[n] - '0';
                n--;
            }
            if(m >= 0){
                sum += b[m] - '0';
                m--;
            }
            s += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};