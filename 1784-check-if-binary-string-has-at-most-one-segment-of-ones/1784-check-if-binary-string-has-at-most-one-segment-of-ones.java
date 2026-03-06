class Solution {
    public boolean checkOnesSegment(String s) {
        boolean ans = false;
        boolean zeroes = false;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1'){
                if(zeroes) return false;
                ans=true;
            }
            else{
                if(ans) zeroes=true;
            }
        }
        return ans;
        
    }
}