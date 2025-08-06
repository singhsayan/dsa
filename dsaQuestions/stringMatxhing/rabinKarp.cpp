#include<iostream>
using namespace std;

#define d 256
#define q 101 // A prime number

void rabinKarpSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();
    int h = 1; // h: Helps in removing the leading digit during rolling hash
    int p = 0, t = 0; // p - hash value for pattern , t - hash value for current window of text 


    //We precompute h = pow(d, M-1) % q.
    //Used when removing the leading character from rolling hash
    for(int i = 0; i < M-1; i++)
        h = (h * d) % q;

    // hashing entire pattern and first window of text
    // d is alphabet size (256 is ASCII value)
    // % q keeps number in manageable size (mod prime to prevent overflow)
    for(int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }


    // if pattern matches with hash value of current window check charcter by character to ensure it is true
    for(int i = 0; i <= N - M; i++) {
        if(p == t) {
            bool match = true;
            for(int j = 0; j < M; j++) {
                if(txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if(match) {
                cout << "Pattern found at index " << i + 1 << endl;
            }
        }
        // rolling hash, remove txt[i] and add txt[i + m], %q keeps in range
        if(i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if(t < 0) t += q;
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    cout << "Rabin-Karp Search Results:" << endl;
    rabinKarpSearch(txt, pat);

    return 0;
}
