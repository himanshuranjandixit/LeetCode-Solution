class MyCalendarThree {
    TreeMap<Integer,Integer>mpp;

    public MyCalendarThree() {
        mpp = new TreeMap<>();
        
    }
    
    public int book(int startTime, int endTime) {
        mpp.put(startTime,mpp.getOrDefault(startTime,0)+1);
        mpp.put(endTime,mpp.getOrDefault(endTime,0)-1);
        int maxi =0;
        int cnt =0;
        for(int it :mpp.values()){
            cnt+=it;
            maxi=Math.max(maxi,cnt);
        }
        return maxi; 
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(startTime,endTime);
 */