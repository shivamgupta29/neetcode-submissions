class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int,int> beg;
        for(int j=0;j<m;j++){
            beg[matrix[j][0]] = j;
        }

        auto it = beg.lower_bound(target);
        int rowi = -1;

        if(it != beg.end() && it->first == target){
            return true;
        }else if(it != beg.begin()){
            --it;
            rowi = it->second;
        }else{
            return false;
        }

        if(rowi == -1) return false;
        for(int j=0;j<n;j++){
            if(matrix[rowi][j] == target){
                return true;
            }
        }
        return false;
    }
};