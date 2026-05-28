class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int count=0;map<long long,int>preSumMap;int sum=0;int rem;
    preSumMap[0]=1;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        rem=sum-k;
        count+=preSumMap[rem];
        preSumMap[sum]++;
    }
    
    
    
    return count;
    }
};