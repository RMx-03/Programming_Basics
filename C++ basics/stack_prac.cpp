#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct item
    {
        string name; // holds the name of the item
        int value;   // holds the value of the item
        item *prev;  // points to the previous item in the stack
    };

    item *stackPtr; // points to the top of the stack

public: // responsible for utilisation of private variables
    // constructor
    Stack()
    {
        stackPtr = NULL;
    }; // stack object is created

    // adds the item to the top of the stack
    void Push(string name, int value) {
        item* n = new item;  // new is used for dynamic memory allocation
        
        n->name = name; // takes the name from the function and assigns it to the name of the item
        n->value = value;  // takes the value from the function and assigns it to the value of the item

        if(stackPtr == NULL) {
            stackPtr = n; // if the stack is empty, the new item is the top of the stack
            stackPtr->prev = NULL; // the top item points to NULL
        } else {
            n->prev = stackPtr; // the new item points to the previous top item
            stackPtr = n; // the new item is now the top of the stack
        }
           

    };

    // removes the top item from the stack
    void Pop() {
        if(stackPtr == NULL) {
            cout << "The stack is empty\n";
        } else {
            item* temp = stackPtr; // a temporary item to hold the top item
            ReadItem(temp); // displays the top item

            stackPtr = stackPtr->prev; // the top item is now the previous item
            temp->prev = NULL; // disconnects the top item from the stack
            delete temp; // deletes the top item
        }

    };

    // returns the required item
    void ReadItem(item* r) {
        cout << "----------------\n";
        cout << "name: " << r->name << endl; // displays the name of the item
        cout << "value: " << r->value << endl; // displays the value of the item
        cout << "----------------\n";
        
    };

    // display the stack
    void PrintStack() {
        item* temp = stackPtr; // a temporary item to hold the top item
        if (temp == NULL) {
            cout << "The stack is empty\n";
            return;
        } else {
            while(temp != NULL) {
                ReadItem(temp); // displays the top item
                temp = temp->prev; // the top item is now the previous item
            } 
        }
    };

    // destructor
    ~Stack()
    {
        item *p1;
        item *p2;

        p1 = stackPtr;
        while (p1 != NULL)
        {
            p2 = p1;
            p1 = p1->prev;
            p2->prev = NULL; // disconnects the top item from the stack
            delete p2;
        }
    }; // stack object destroyed
};

int main() {
    Stack stack; // creates a stack object


    stack.Push("item1", 15); // adds item to the stack
    stack.Push("item2", 20);     
    stack.Push("item3", 25); 
    stack.Push("item4", 30);
    stack.PrintStack();  // displays the stack    
    cout << "Popping\n"; 
    stack.Pop(); // removes the top item from the stack
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    stack.PrintStack(); 
    cout << "\n\n New Stack \n\n";
    stack.Push("item1", 11);
    stack.Push("item2", 22);
    stack.Push("item3", 33);
    stack.Push("item4", 44);
    stack.PrintStack();


    return 0;
}