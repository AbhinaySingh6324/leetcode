class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
         queue<int>e,o;
         int n=nums.size();
          for(int i =0 ;i<n;i++)
          {
               if(nums[i]>0)
               {
                   e.push(nums[i]);
                   
               }
               else  o.push(nums[i]);
          }
         nums.clear();
          for( int i =0 ;i< n/2;i++)
          {
              nums.push_back(e.front());
              nums.push_back(o.front());
              e.pop();
              o.pop();
          }
        return nums;
        
    }
};