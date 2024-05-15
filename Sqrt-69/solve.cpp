#include<iostream>
#include<vector>
#include<chrono>


class Solve {
public:
    /*
        x -> integer number
        y -> y ** y =~ x   =>
                            log y(x) =~ 2 

        binary search:
        low = 1; high = x; y = &high;
        mid = (low + (high - low )) / 2

        if mid * mid == x => return mid;
        else if mid * mid < x => low = mid + 1;
        else if mid * mid > x => high = mid - 1;

        return high;

    */
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        // std::vector<int> nums;
        // for (int i = 0; i < x; i++)
        // {
        //     nums.push_back(i);
        //     if (i * i == x){
        //         return i;
        //     }
        // }
        int low = 1;
        int high = x;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            std::cout << "iteration - " << low << std::endl;
            std::cout << "mid - " << mid << std::endl;
            if (mid == x/mid) {
                return mid;
            }
            else if (mid < x/mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }


};
int main(int argc, char* argv[]) {
    Solve* solve = new Solve();

    int x;
    std::cin >> x;

    auto start = std::chrono::high_resolution_clock::now();
    auto result = solve->mySqrt(x);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "result = " << result << std::endl;
    std::cout << "time = " << duration.count() << std::endl;
}