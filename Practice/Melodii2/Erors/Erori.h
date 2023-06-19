//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_ERORI_H
#define MELODII_2_ERORI_H
#include <string>

using std::string;

class RepoError{
private:
    string msg;
public:
    RepoError(string msg):msg{msg}{}
    string get_msg(){
        return msg;
    }
};

class ValidationError{
private:
    string msg;
public:
    ValidationError(string msg):msg{msg}{}
    string get_msg(){
        return msg;
    }
};
#endif //MELODII_2_ERORI_H
