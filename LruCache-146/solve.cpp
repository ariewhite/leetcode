#include <iostream>
#include "string"


class BrowserHistory
{    
public:
    
    BrowserHistory(std::string homepage)
    {
        Node * node = new Node(homepage);
        curr = node;
    }

    void visit(std::string url)
    {
        Node * node = new Node(url);
        
        curr->next = node;
        node->prev = curr;
        delete node->next;
        node->next = NULL;
        curr = node;
    }

    std::string back(int count)
    { 
        while (count != 0)
        {
            if(curr->prev != NULL){
                curr = curr->prev;
                count--;  
            }
            else{
                return curr->value;
            }             
        }       
        return curr->value;
    }
    

    std::string forward(int count)
    {
        while (count != 0)
        {
            if(curr->next != NULL){
                curr = curr->next;
                count--;
            }
            else{
                return curr->value;
            }
        }
        return curr->value;
    }

private:
    class Node
    {
    public:
        std::string value;

        Node * next;
        Node * prev;

        Node(std::string val) : value(val) 
        {
            this->next = NULL;
            this->prev = NULL;
        }  
    };
    
public:
    Node * curr;
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


int main(int argc, char * argv[])
{
    std::string homepage = "homepage";
    std::string url1 = "leetcode";
    std::string url2 = "google";
    std::string url3 = "spotify";
    int steps = 2;


    BrowserHistory * hist = new BrowserHistory(homepage);


    hist->visit(url1);
    hist->visit(url2);
    hist->visit(url3);
    

    std::string param = hist->back(steps);
    std::string param2 = hist->forward(steps);


    std::cout << "param - " << param << std::endl;
    std::cout << "param2 - " << param2 << std::endl;


    return 0;
}