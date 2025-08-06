#include<iostream>
#include<vector>
using namespace std;

void computeLPS(string pat, vector<int> &lps) {
    int len = 0; //  length of current proper prefix which is also suffix
    int i = 1; // loop index through the pattern
    lps[0] = 0; // a single character has no proper prefix/suffix

    while(i < pat.length()) {
        if(pat[i] == pat[len]) { // if characters match then increase len, mobve forward index and assign it to lps
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) { // if characters don't match and len not equal to 0 then move back to shorter prefix
                len = lps[len - 1];
            } else {
                lps[i] = 0; // just set lps to 0
                i++;
            }
        }
    }
}

// advantage of kmp instead of starting over we use lps to skip redundant comparisons

void KMPSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();

    vector<int> lps(M);
    computeLPS(pat, lps);

    int i = 0, j = 0;
    while(i < N) {
        if(txt[i] == pat[j]) {
            i++;
            j++;
        }

        if(j == M) {
            cout << "Pattern found at index " << i - j + 1 << endl; // + 1 for 1 based index
            j = lps[j - 1]; // done reset to look for next possible match(support for overlapping problems) 
        }
        else if(i < N && txt[i] != pat[j]) {
            if(j != 0) {
                j = lps[j - 1]; // if charcters don't match fall back in pattern using LPS
            } else {
                i++; // else move forward in the text
            }
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    cout << "KMP Search Results:" << endl;
    KMPSearch(txt, pat);

    return 0;
}
