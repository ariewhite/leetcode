#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

vector<int> twoSum(){
    vector<int> nums;
    int target {9};
    int num{};

    while (cin >> num)
    {
        nums.push_back(num);
    }

    auto start = std::chrono::high_resolution_clock::now();

    unordered_map<int, int> valueToIndex;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        auto it = valueToIndex.find(target - nums[i]);
        if (it != valueToIndex.end()){
            cout << it->second << " " << i << endl;
            //return {it->second, i};
        }
        valueToIndex.insert({nums[i], i});
    }


    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Duration - " << duration.count() << endl;

    return {};
}

int main(int argc, char * argv[]){
    twoSum();
}
