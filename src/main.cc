#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "controller.h"
#include "definitions.h"
#include "utils.h"

using namespace std;

Controller *controller;

void parse_input(istringstream &in) {
    string word_;
    in >> word_;
    utils::lower_string(word_);
    if (word_ == input_user_register) {
        int id;
        in >> id;
        controller->register_user_by_id(id);
        return;
    }
}

int main(int argc, char **argv) {
    // File for inputs
    string file = argv[1];

    ifstream inputs_(file);
    if (!inputs_.is_open()) {
        cout << "Failed to load the specified file."
             << "\n";
        cout << "Usage: ./run.out <filename>"
             << "\n";
        return 1;
    }

    controller = new Controller();

    string line;
    while (getline(inputs_, line)) {
        istringstream iss(line);
        parse_input(iss);
    }

    return 0;
}