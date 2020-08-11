#include <iostream>
#include "encryption.h"
#include "decryption.h"

using namespace std;
int main(int argc, char const* argv[])
{
    cout << encryption("123", "345") << endl;
    return 0;
}
