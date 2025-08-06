#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Stack{
    public:
        int top;
        int size;
        int *arr;

        Stack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int x){
            if(size - top >= 1){
                top++;
                arr[top] = x;
            }
        }

        int pop(){
            if(top >= 0){
                int ele = arr[top];
                top--;
                return ele;
            }
            else{
                return -1;
            }
        }

        bool isEmpty() {
            return top == -1;
        }

        bool check(string s){
            Stack st(s.size());
            for(int i = 0; i < s.size(); i++){
                char ch = s[i];
                if(ch =='(' || ch == '{' || ch == '['){
                    st.push(ch);
                }
                else{
                    if(!st.isEmpty()){
                        char current = st.arr[st.top];
                        if((current == '(' && ch == ')') || (current == '{' && ch == '}') || (current == '[' && ch == ']')){
                            st.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
            if(!st.isEmpty()){
                return false;
            }
            else{
                return true;
            }
        }
};

int main() {
    string input;
    cout << "Enter a string with parentheses to check: ";
    cin >> input;

    Stack stack(input.size());
    if (stack.check(input)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are not balanced.\n";
    }

    return 0;
}