class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        ans += strs[0];
        for(int i=1;i<strs.size();i++){
            string temp = strs[i];
            if(temp == "") return "";
            for(int i=0;i<ans.length() && temp.length();i++){
                if(temp[i] != ans[i]){
                    ans = ans.substr(0, i);
                    break;
                }
            }
        }
        return ans;
    }
};