class Solution {
public:
    int count1(int num){
        int count=0;
        for(int i=0;i<32;i++){
            if((num>>i)&1)count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[this](const int& a, const int& b){
            int oneInA = this->count1(a);
            int oneInB = this->count1(b);
            if(oneInA != oneInB) return oneInA<oneInB;
            else return a<b;
        });
        return arr;
        
    }
};