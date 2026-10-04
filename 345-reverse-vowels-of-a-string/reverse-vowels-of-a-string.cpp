class Solution {
public:
    string reverseVowels(string s) {
        string news = "";
        stack<char> stck;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                stck.push(ch);
            }
        }
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                news += stck.top();
                stck.pop();
            }
            else{
                news += ch;
            }
        }
        return news;
    }
};