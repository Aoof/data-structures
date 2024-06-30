// Cookie.h

#include <iostream>
using namespace std;

#ifndef COOKIE_H
#define COOKIE_H

class Cookie {
    private:
        string color;

    public:
        Cookie(string color) {
            this->color = color;
        }

        string getColor() {
            return this->color;
        }
};

#endif