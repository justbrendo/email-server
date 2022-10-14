#pragma once

#include <string>

using namespace std;

struct Mail {
    string content;
    int priority;
    Mail *next;
};

class Inbox {
private:
public:
    Inbox();

    Mail *first_mail = nullptr;

    void insertMail(string &content, int priority);

    string retrieveMail();

    bool empty() const { return first_mail == nullptr; };
};