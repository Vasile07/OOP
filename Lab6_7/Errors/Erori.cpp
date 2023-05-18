//
// Created by Irimieş Vasile on 3/30/2023.
//

#include "Erori.h"

#include <utility>

RepoError::RepoError(string mesaj) {
    msg = std::move(mesaj);
}

string RepoError::get_message() const {
    return msg;
}

ValidationError::ValidationError(string mesaj) {
    msg = std::move(mesaj);
}

string ValidationError::get_message() const {
    return msg;
}
