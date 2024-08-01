#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class AllOne {
private:
    string value;
    int count;

protected:
    unordered_set<string, int> * set = new unordered_set<string, int>;
public:
    // constructor 
    AllOne() : value(), count(0)
    {
        
    }
    
    void inc(string key) {
        this->set->insert(make_pair<string, int>(key, (int)key.length()));
    }
    
    void dec(string key) {
        
    }
    
    string getMaxKey() {
       // return nullptr;
    }
    
    string getMinKey() {
        //return NULL;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(int argc, char * argv[])
{


    return 0;
}