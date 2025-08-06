#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string str){
    stack<char> s;

    for(int i = 0; i < str.length(); i ++){
        char ch = str[i];

        if(ch == '(' || ch == '[' || ch == '{'  ){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if(ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '['){
                    s.pop();
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
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    
    cout << "Enter string" << endl;
    getline(cin, s);

    if(isValidParenthesis(s)){
        cout << "It is a valid parenthesis" << endl;
    }
    else{
        cout << "It is not a valid parenthesis" << endl;
    }

}