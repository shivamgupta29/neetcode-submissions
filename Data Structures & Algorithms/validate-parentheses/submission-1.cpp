class Solution {
public:
    bool isValid(string s) {
        map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        stack<char> st;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(!st.empty() && mp[c]==st.top()){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
