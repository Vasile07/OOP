//
// Created by Irimieş Vasile on 6/19/2023.
//

#include "Student.h"

int Student::get_numar_matricol() const {
    return numar_matricol;
}

string Student::get_nume() const {
    return nume;
}

int Student::get_varsta() const {
    return varsta;
}

string Student::get_facultate() const {
    return facultate;
}

void Student::set_varsta(int varsta_noua) {
    varsta = varsta_noua;
}
