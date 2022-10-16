#include "../include/controller.h"

#include <algorithm>
#include <iostream>

// Account creation
#define account_created(id) "OK: CONTA " << id << " CADASTRADA"
#define account_already_exists(id) "ERRO: CONTA " << id << " JA EXISTENTE"

// Account removal
#define account_removed(id) "OK: CONTA " << id << " REMOVIDA"

// Account retrieval
#define account_does_not_exist(id) "ERRO: CONTA " << id << " NAO EXISTE"

// Mail delivery
#define email_sent(id) "OK: MENSAGEM PARA " << id << " ENTREGUE"

// Mail retrieval
#define inbox_empty(id) "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA"
#define inbox_retrieval(id, content) "CONSULTA " << id << ":" << content

using namespace std;

Controller::Controller() { first_user = nullptr; }

Search_result Controller::find_user_by_id(int id) {
    Search_result sr{};
    User *buffer = first_user;
    sr.user = buffer;
    sr.previous = nullptr;
    // Iterate users till null
    while (buffer != nullptr) {
        if (buffer->id == id) {  // User found
            sr.user = buffer;
            sr.code = sr_found;
            return sr;
        }
        sr.previous = buffer;
        buffer = buffer->next;
    }
    // User not found
    sr.code = sr_not_found;
    return sr;
}

void Controller::register_user_by_id(int id) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_found) {
        cout << account_already_exists(id) << "\n";
        return;
    }
    if (first_user == nullptr) {
        first_user = new User(id);
    } else {
        sr.previous->next = new User(id);
    }
    cout << account_created(id) << "\n";
}

void Controller::remove_user_by_id(int id) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_not_found) {
        cout << account_does_not_exist(id) << "\n";
        return;
    }
    if (sr.previous != nullptr) {
        sr.previous->next = sr.user->next;
    } else {
        if(sr.user->next != nullptr) {
            first_user = sr.user->next;
        } else {
            first_user = nullptr;
        }
    }
    delete sr.user;
    cout << account_removed(id) << "\n";
}

void Controller::send_message_by_id(int id, int priority, string &content) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_not_found) {
        cout << account_does_not_exist(id) << "\n";
        return;
    }
    sr.user->inbox->insertMail(content, priority);
    cout << email_sent(id) << "\n";
}

void Controller::retrieve_mail_by_id(int id) {
    Search_result sr = find_user_by_id(id);
    if (sr.code == sr_not_found) {
        cout << account_does_not_exist(id) << "\n";
        return;
    }
    if (sr.user->inbox->empty()) {
        cout << inbox_empty(id) << "\n";
        return;
    }
    string content = sr.user->inbox->retrieveMail();
    cout << inbox_retrieval(id, content) << "\n";
}