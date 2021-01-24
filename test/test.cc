#define BOOST_TEST_MODULE AES_TESTS

#include "decryption.h"
#include "encryption.h"
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost;
using namespace std;

string rand_str(size_t length)
{
    string result;
    for (size_t i = 0; i < length; ++i) {
        result.append(1, char(32 + rand() % 95));
    }
    return result;
}

BOOST_AUTO_TEST_CASE(First_Test_Case)
{
    srand(time(NULL));
    std::string teststr = rand_str(rand() % 10000 + 1000ull),
                password("12345678"),
                rawfilename("raw.txt"),
                filename("temp.bin");

    std::fstream rawfile(rawfilename, std::ios::binary | std::ios::out);
    rawfile << teststr;
    rawfile.close();

    rawfile.open(rawfilename, std::ios::binary | std::ios::in);
    std::fstream outfile(filename, std::ios::binary | std::ios::out);
    outfile << encryption(rawfile, password).rdbuf();
    outfile.close();

    std::ifstream infile(filename, std::ios::binary);

    std::string result = decryption(infile, password).str();
    infile.close();
    BOOST_CHECK_EQUAL(teststr, result);
}

// int main(int argc, char const* argv[])
// {

// }
