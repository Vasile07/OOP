//
// Created by Irimieş Vasile on 4/4/2023.
//

#include "MyString.h"
#include <cstring>


MyString::MyString() {
    this->continut = new char[strlen("")+1];
    strcpy(this->continut, "");
}

char* MyString::get_char() const {
    return this->continut;
}

void MyString::operator=(char *sir_caract) {
    delete[] this->continut;
    this->continut = new char[strlen(sir_caract) + 1];
    strcpy(this->continut, sir_caract);
}

bool MyString::operator==(MyString &ms) const {
    return strcmp(this->continut, ms.get_char()) == 0;
}

MyString::~MyString() {
    delete[] this->continut;
}

bool MyString::operator==(char *sir) const {
    return  ( strcmp(this->continut, sir) == 0 );
}


