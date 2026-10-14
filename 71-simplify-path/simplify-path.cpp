class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length();
        for(int i = 0; i < n; i++){
            if(path[i] == '/'){
                continue;
            }
            string dir = "";
            while(i < n && path[i] != '/'){
                dir += path[i];
                i++;
            }
            if(dir == "."){
                continue;
            }
            else if(dir == ".."){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(dir);
            }
        }
        string ans = "";
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};