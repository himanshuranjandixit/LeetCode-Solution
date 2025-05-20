class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        st.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            int ast = asteroids[i];
            bool check=true;
            if(!st.empty() && ast<0 && st.top()>0){
                while(!st.empty() && ast<0 && st.top()>0){
                    if(abs(ast)>abs(st.top())){
                        st.pop();
                        if(st.empty()) break;
                    }
                    else if (abs(ast)<abs(st.top())){
                        check=false;
                        break;
                    }
                    else {
                        st.pop();
                        check=false;
                        break;
                    }
                }
                if(check) st.push(ast);
            }
            else st.push(ast);

        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
        
    }
};