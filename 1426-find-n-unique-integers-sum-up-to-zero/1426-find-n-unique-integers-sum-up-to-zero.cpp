class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2==1){
            ans.push_back(0);
            n--;
        }
        int num =1;
        while(n){
            ans.push_back(num);
            ans.push_back(-num);
            n-=2;
            num++;
        }
        return ans;
        
    }
};