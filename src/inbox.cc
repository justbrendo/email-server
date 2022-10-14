#include "inbox.h"

#include <string>

using namespace std;

string Inbox::retrieveMail() {
    if (empty()) return "";
    string result = first_mail->content;
    delete first_mail;
    first_mail = first_mail->next;
    return result;
}

void Inbox::insertMail(string &content, int priority) {
    Mail *mail = new Mail{content, priority, nullptr};
    if (first_mail == nullptr) {
        first_mail = mail;
        return;
    }
    if (priority > first_mail->priority) {
        mail->next = first_mail;
        first_mail = mail;
        return;
    }
    Mail *buffer = first_mail;
    while (buffer->next != nullptr) {
        if (buffer->next->priority < priority) {
            break;
        }
        buffer = buffer->next;
    }
    mail->next = buffer->next;
    buffer->next = mail;

}

Inbox::Inbox() = default;
