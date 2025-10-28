class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        int indx =0;
        while(v.size()>1){
            indx = (indx+k-1)%v.size();
            v.erase(v.begin()+indx);
        }
        return v[0];
        
    }
};