#include <bits/stdc++.h>
using namespace std;

string columnar_encrypt(const string &pt, const string &key){
    int n = key.size();
    int rows = (pt.size() + n - 1) / n;
    vector<string> mat(rows, string(n, '\0'));
    int idx = 0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<n;c++){
            if(idx < (int)pt.size()) mat[r][c] = pt[idx++];
            else mat[r][c] = 'X'; // padding
        }
    }
    // order of columns by sorted key
    vector<pair<char,int>> ord;
    for(int i=0;i<n;i++) ord.push_back({key[i], i});
    sort(ord.begin(), ord.end());
    string ct;
    for(auto &p: ord){
        int c = p.second;
        for(int r=0;r<rows;r++) ct += mat[r][c];
    }
    return ct;
}

string columnar_decrypt(const string &ct, const string &key){
    int n = key.size();
    int rows = (ct.size() + n - 1)/n;
    vector<pair<char,int>> ord;
    for(int i=0;i<n;i++) ord.push_back({key[i], i});
    sort(ord.begin(), ord.end());
    vector<string> cols(n);
    int idx = 0;
    for(auto &p: ord){
        int c = p.second;
        cols[c] = ct.substr(idx, rows);
        idx += rows;
    }
    string pt;
    for(int r=0;r<rows;r++){
        for(int c=0;c<n;c++){
            pt += cols[c][r];
        }
    }
    return pt;
}

int main(){
    string pt; cout << "Plaintext: "; getline(cin, pt);
    string key; cout << "Key (a string): "; getline(cin, key);
    string ct = columnar_encrypt(pt, key);
    cout << "Cipher: " << ct << "\n";
    cout << "Decrypted: " << columnar_decrypt(ct, key) << "\n";
    return 0;
}
