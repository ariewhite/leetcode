#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::unordered_map;


class Duration
{
public:
    Duration(std::string x) : id_(x){}
    ~Duration(){
        const std::chrono::steady_clock::time_point end_time_ = std::chrono::steady_clock::now();
        const auto dur = end_time_ - start_time_;

        cout << id_ << ": "
             << "time: " 
             << ":" << std::chrono::duration_cast<std::chrono::milliseconds> (dur).count()
             << "ms\n";
    }
private:
    std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now(); 
    std::string id_;
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(std::remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }), nums.end()); 

        std::sort(nums.begin(), nums.end());

        int t = 1;
        for (auto n : nums)
        {
            if ((n == t)) {
                t++;
            } else if (n > t) {
                return t;
            }
            
        }     

        return t;
        
    }
};


int main()
{
    vector<int> * nums = new vector<int> {3, 4, -1, 1};

    Solution s;
    {
        Duration durka("sort array + solution");
        cout << s.firstMissingPositive(*nums) << endl;
    }
    delete[] nums;
    return 0;
}