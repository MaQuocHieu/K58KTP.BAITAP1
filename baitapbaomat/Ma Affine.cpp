#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y){
    if(b==0){ x=1; y=0; return a; }
    int x1,y1;
    int g = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int modinv(int a, int m){
    int x,y;
    int g = egcd(a,m,x,y);
    if(g != 1) return -1;
    x %= m;
    if(x < 0) x += m;
    return x;
}

string affine_encrypt(const string &s, int a, int b){
    string out;
    for(char ch: s){
        if(isupper(ch)){
            int x = ch - 'A';
            out += char((a*x + b) % 26 + 'A');
        } else if(islower(ch)){
            int x = ch - 'a';
            out += char((a*x + b) % 26 + 'a');
        } else out += ch;
    }
    return out;
}

string affine_decrypt(const string &s, int a, int b){
    int a_inv = modinv(a, 26);
    if(a_inv == -1) return "[ERROR: no modular inverse for a]";
    string out;
    for(char ch: s){
        if(isupper(ch)){
            int y = ch - 'A';
            int x = (a_inv * ((y - b + 26) % 26)) % 26;
            out += char(x + 'A');
        } else if(islower(ch)){
            int y = ch - 'a';
            int x = (a_inv * ((y - b + 26) % 26)) % 26;
            out += char(x + 'a');
        } else out += ch;
    }
    return out;
}

int main(){
    string text;
    cout << "Text: "; getline(cin, text);
    int a,b; cout << "a (must be coprime with 26): "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Encrypted: " << affine_encrypt(text,a,b) << "\n";
    cout << "Decrypted: " << affine_decrypt(affine_encrypt(text,a,b), a, b) << "\n";
    return 0;
}
