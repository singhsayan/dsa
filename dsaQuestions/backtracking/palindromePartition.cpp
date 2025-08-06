#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string &str, int start, int end){
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}

void partition(int start, vector<string>&current, vector<vector<string>>&result, string &str){
    if(start == str.length()){
        result.push_back(current);
        return;
    }

    if(start > str.length() || start < 0) return;

    for(int end = start; end < str.length(); end++){
        if(isPalindrome(str,start, end)){
            current.push_back(str.substr(start, end - start + 1));

            partition(end + 1, current, result, str);

            current.pop_back();
        }
    }
}

int main(){
    int size;
    cout << "Enter size of the string:" << endl;
    cin >> size;

    string str;

    cout << "Enter characters present in string:" << endl;
    for(int i = 0; i < size; i++){
        int character;
        cin >> character;
        str.push_back(character);
    }

    vector<vector<string>> result;
    vector<string> current;

    partition(0, current, result, str);

    cout << "All partitions present in the given string are:" << endl;
    for(auto &part: result){
        for(string &ele: part){
            cout << ele << " " << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}