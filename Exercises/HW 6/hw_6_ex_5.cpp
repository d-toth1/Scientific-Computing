#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ifstream key_text("key.txt");
    string line;
    vector<char> all_chars;
    vector<char> encoded_chars;
    vector<char> decoded_chars;

    while(getline(key_text, line)) {
        if(!line.empty()) {
            char c;
            istringstream linefeed(line);
            while( linefeed.get(c) && c != EOF) {
                if(c != ' '){
                    all_chars.push_back(c);
                }
            }
        }
    }
    for(int i = 0; i < all_chars.size(); i++) {
        if(i % 2 == 1) {
            decoded_chars.push_back(all_chars[i]);
        } else if(i % 2 == 0) {
            encoded_chars.push_back(all_chars[i]);
        }
    }

    ifstream encryp_txt("encrypted_text.txt");
    ofstream decryp_txt("decrypted_text.txt");

    while(getline(encryp_txt, line)) {
        string line_decoded;
        for(char c : line) {
            if(c == ' ') {
                line_decoded += c;
            } else {
                for(int i = 0; i < encoded_chars.size(); i++) {
                    if(c == encoded_chars[i]) {
                        line_decoded += decoded_chars[i];
                    }
                }
            }

        }
        decryp_txt << line_decoded << '\n';
    }

    return 0;
}
