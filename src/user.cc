#include "user.h"

User::User(int id) {
    this->node = new User_node;
    node->id = id;
    node->inbox = new Inbox();
    node->next = nullptr;
};

User::~User() {
    delete this->node->inbox;
    delete this->node;
}