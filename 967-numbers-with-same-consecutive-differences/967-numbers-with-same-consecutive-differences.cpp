class Solution {
public:
     set<int>nums;
void solve(long long  i,int len,int nn ,int kk){
    if(len==nn){
        nums.insert(i);
        return;
    }
    long long last = i%10;
    if(last+kk < 10){
        solve((i*10)+(last+kk),len+1,nn,kk);
    }
    if (last-kk >=0){
        solve((i*10)+(last-kk),len+1,nn,kk);
    }

}
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            solve(i,1, n,k);
        }
        vector<int>ans(nums.begin(),nums.end());
        return ans;
    }
};