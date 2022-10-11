#include "user.h"

User::User(int id) {
  node->id = id;
  node->inbox = new Inbox();
  node->next = nullptr;
};

User::~User() {
  delete this->node->inbox;
  delete this->node;
}