#pragma once

#include <string>

#include "user.h"

using namespace std;

#define sr_not_found -1
#define sr_found 1

struct Search_result {
    User *user;
    User *previous;
    int code;
};

class Controller {
private:
    User *first_user;

    Search_result find_user_by_id(int id);

public:
    Controller();

    void register_user_by_id(int id);

    void remove_user_by_id(int id);
};