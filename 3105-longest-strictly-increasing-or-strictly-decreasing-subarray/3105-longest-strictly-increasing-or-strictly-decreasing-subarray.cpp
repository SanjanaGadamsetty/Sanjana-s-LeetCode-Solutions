class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n= nums.size();
        int i= 0, ans= 0;

        if (n== 1) return 1;

        int increment= 1, decrement= 1;
        for (int i= 1; i< n; i++){
            if (nums[i]> nums[i-1]){
                increment++;
                decrement= 1;
            }
            else if (nums[i]< nums[i-1]){
                increment= 1;
                decrement++;
            }
            else{
                increment= 1;
                decrement= 1;
            }
            ans= max({ans, decrement, increment});
        }
        return ans;
    }
};