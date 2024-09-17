#include <iostream>
#include <vector>

class Solution
{
public:
    static int removeElement(std::vector<int> & nums, int val){
        size_t sz = nums.size();
        for (auto it = nums.begin(); it != nums.end();){
            if (*it == val){
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        int ans = nums.size();
        nums.resize(sz);
        
        return ans;
    }
    
    static void print(const std::vector<int> & nums)
    {
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << nums.size() << "\n";
        
    }
};



int main()
{
    std::vector<int> nums = {3, 2, 2, 3};
    std::cout << Solution::removeElement(nums, 3) << std::endl;
    Solution::print(nums);
    return 0;
}