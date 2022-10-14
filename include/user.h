#pragma once

#include "inbox.h"

class User {
private:
public:
    User *next;
    int id;
    Inbox *inbox;

    explicit User(int id);

    ~User();
};

