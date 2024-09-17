//
//  main.cpp
//  algo
//
//  Created by Chingiz Murzabaev on 15.08.2024.
//

#include <iostream>
#include "vector"



class CountingSort {
public:
    template <typename T>
    inline static std::vector<T> sort (std::vector<T> & nums)
    {
        unsigned int low = *std::min_element(nums.cbegin(), nums.cend());
        unsigned int high = *std::max_element(nums.cbegin(), nums.cend());
        
        std::vector<int> count(high-low+1, 0);
        std::vector<T> res(nums.size(), 0);
        
        for (auto x : nums) {
            count[x-low] += 1;
        }
        for (int i = 1; i < count.size(); ++i) {
            count[i] += count[i-1];
        }
        
        std::reverse(nums.begin(), nums.end());
        
        for (auto x : nums) {
            count[x-low] -= 1;
            res[count[x-low]] = x;
        }
        
        return res;
        
    }
};

/*
 //    std::vector<int> nums = { 5, 4, 3, 1, 3, 6, 88, 14};
 //
 //    std::cout << "original array: ";
 //    for (auto x : nums) {
 //        std::cout << x << " ";
 //    }
 //
 //    std::cout << "\nsorted array: ";
 //
 //    nums = CountingSort::sort(nums);
 //
 //    for (auto x : nums) {
 //        std::cout << x << " ";
 //    }
 //
 //    std::cout << std::endl;
 
     1 - 2
 0 - 1 - 2
 
 1 - 0 - 2 //
 1 > 0 ++ 2
 0 < 2 -- 1
 2 > 0 ++ 2 -> 5
 
 to do
 попытаться через оптимизировать черзе прошлое состояние cur_c
 */
class Solution{
private:
    unsigned int sum = 1;
    unsigned short cur_c = 1;
    
    void _check(){
        if (cur_c < 1) {
            cur_c = 1;
        }
    }
public:
    
    int solve(std::vector<int> & rating)
    {
        size_t size = rating.size();
        
        std::cout << "size - " << size << std::endl;
        
        for (int i = 0; i < rating.size(); ++i)
        {
            std::cerr << "current iteration - " << i << std::endl;
            if (i == 0){
                if (rating[i] > rating [i+1]) {
                    cur_c += 1;
                    sum += cur_c;
                } else {
                    sum += cur_c;
                }
            }
            else if( i == size-1 ){
                if (rating[i-1] < rating[i] ) {
                    cur_c += 1;
                    sum += cur_c;
                } else if (rating[i-1] == rating[i]) {
                    sum += cur_c;
                } else {
                    cur_c -= 1;
                    _check();
                    sum += cur_c;
                }
            } else {
                if (rating[i-1] < rating[i] | rating[i+1] < rating [i] ) {
                    cur_c += 1;
                    sum += cur_c;
                } else if (rating[i-1] == rating[i]) {
                    sum += cur_c;
                } else if (rating[i] < rating[i-1] && rating[i] <= rating[i+1]){
                    sum += cur_c;
                } else {
                    cur_c -= 1;
                    _check();
                    sum += cur_c;
                }
            }

            //std::cout << sum << std::endl;
            std::cout << "cur_c" << cur_c << std::endl;
            std::cout << sum << std::endl;
        }
        
        std::cerr << sum << std::endl;
            
        return sum;
    }
               
};
int main(int argc, const char * argv[]) {
    std::vector<int> rating = {1,0,2};
    Solution s;
    s.solve(rating);

    return 0;
}
