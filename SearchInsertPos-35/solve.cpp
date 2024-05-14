#include <iostream>
#include <vector>

class Solution
{
public:
    const int seachInsertPos(std::vector<int> &nums, int target)
    {
        /*
            nums = { 1, 3, 5, 6 }
            target = 2

            solve w/ binary search.

            0: { 1, 3, 5, 6 }
                       *      mid = 2; nums[2] = 5; low = 0; high = 3
            1: { 1, 3, 5, 6 }
                    *         mid = 2; nums[1] = 3; low = 0; high = 1
            2: { 1, 3, 5, 6 }
                 *            mid = 0; nums[0] = 1; low = 1; high = 1
        */
        int low = 0;
        int high = nums.size() - 1; // 4

        if (target > nums[high]){
            return high+1;
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();

    std::vector<int> nums = {1, 3, 5, 6};
    int target = 7;

    auto answer = sol->seachInsertPos(nums, target);
    std::cout << "Index - " << answer << std::endl;

    return 0;
}