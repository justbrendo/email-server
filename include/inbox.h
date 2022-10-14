#pragma once

#include <string>
#include "user.h"

using namespace std;

struct Mail {
    string content;
    int priority;
};

class Inbox {
private:
public:
    Inbox();

    User *owner;
};