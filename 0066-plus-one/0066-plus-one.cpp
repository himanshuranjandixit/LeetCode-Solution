class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--){
            int &it = digits[i];
            if(it==9){
                it=0;
            }
            else{
                it++;
                return digits;
            }
        } 
        digits.insert(digits.begin(),1);
        return digits; 
    }
};