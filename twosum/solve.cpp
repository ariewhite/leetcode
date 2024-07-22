#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

// vector<int> twoSum(){
//     vector<int> nums;
//     int target {9};
//     int num{};

//     while (cin >> num)
//     {
//         nums.push_back(num);
//     }

//     auto start = std::chrono::high_resolution_clock::now();

//     unordered_map<int, int> valueToIndex;

//     for (int i = 0; i < (int)nums.size(); i++)
//     {
//         auto it = valueToIndex.find(target - nums[i]);
//         if (it != valueToIndex.end()){
//             cout << it->second << " " << i << endl;
//             //return {it->second, i};
//         }
//         valueToIndex.insert({nums[i], i});
//     }

//     cout << "func end;" << endl;


//     auto end = std::chrono::high_resolution_clock::now();

//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     cout << "Duration - " << duration.count() << endl;

//     return {};
// }

// int main(int argc, char * argv[]){
//     twoSum();
// }


// 342 + 465 = 807
// 2 - 4 - 3
// 5 - 6 - 4
// 7 - 0 - 8

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode;
        ListNode * fr = result;

        
        int remain = 0;
        int sum;
        while (l1 != nullptr || l2 != nullptr || remain != 0)
        {
            sum = l1->val + l2->val + remain;
            remain = sum/10;
            ListNode * node = new ListNode(sum%10);
            fr->next = node;
            fr = fr->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;               
        }
        
        return result;
    }
};

int main(){
    return 0;
}

