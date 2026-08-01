class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stacked;
        string curr="";
        for(char c: path){
            if(c=='/'){
                if(curr==".."){
                    if(!stacked.empty()) stacked.pop_back();
                }else if(!curr.empty() && curr!="."){
                    stacked.push_back(curr);
                }
                curr.clear();
            }
            else{
                curr += c;
            }
        }
        if(curr==".."){
                    if(!stacked.empty()) stacked.pop_back();
                }else if(!curr.empty() && curr!="."){
                    stacked.push_back(curr);
                }
        string res="/";
        for(int i=0;i<stacked.size();i++){
            if(i>0) res += "/";
            res += stacked[i];
        }
        return res;
    }
};