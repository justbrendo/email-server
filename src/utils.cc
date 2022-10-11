#include "utils.h"

namespace utils {
void lower_string(std::string& s) {
  std::for_each(s.begin(), s.end(), [](char& c) { c = ::tolower(c); });
};
}  // namespace utils
