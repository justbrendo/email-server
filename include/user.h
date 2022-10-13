#pragma once

#include "inbox.h"

class User;

struct User_node {
    User *next;
    int id;
    Inbox *inbox;
};

class User {
private:
public:
    User_node *node;

    explicit User(int id);

    ~User();
};

