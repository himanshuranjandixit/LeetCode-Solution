class Solution {
public:
    string robotWithString(string s) {
        int n= s.size();
        vector<char>v(n);
        v[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            v[i]=min(v[i+1],s[i]);
        }
        string t="";
        string paper="";
        int indx=0;
        while(indx<n){
            t+=s[indx];
            char mini;
            if(indx+1<n){
                mini = v[indx+1];

            }
            else mini = s[indx];
            while(!t.empty() && t.back() <= mini){
                paper+=t.back();
                t.pop_back();
            }
            indx++;

        }
        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;

        
    }
};