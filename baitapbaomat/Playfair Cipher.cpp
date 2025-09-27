#include <bits/stdc++.h>
using namespace std;

string prepare_playfair_text(const string &s){
    string t;
    for(char ch: s){
        if(isalpha(ch)){
            char c = toupper(ch);
            if(c == 'J') c = 'I'; // merge J->I
            t += c;
        }
    }
    // insert X between repeated letters in pair and ensure even length
    string out;
    for(size_t i=0;i<t.size();){
        char a = t[i];
        char b = (i+1 < t.size() ? t[i+1] : '\0');
        if(b == '\0'){
            out += a; out += 'X'; break;
        }
        if(a == b){
            out += a; out += 'X'; i++;
        } else {
            out += a; out += b; i += 2;
        }
    }
    if(out.size() % 2 == 1) out += 'X';
    return out;
}

vector<vector<char>> generate_table(const string &key){
    string seq;
    vector<bool> used(26,false);
    for(char ch: key){
        if(!isalpha(ch)) continue;
        char c = toupper(ch);
        if(c == 'J') c = 'I';
        if(!used[c - 'A']){
            used[c - 'A'] = true;
            seq += c;
        }
    }
    for(char c='A'; c<='Z'; ++c){
        if(c == 'J') continue;
        if(!used[c-'A']){
            seq += c;
            used[c-'A'] = true;
        }
    }
    vector<vector<char>> table(5, vector<char>(5));
    for(int i=0;i<25;i++) table[i/5][i%5] = seq[i];
    return table;
}

pair<int,int> find_pos(const vector<vector<char>> &table, char c){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(table[i][j]==c) return {i,j};
    return {-1,-1};
}

string playfair_encrypt(const string &pt, const string &key){
    auto table = generate_table(key);
    string t = prepare_playfair_text(pt);
    string out;
    for(size_t i=0;i<t.size(); i+=2){
        char a = t[i], b = t[i+1];
        auto pa = find_pos(table, a);
        auto pb = find_pos(table, b);
        if(pa.first == pb.first){ // same row
            out += table[pa.first][(pa.second+1)%5];
            out += table[pb.first][(pb.second+1)%5];
        } else if(pa.second == pb.second){ // same column
            out += table[(pa.first+1)%5][pa.second];
            out += table[(pb.first+1)%5][pb.second];
        } else {
            out += table[pa.first][pb.second];
            out += table[pb.first][pa.second];
        }
    }
    return out;
}

string playfair_decrypt(const string &ct, const string &key){
    auto table = generate_table(key);
    string out;
    for(size_t i=0;i<ct.size(); i+=2){
        char a = toupper(ct[i]), b = toupper(ct[i+1]);
        if(a=='J') a='I'; if(b=='J') b='I';
        auto pa = find_pos(table, a);
        auto pb = find_pos(table, b);
        if(pa.first == pb.first){ // same row
            out += table[pa.first][(pa.second+4)%5];
            out += table[pb.first][(pb.second+4)%5];
        } else if(pa.second == pb.second){ // same column
            out += table[(pa.first+4)%5][pa.second];
            out += table[(pb.first+4)%5][pb.second];
        } else {
            out += table[pa.first][pb.second];
            out += table[pb.first][pa.second];
        }
    }
    return out;
}

int main(){
    string key; cout << "Key: "; getline(cin, key);
    string pt; cout << "Plaintext: "; getline(cin, pt);
    string ct = playfair_encrypt(pt, key);
    cout << "Ciphertext: " << ct << "\n";
    cout << "Decrypted: " << playfair_decrypt(ct, key) << "\n";
    return 0;
}
