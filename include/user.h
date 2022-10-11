#pragma once

#include "inbox.h"

struct User_node {
  User* next;
  int id;
  Inbox* inbox;
};

class User {
 private:
 public:
  User_node* node;
  User(int id);
  ~User();
};