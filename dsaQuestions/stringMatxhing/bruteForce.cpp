#include<iostream>
#include<vector>
using namespace std;

void bruteForceSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();

    for(int i = 0; i <= N - M; i++) {
        int j;
        for(j = 0; j < M; j++) {
            if(txt[i + j] != pat[j]) {
                break;
            }
        }

        if(j == M) {
            cout << "Pattern found at index " << i + 1 << endl;
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    cout << "Brute Force Search Results:" << endl;
    bruteForceSearch(txt, pat);

    return 0;
}
