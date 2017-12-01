/*
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,till_here=INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(till_here<=sum){
                till_here=sum;
            }
            if (sum<0){
                sum=0;
            }
        }
        return till_here;
    }
};
