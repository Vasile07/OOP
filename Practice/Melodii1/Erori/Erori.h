//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_ERORI_H
#define MELODII_1_ERORI_H
#include <string>

using std::string;

class RepoError{
private:
    string msg;
public:
    RepoError(string msg):msg{msg}{}
    string get_msg()const{
        return msg;
    }
};


class ValidationError{
private:
    string msg;
public:
    ValidationError(string msg):msg{msg}{}
    string get_msg()const{
        return msg;
    }
};

#endif //MELODII_1_ERORI_H
