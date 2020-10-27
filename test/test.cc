//
// Created by Ezra on 8/11/2020.
//

#include "decryption.h"
#include "encryption.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// void read_argvs(int argc, char const* argv[])
// {
//     for (int i = 2; i < argc; i += 2) {
//         if (!strcmp(argv[i], "-p")) {
//         } else if (!strcmp(argv[i], "-o")) {
//         }
//     }
// }

void print_help()
{
    cout << "usage :" << endl;
    cout << "AES ${filename} [-p ${password}]" << endl;
    cout << "[note] The default password is 12345678" << endl;
}

int main(int argc, char const* argv[])
{
    // read_argvs(argc, argv);
    char key[] = "123456789";
    char* key_temp = nullptr;
    ifstream file(argv[1]);
    char* default_key = key;
    if (!strcmp(argv[2], "-p ")) {
        key_temp = (char*)calloc(strlen(argv[3]) + 1, sizeof(char));
        default_key = key_temp;
    }
    if (file.fail()) {
        cerr << "file not exist" << endl;
        exit(-1);
    }

    auto stream = encryption(file, key);
    file.close();

    ofstream output("output.bin", ios::binary);
    output << stream.rdbuf();
    output.close();

    ifstream input("output.bin", ios::binary);
    auto string = decryption(input, key);
    cout << string << endl;
    input.close();

    if (key_temp != nullptr)
        free(key_temp);

    return 0;
}
