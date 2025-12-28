class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string>vis;
        queue<string>q;
        string ans = s;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            ans = min(ans,cur);
            string add = cur;
            for(int i = 1;i < add.size();i += 2){
                add[i] =char('0'+(add[i]-'0'+a)%10);
            }
            if(!vis.count(add)){
                vis.insert(add);
                q.push(add);
            }
            string rot = cur.substr(cur.size()-b)+cur.substr(0,cur.size()-b);
            if(!vis.count(rot)){
                vis.insert(rot);
                q.push(rot);
            }
        }
        return ans;
    }
};
