#include <iostream>


class Solve{
private:
    int _val;
public:
    int value;
public:
    Solve(int input) //: value(input)
    {
        value = input;
        std::cout << "value - " << input << std::endl;

    }

    void minus(int count){
        this->value -= count;
        this->_val = 100;
    }
};
int main(){

    Solve * s = new Solve(10);

    s->minus(4);

    std::cout << "s.value() - " <<  s->value << std::endl;
    std::cout << "s.value() after minus 4 - " <<  s->value << std::endl;
    return 0;

}