//
// Created by Irimieş Vasile on 3/30/2023.
//

#ifndef LABORATORUL_6_7_ERORI_H
#define LABORATORUL_6_7_ERORI_H
#include <string>
using std::string;

class RepoError :public std::exception{
    private:
        string msg;

    public:
        explicit RepoError(string mesaj);
        string get_message() const;
};

class ValidationError{
private:
    string msg;

public:
    explicit ValidationError(string mesaj);
    string get_message() const;
};

#endif //LABORATORUL_6_7_ERORI_H
