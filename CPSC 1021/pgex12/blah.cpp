#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

    int in = 1;
    if (argc > 1) {
        in = stoi(argv[1]);
        cout << in << endl;
    }

    while (in != 1) {

        if (in % 2 == 0) {
            in /= 2;
        } else {
            in = in * 3 + 1;
        }
        cout << in << endl;

    }

    return 0;
}