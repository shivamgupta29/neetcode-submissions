class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k == arr.size()) return arr;
        map<int, vector<int>> diff;
        for(int num: arr){
            int differnce = abs(num-x);
            diff[differnce].push_back(num);
        }
        vector<int> ans;
        for(auto p: diff){
            if(ans.size()==k) break;
            for(int num: p.second){
                if(ans.size()<k) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};