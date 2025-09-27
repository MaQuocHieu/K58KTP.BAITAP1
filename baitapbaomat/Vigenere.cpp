#include <bits/stdc++.h>
using namespace std;

string normalize_key(const string &key){
    string k;
    for(char ch: key) if(isalpha(ch)) k += toupper(ch);
    return k;
}

string vigenere_encrypt(const string &pt, const string &key){
    string K = normalize_key(key);
    if(K.empty()) return "[ERROR: empty key]";
    int ki = 0, klen = K.size();
    string out;
    for(char ch: pt){
        if(isupper(ch)){
            int shift = K[ki % klen] - 'A';
            out += char((ch - 'A' + shift) % 26 + 'A');
            ki++;
        } else if(islower(ch)){
            int shift = K[ki % klen] - 'A';
            out += char((ch - 'a' + shift) % 26 + 'a');
            ki++;
        } else out += ch;
    }
    return out;
}

string vigenere_decrypt(const string &ct, const string &key){
    string K = normalize_key(key);
    if(K.empty()) return "[ERROR: empty key]";
    int ki = 0, klen = K.size();
    string out;
    for(char ch: ct){
        if(isupper(ch)){
            int shift = K[ki % klen] - 'A';
            out += char((ch - 'A' - shift + 26) % 26 + 'A');
            ki++;
        } else if(islower(ch)){
            int shift = K[ki % klen] - 'A';
            out += char((ch - 'a' - shift + 26) % 26 + 'a');
            ki++;
        } else out += ch;
    }
    return out;
}

int main(){
    string pt; cout << "Plaintext: "; getline(cin, pt);
    string key; cout << "Key: "; getline(cin, key);
    string ct = vigenere_encrypt(pt, key);
    cout << "Cipher: " << ct << "\n";
    cout << "Decrypted: " << vigenere_decrypt(ct, key) << "\n";
    return 0;
}
