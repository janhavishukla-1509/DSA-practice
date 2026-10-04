class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length() != words.size()) return false;
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for(int i = 0; i < pattern.length(); i++){
            char ch = pattern[i];
            string w = words[i];
            if(charToWord.count(ch) && charToWord[ch] != w) return false;
            if(wordToChar.count(w) && wordToChar[w] != ch) return false;
            charToWord[ch] = w;
            wordToChar[w] = ch;
        }
        return true;
    }
};