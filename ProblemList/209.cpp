class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,j = 1;
        int indiceMin = 9999999, sumaParcial = nums[i];
        int indiceLocal = 0;
        while(j<=nums.size()){
            if(sumaParcial < target){
                if(j<nums.size()){
                    sumaParcial += nums[j]; 
                }
                j++;
            }else{
                //sumaParcial >= target
                indiceLocal = j-i;
                if(indiceLocal < indiceMin){
                    indiceMin = indiceLocal;
                }
                sumaParcial -= nums[i];
                i++;
            }
        }
        
        if(indiceMin == 9999999){
            return 0;
        }
        return indiceMin;
    }
};
