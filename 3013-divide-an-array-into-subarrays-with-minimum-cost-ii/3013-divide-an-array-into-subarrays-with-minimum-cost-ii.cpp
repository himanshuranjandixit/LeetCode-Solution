class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        multiset<int>left,right;
        long long sum = 0;
        long long ans = LLONG_MAX;
        for(int i = 1;i<=dist+1;i++){
            left.insert(nums[i]);
            sum += nums[i];
            if(left.size()>k){
                auto it = prev(left.end());
                sum -= *it;
                right.insert(*it);
                left.erase(it);
            }
        }

        ans = min(ans,sum);

        for(int i=2;i+dist<nums.size();i++){
            int num1 = nums[i-1];
            int num2 = nums[i+dist];
            if (left.find(num1)!=left.end()){
                sum -= num1;
                left.erase(left.find(num1));
            }
            else right.erase(right.find(num1));
            if(!left.empty() && num2< *prev(left.end())){
                left.insert(num2);
                sum += num2;
            }
            else right.insert(num2);
           
            while(left.size() < k && !right.empty()){
                auto it = right.begin();
                sum += *it;
                left.insert(*it);
                right.erase(it);
            }

            while (left.size() > k) {
                auto it = prev(left.end());
                sum -= *it;
                right.insert(*it);
                left.erase(it);
            }
            ans = min(ans,sum);
        }
        return ans + nums[0];
    }
};
