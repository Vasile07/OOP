//
// Created by Irimieş Vasile on 4/4/2023.
//

#ifndef LABORATORUL_6_7_MYSTRING_H
#define LABORATORUL_6_7_MYSTRING_H


class MyString {
private:
    char* continut;
public:
    /***
     * Constructorul Mystring
     * Initializeaza vid stringul
     */
    MyString();

    /***
     * Returneaza sirul de caractere
     * @return char*
     */
    char* get_char() const;

    /***
     * Atribuie sirul dat
     * @param sir_caract char*
     */
    void operator= (char* sir_caract);

    /***
     * Verfiica egalitatea celor doua MyStrings
     * @param ms MyString
     * @return True/False
     */
    bool operator== (MyString& ms) const;

    bool operator== (char* sir) const;
    /***
     * Destructor
     */
    ~MyString();

};


#endif //LABORATORUL_6_7_MYSTRING_H
