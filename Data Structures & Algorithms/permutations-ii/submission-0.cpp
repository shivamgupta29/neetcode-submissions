class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    vector<vector<int>> res;
    void solve(vector<int> &temp){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(auto &[num, count] : mp){
            if(count==0) continue;
            temp.push_back(num);
            mp[num]--;
            solve(temp);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int &num : nums){
            mp[num]++;
        }
        n = nums.size();
        vector<int> temp;
        solve(temp);
        return res;
    }
};