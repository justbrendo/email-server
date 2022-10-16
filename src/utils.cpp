#include "../include/utils.h"

#define output_msg(s1, s2, amount, time) s1 << " " << amount << " " << s2 << " took: " << time << " ms" << "\n"

#include <chrono>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
using namespace std::chrono;

auto start = high_resolution_clock::now();
auto finish = high_resolution_clock::now();
streambuf *sb;

namespace utils {
    void lower_string(std::string &s) {
        std::for_each(s.begin(), s.end(), [](char &c) { c = ::tolower(c); });
    }

    void start_clock() {
        start = high_resolution_clock::now();
        sb = cout.rdbuf();
        cout.rdbuf(NULL);
    }

    double stop_clock() {
        finish = high_resolution_clock::now();
        sb = cout.rdbuf(sb);
        auto duration = duration_cast<nanoseconds>(finish - start);
        return (double) duration.count() / 1000000;
    }

    void performance_check(Controller *controller) {
        double duration;
        string msg("Why are you reading this piece of code?");
        for (int i = 3; i < 4; i++) {
            int amount = pow(10, i);

            start_clock();
            for (int j = 0; j < amount; j++)
                controller->register_user_by_id(j);
            duration = stop_clock();
            cout << output_msg("Registering", "users", amount, duration);

            start_clock();
            for (int j = 0; j < amount; j++)
                controller->send_message_by_id(j, j, msg);
            duration = stop_clock();
            cout << output_msg("Sending", "messages", amount, duration);

            start_clock();
            for(int j = 0; j < amount; j++)
                controller->retrieve_mail_by_id(j);
            duration = stop_clock();
            cout << output_msg("Retrieving", "messages", amount, duration);

            start_clock();
            for (int j = 0; j < amount; j++)
                controller->remove_user_by_id(j);
            duration = stop_clock();
            cout << output_msg("Removing", "users", amount, duration);

            cout << "\n";
        }

        start_clock();
        controller->register_user_by_id(1);
        for(int i = 0; i < 1000; i ++) {
            controller->send_message_by_id(1, 1, msg);
        }
        duration = stop_clock();
        cout << "Registering a user, then sending him 1,000 emails of same priority took: " << duration << " ms" << "\n";
        start_clock();
        for(int i = 0; i < 1000; i++) {
            controller->retrieve_mail_by_id(1);
        }
        controller->remove_user_by_id(1);
        stop_clock();
        cout << "Retrieving those 1,000 emails took: " << duration << " ms" << "\n";
        cout << "\n";

        start_clock();
        controller->register_user_by_id(1);
        for(int i = 0; i < 1000; i ++) {
            controller->send_message_by_id(1, i, msg);
        }
        duration = stop_clock();
        cout << "Registering a user, then sending him 1,000 emails of increasing priorities took: " << duration << " ms" << "\n";
        start_clock();
        for(int i = 0; i < 1000; i++) {
            controller->retrieve_mail_by_id(1);
        }
        controller->remove_user_by_id(1);
        stop_clock();
        cout << "Retrieving those 1,000 emails took: " << duration << " ms" << "\n";
        cout << "\n";

        start_clock();
        controller->register_user_by_id(1);
        for(int i = 0; i < 1000; i ++) {
            controller->send_message_by_id(1, 1000 - i, msg);
        }
        duration = stop_clock();
        cout << "Registering a user, then sending him 1,000 emails of decreasing priorities took: " << duration << " ms" << "\n";
        start_clock();
        for(int i = 0; i < 1000; i++) {
            controller->retrieve_mail_by_id(1);
        }
        controller->remove_user_by_id(1);
        stop_clock();
        cout << "Retrieving those 1,000 emails took: " << duration << " ms" << "\n";
        cout << "\n";

    }
}  // namespace utils
