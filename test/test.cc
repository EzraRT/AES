//
// Created by Ezra on 8/11/2020.
//

#include <iostream>
#include "encryption.h"
#include "decryption.h"
#include<fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    char key[] = "1234567898765430";
    ifstream file("input.txt");

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

    return 0;
}
