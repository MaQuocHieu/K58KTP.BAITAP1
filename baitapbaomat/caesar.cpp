#include <bits/stdc++.h>
using namespace std;

string caesar_encrypt(const string &s, int k){
    k %= 26;
    string out;
    for(char ch: s){
        if(isupper(ch)) out += char((ch - 'A' + k + 26) % 26 + 'A');
        else if(islower(ch)) out += char((ch - 'a' + k + 26) % 26 + 'a');
        else out += ch;
    }
    return out;
}

string caesar_decrypt(const string &s, int k){
    return caesar_encrypt(s, (26 - (k % 26)) % 26);
}

int main(){
    string text;
    cout << "Input text: ";
    getline(cin, text);
    int k;
    cout << "Shift k (0-25): ";
    cin >> k;
    cout << "Encrypted: " << caesar_encrypt(text, k) << "\n";
    cout << "Decrypted: " << caesar_decrypt(caesar_encrypt(text,k), k) << "\n";
    return 0;
}
