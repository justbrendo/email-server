#pragma once

#include "../include/controller.h"

#include <algorithm>
#include <string>

namespace utils {

    // transforms all characters of a string into lower case.
    void lower_string(std::string &s);

    // checks server's performance
    void performance_check(Controller *controller);

};  // namespace utils
