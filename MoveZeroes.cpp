//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.

class Solution {
public:
  size_t countZero(std::vector<int>& nums){
          size_t n{};
          for(auto elem: nums){
              if(elem == 0) n++;
          }
          return n;
      }
  void moveZeroes(std::vector<int>& nums) {
      if(nums.size() <= 1) return;
      int *p = &nums[0];
      int *q = p + 1;
      int count{};
      while(count < nums.size()){
          if(*p == 0){
              if(*q != 0){
                  *p = *q;
                  p++;
                  *q = 0;
              }
          }else{
              p++;
          }
          q++;
          count++;
          if(q >= &nums[nums.size()])break;
      }
      for(int i = nums.size() - countZero(nums); i < nums.size();++i){
          nums[i] = 0;
      }
  }
};
