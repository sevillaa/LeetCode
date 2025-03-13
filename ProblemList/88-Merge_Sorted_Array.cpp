class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1; //indice posicion vector 1 (empezando desde el final) [1,2,3,4,0,0]
    int j = n-1; //indice posicion vector 2 (empezando desde el final) [4,5] <-
    int k = m + n -1; //indice posicion a asignar vector 1 [1,2,3,4,0,0,0] <-
    
    while (j>= 0){
        if(i >= 0 && nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    }
};
