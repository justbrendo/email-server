#include "../include/user.h"

User::User(int id) {
    this->inbox = new Inbox();
    this->id = id;
    this->next = nullptr;
};

User::~User() {
    delete this->inbox;
}