#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string A) {
            map<char, int> m;
            string ans = "";
            queue<char> q;

            for(int i = 0; i < A.length(); i++) {
                char ch = A[i];

                q.push(ch);
                m[ch]++;

                while(!q.empty()) {
                    if(m[q.front()] > 1) {
                        q.pop();
                    }
                    else {
                        ans.push_back(q.front());
                        break;
                    }
                }
                if(q.empty()) {
                    ans.push_back('#');
                }
            }
            return ans;
        }
};

int main() {
    Solution sol;
    string A;

    cout << "Enter the input string: ";
    cin >> A;

    string result = sol.FirstNonRepeating(A);
    cout << "First non-repeating characters sequence: " << result << endl;

    return 0;
}