class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "+"){
                int top = st.top();
                st.pop();
                int stop = st.top();
                st.push(top);
                st.push(stop+top);
            }else if(operations[i] == "D"){
                int top = st.top();
                st.push(2*top);
            }else if(operations[i] == "C"){
                st.pop();
            }else{
                st.push(stoi(operations[i]));
            }
        }
        int ans=0;
        if(st.empty()) return 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};