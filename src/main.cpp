#include <iostream>
#include "../include/controller.h"
using namespace std;

int main() {
    Controller controller;
    cout << "Initializing controller..." << endl;
    controller.run(); //while running, will translate user input from controller to program to then be used for coded commands (using xinput library, only on windows, I am coding on macOS)
}