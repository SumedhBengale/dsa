//Implementation of stack without using the Std Library.

#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stack;
    
    public:
        void push(int value){
            stack.push_back(value);
        }

        int pop(){
            if(stack.empty()){
                cerr << "Stack is Empty" << endl;
                return -1;
            }

            int last = stack.at(stack.size()-1);
            stack.pop_back();
            return last;
        }

        int top(){
            return stack.back();
        }

        int* full(){
            int *elements = new int[stack.size()];
            for (int i = 0; i < stack.size(); i++)
            {
                elements[i] = stack[i];
            }
            return elements;
            
        }

        bool empty(){
            return stack.empty();
        }

        int size(){
            return stack.size();
        }
};

int main(){

    Stack myStack;

    int x;
    while(x != 6){
        cout << "Press 1 to Push" << endl;
        cout << "Press 2 to Pop" << endl;
        cout << "Press 3 to View the top element" << endl;
        cout << "Press 4 to View the Whole Stack" << endl;
        cout << "Press 5 to check if the Stack is Empty" << endl;
        cout << "Press 6 to Exit" << endl;
        cout << "Enter your Choice: " << endl;
        cin >> x;
        switch (x){
            case 1:{
                cout << "Enter the Value to Push to the Stack" << endl;
                int input;
                cin >> input;
                myStack.push(input);
                cout << "Pushed " << input << " to the Stack" << endl;
                break;
            }
            
            case 2:{
                int popped_element = myStack.pop();
                cout << "The element '" << popped_element << "' has been removed from the Stack" << endl;
                break;
            }
            
            case 3:{
                int top = myStack.top();
                cout << "The topmost element of the Stack is: " << top << endl;
                break;
            }

            case 4:{
                cout << "The whole Stack is: " << endl;
                int* elements = myStack.full();
                for (int i = 0; i < myStack.size(); i++) {
                    cout << elements[i] << " ";
                }
                cout << endl;
                delete[] elements;
                break;
            }

            case 5:{
                if(myStack.empty()){
                    cout << "Stack is Empty" << endl;
                }else{
                    cout << "Stack is not Empty" << endl;
                }
                break;
            }

            case 6:{
                cout << "Exiting.." << endl;
                exit(0);
                break;
            }
        }

    }

    return 0;
}