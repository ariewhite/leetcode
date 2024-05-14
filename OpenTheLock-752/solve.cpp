#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<array>

using namespace std;

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation: 
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".

int openLock(const vector<string> & deadends, string & target){

    array<int, 10000> visit{0};
    unordered_map<string, string> map;
    int n = (int)deadends.size();
    for (int i = 0; i < (int)deadends.size(); i++)
    {
        map.insert(deadends.at(i), to_string(i));
    }


    
}


int main(int argc, char * argv[]){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target {"02020"};
    openLock(deadends, target);
    return 0;
}