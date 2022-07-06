class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
          int n = milestones.size();
         sort(milestones.begin(),milestones.end());
          long long  sum = 0;
         for( int i  = 0 ;i<n-1;i++)
         {
             sum+=milestones[i];
         }
         if(sum<milestones[n-1])
         {
             return (sum*2+1);
         }
        else
        {
            return sum+milestones[n-1];
        }
        
    }
};