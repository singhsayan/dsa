#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main(){
    // creation
    unordered_map<string, int> m;

    // insertion
    // 1st method
    pair<string,int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2nd method
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // 3rd method
    m["mera"] = 1;

    // search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("bro") << endl;

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
}