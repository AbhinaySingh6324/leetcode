class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int mid, low = 0, high = mountainArr.length()-1;
        while(low < high){
            mid = low + (high - low)/2;
            int l = mountainArr.get(mid-1); 
            int m = mountainArr.get(mid);
            int h = mountainArr.get(mid+1);
            if(mid > 0 && mid < n && m > l && m > h) break;
            if(m < h) low = mid+1;
            else high = mid;
        }
        if(mountainArr.get(mid) == target) return mid;
        low = 0;
        high = mid-1;
        //ascending
        while(low <= high){
            mid = low + (high - low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) high = mid-1;
            else low = mid+1;
        }
   //descending        
        low = mid;
        high = n-1;
        
        while(low <= high){
            mid = low + (high - low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target) high = mid-1;
            else low = mid+1;
        }
        
        return -1;
    }
};