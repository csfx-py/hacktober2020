Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
 
 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;vector<int>s;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                { s.push_back(i);
                s.push_back(j);}
                    
            }
        }
        
        return s;
    }
};
