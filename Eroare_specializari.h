//
// Created by Dragosh on 1/16/2023.
//

#ifndef MAIN_CPP_EROARE_SPECIALIZARI_H
#define MAIN_CPP_EROARE_SPECIALIZARI_H

#include <exception>
#include <stdexcept>
#include <iostream>


class Eroare_specializari : public std::runtime_error {
    using std::runtime_error::runtime_error;
};


#endif //MAIN_CPP_EROARE_SPECIALIZARI_H
