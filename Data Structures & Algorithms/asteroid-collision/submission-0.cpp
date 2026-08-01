class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty()) return {};
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            bool alive=true;
            while(alive && !st.empty() && (st.top()>0 && asteroids[i]<0)){
                int top = st.top();
                st.pop();
                if(abs(top) > abs(asteroids[i])){
                    st.push(top);
                    alive=false;
                }else if(abs(top) == abs(asteroids[i])){
                    alive=false;
                }
            }
            if(alive) st.push(asteroids[i]);
        }
        if(st.empty()) return {};
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};