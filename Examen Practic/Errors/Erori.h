//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_ERORI_H
#define IRIMIES_VASILE_EMILIAN_ERORI_H
#include "string"
using std::string;

class RepoError{

private:

    string msg;

public:

    /**
     * Constructor RepoError
     * @param msg string
     */
    RepoError(string msg):msg{msg}{}

    /**
     * Returneaza mesajul de eroare agregat
     * @return string
     */
    string get_msg()const{
        return msg;
    }

};

#endif //IRIMIES_VASILE_EMILIAN_ERORI_H
