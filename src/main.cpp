#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "controller.h"
#include "utils.h"

using namespace std;

Controller *controller;

// Input types
#define input_user_register "cadastra"
#define input_user_removal "remove"
#define input_send_mail "entrega"
#define input_retrieve_mail "consulta"

int debug = 0;

void parse_input(istringstream &in) {
    string word_;
    in >> word_;
    utils::lower_string(word_);
    int id;
    in >> id;
    if (word_ == input_user_register)
        return controller->register_user_by_id(id);

    if (word_ == input_user_removal)
        return controller->remove_user_by_id(id);

    if (word_ == input_send_mail) {
        int priority;
        in >> priority;
        string content;
        string buffer;
        while (in >> buffer && buffer != "FIM")
            content.append(" " + buffer);
        return controller->send_message_by_id(id, priority, content);
    }

    if (word_ == input_retrieve_mail) {
        return controller->retrieve_mail_by_id(id);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Input not specified."
             << "\n";
        cout << "Usage: ./run.out <filename>"
             << "\n"
             << "'-d' can be passed as argument to enable debugging"
             << "\n";
        return 1;
    }

    if(argc == 3) {
        if(argv[2] == "-d")
    }
    // File for inputs
    string file = argv[1];

    ifstream inputs_(file);
    if (!inputs_.is_open()) {
        cout << "Failed to load the specified file."
             << "\n";
        cout << "Usage: ./run.out <filename>"
             << "\n"
             << "'-d' can be passed as argument to enable debugging"
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