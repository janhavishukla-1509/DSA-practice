class Solution {
public:
    void helper(int index, const string &digits, string &curr, vector<string> &ans, unordered_map<char, string> &phone){
        if(index == digits.length()){
            ans.push_back(curr);
            return;
        }
        string letters = phone[digits[index]];
        for(char ch : letters){
            curr.push_back(ch);
            helper(index + 1, digits, curr, ans, phone);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string curr = "";
        helper(0, digits, curr, ans, phone);
        return ans;
    }
};