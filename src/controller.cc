#include "controller.h"

#include <algorithm>
#include <iostream>

#include "definitions.h"

using namespace std;

Controller::Controller() { first_user = nullptr; };

Search_result Controller::find_user_by_id(int id) {
  Search_result sr;
  if (first_user != nullptr) {
    User* buffer = first_user;
    // Iterate users till null
    while (buffer != nullptr) {
      if (buffer->node->id == id) {  // User found
        sr.user = buffer;
        sr.code = sr_found;
        return sr;
      }
      sr.previous = buffer;
      buffer = buffer->node->next;
    }
  }
  sr.user = first_user;
  sr.code = sr_not_found;
  return sr;  // User not found
}

void Controller::register_user_by_id(int id) {
  Search_result sr = find_user_by_id(id);
  if (sr.code == sr_found) {
    cout << account_already_exists(id);
    return;
  }
  sr.user = new User(id);
  cout << account_created(id);
};

void Controller::remove_user_by_id(int id) {
  Search_result sr = find_user_by_id(id);
  if (sr.code == sr_not_found) {
    cout << account_does_not_exist(id);
    return;
  }
  sr.previous->node->next = sr.user->node->next;
  delete sr.user;
  cout << account_removed(id);
};