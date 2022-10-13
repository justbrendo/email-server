#include "controller.h"

#include <algorithm>
#include <iostream>

#include "definitions.h"

using namespace std;

Controller::Controller() { first_user = nullptr; };

Search_result Controller::find_user_by_id(int id) {
    Search_result sr{};
    User *buffer = first_user;
    sr.user = buffer;
    sr.previous = nullptr;
    // Iterate users till null
    while (buffer != nullptr) {
        if (buffer->node->id == id) {  // User found
            sr.user = buffer;
            sr.code = sr_found;
            return sr;
        }
        sr.previous = buffer;
        buffer = buffer->node->next;
    }
    // User not found
    sr.code = sr_not_found;
    return sr;
}

void Controller::register_user_by_id(int id) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_found) {
        cout << account_already_exists(id) << "\n";
        return;
    }
    if (sr.previous == nullptr) {
        first_user = new User(id);
    } else {
        sr.previous->node->next = new User(id);
    }
    cout << account_created(id) << "\n";
};

void Controller::remove_user_by_id(int id) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_not_found) {
        cout << account_does_not_exist(id);
        return;
    }
    sr.previous->node->next = sr.user->node->next;
    delete sr.user;
    cout << account_removed(id);
};