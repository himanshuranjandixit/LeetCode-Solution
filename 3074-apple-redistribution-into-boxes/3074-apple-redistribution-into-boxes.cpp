class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int numOfApple =0;
        for(int it : apple){
            numOfApple += it;
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int count =0;
        for(auto it:capacity){
            if(numOfApple<=0) return count;
            numOfApple -= it;
            count++;
        }
        return count;
        
    }
};