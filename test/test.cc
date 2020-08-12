#include <iostream>
#include "encryption.h"
#include "decryption.h"

using namespace std;

int main(int argc, char const *argv[]) {
    char raw_str[128] = {0};

    for (int i = 32; i < 127; ++i) {
        raw_str[i - 32] = i;
    }
    cout << raw_str << endl;
    string raw(raw_str);
    string str = encryption(raw);
    cout << str << endl;

    cout << decryption(str) << endl;

    return 0;
}
