class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (auto x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                long long a = st.back(); st.pop_back();
                long long b = st.back(); st.pop_back();
                long long g = gcd(a, b);
                if (g == 1) {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                } else {
                    long long lcm = (a / g) * b; 
                    st.push_back(lcm);
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
