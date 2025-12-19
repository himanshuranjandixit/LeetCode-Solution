class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long>finish(skill.size());
        finish[0]= mana[0]*skill[0];
        for(int i=1;i<skill.size();i++){
            finish[i] =finish[i-1] + mana[0]*skill[i];
        }
        for(int i=1;i<mana.size();i++){
            finish[0] += mana[i]*skill[0];
            for(int j=1;j<skill.size();j++){
                finish[j] = max(finish[j],finish[j-1]) + 1LL*skill[j]*mana[i];
            }
            for(int k=skill.size()-1;k>0;k--){
                finish[k-1] = finish[k]- 1LL*skill[k]*mana[i];
            }
        }
        return finish[skill.size()-1];


        
    }
};

