//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_STUDENT_H
#define IRIMIES_VASILE_EMILIAN_STUDENT_H
#include <string>

using std::string;

class Student {

private:

    int numar_matricol;
    string nume;
    int varsta;
    string facultate;

public:

    /**
     * Constructorul clasei Student
     * @param numar_matricol int
     * @param nume string
     * @param varsta int
     * @param facultate string
     */
    Student(int numar_matricol, string nume, int varsta, string facultate):numar_matricol{numar_matricol},nume{nume},varsta{varsta},facultate{facultate}{}

    /**
     * Returneaza numarul matricol
     * @return int
     */
    int get_numar_matricol()const;

    /**
     * Returneaza numele studentului
     * @return string
     */
    string get_nume()const;

    /**
     * Returneaza varsta studentului
     * @return int
     */
    int get_varsta()const;

    /**
     * Returneaza facultatea studentului
     * @return string
     */
    string get_facultate()const;

    /**
     * Seteaza varsta cu varsta noua
     * @param varsta_noua int
     */
    void set_varsta(int varsta_noua);

};

#endif //IRIMIES_VASILE_EMILIAN_STUDENT_H
