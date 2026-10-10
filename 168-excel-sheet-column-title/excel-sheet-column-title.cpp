class Solution {
public:
    string convertToTitle(int colNumber) {
        string s = "";
        while(colNumber > 0){
            colNumber--;
            char ch = 'A' + (colNumber % 26);
            s += ch;
            colNumber /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};