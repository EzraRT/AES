//
// Created by Ezra on 8/11/2020.
//

#include "decryption.h"
#include "encryption.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

string get_output_filename(string input_filename)
{
    string result;
    auto pos = input_filename.rfind('.');
    if (pos == input_filename.npos) {
        //文件名无后缀
        result = input_filename.append(".bin");
    } else {
        result = input_filename.substr(0, pos).append(".bin");
    }
    return result;
}

void print_usage()
{
    cout << "usage :" << endl;
    cout << "AES ${filename} [-p ${password}]" << endl;
    cout << "[note] The default password is 12345678" << endl;
}

int main(int argc, char const* argv[])
{
    char key_default[] = "123456789";
    char* key = key_default;

    if (argc < 2) {
        cerr << "Error, no input file." << endl;
        print_usage();
        return -1;
    }
    string file_name(argv[1]);
    ifstream file(file_name);

    if (file.fail()) {
        cerr << '\'' << file_name << "\' dost not exist" << endl;
        return -1;
    }

    if (argc == 4) {
        // 指定了密码
        char* key_temp;
        if (!strcmp(argv[2], "-p ")) {
            key_temp = (char*)calloc(strlen(argv[3]) + 1, sizeof(char));
        }
        key = key_temp;
    }

    auto stream = encryption(file, key);
    file.close();

    string output_filename = get_output_filename(file_name);

    ofstream output(output_filename, ios::binary);
    output << stream.rdbuf();
    output.close();

    if (key != key_default)
        free(key);

    cout << "Success! The result has been stored in " << output_filename << endl;
    return 0;
}
