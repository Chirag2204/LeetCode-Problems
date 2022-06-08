class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            if(target < nums[0]){
                    return 0;
            }
            else if(target > nums[nums.size()-1]){
                    return nums.size();
            }else{
                  int returnvalue =binarySearch(0,nums.size()-1,target,nums);
            
            return returnvalue;    
            }
     
    }
        
     int binarySearch(int beg,int end,int value,vector<int>& nums){
          if(end>=beg){
              int mid =(beg+end)/2;
            if(value > nums[mid]){
                   
                 return binarySearch(mid+1,end,value,nums);
             }
             if(value < nums[mid]){
                    
                 return binarySearch(beg,mid-1,value, nums);     
             }
             if(value==nums[mid]){ 
                  return mid;
             }
                
          }
          return (beg+end)/2 + 1; 
          
     }
};