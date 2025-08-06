#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    stack<char> s;

    cout << "Enter string:" << endl;
    getline(cin, str);

    for(int i = 0; i < str.length(); i++){
        s.push(str[i]);
    }

    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout << "Reversed string is:" << ans << endl;

    return 0;


}
// Time complexity - O(n)
// Space comnplexity - O(n)