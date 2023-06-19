//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_ERORI_H
#define PRODUSE_BUN_ERORI_H

#include <string>
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

class ValidationError{

private:

    string msg;

public:

    /**
     * Constructor ValidationError
     * @param msg string
     */
    ValidationError(string msg):msg{msg}{}

    /**
     * Returneaza mesajul de eroare agregat
     * @return string
     */
    string get_msg()const{
        return msg;
    }

};

#endif //PRODUSE_BUN_ERORI_H
