#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>

class Solution {
public:

/*
    1: merge - nums1 + nums2 -> nums1
    2: sort - nums1
*/
   
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());    

        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     std::cout << nums1[i];
        // }
           
    }
};

int main(int argc, char * argv[]){
    Solution * sol = new Solution();

    std::vector<int> nums1 = {
        {1, 2, 3, 0, 0, 0}
    };
    std::vector<int> nums2 = {
        {2, 5, 6}
    };

    int m = 6;
    int n = 3;
    
    auto start = std::chrono::high_resolution_clock::now();


    sol->merge(nums1, m, nums2, n);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "duration - " << duration.count() << std::endl;

    return 0;
}