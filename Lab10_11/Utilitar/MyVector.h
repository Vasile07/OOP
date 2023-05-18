//
// Created by Irimieş Vasile on 4/11/2023.
//

#include "../Domain/Film.h"

#ifndef LABORATORUL_6_7_MYVECTOR_H
#define LABORATORUL_6_7_MYVECTOR_H

#endif //LABORATORUL_6_7_MYVECTOR_H
template <typename TElem>
class IteratorVector;

template <typename TElem>
class MyVector{
private:
    TElem* elems;
    int n;
    int capacitate;
    void redimesionare();

public:

    /**
     * Creeza un obiect al clasei MyVector
     */
    MyVector();

    /**
     * Adauga un element in vector
     * @param elem
     */
    void push_back(const TElem& elem);

    /**
     * Sterge ultimul element
     */
    void pop_back();

    /**
     * Returneaza dimensiunea listei
     * @return int - dimensiune
     */
    [[nodiscard]] int size() const;

    TElem& operator[](int poz) const{
        return elems[poz];
    }

    ~MyVector();

    friend class IteratorVector<TElem>;
    IteratorVector<TElem> begin() const;
    IteratorVector<TElem> end() const;



};

template<typename TElem>
IteratorVector<TElem> MyVector<TElem>::end() const {
    return IteratorVector<TElem>(*this, n);
}

template<typename TElem>
IteratorVector<TElem> MyVector<TElem>::begin() const {
    return IteratorVector<TElem>(*this);
}

template<typename TElem>
MyVector<TElem>::~MyVector() {
    delete[] elems;
}

template<typename TElem>
MyVector<TElem>::MyVector() {
    capacitate = 2;
    n  = 0;
    elems = new TElem[capacitate];
}

template<typename TElem>
void MyVector<TElem>::push_back(const TElem& elem) {
    if ( n == capacitate )
        redimesionare();
    elems[n] = elem;
    n++;
}

template<typename TElem>
void MyVector<TElem>::pop_back() {
    n--;
}

template<typename TElem>
void MyVector<TElem>::redimesionare() {
    auto* new_elems = new TElem[capacitate*2];
    for ( int i = 0 ; i < n ; i ++ )
        new_elems[i] = elems[i];
    delete[] elems;
    elems = new_elems;
    capacitate = 2 * capacitate;
}

template<typename TElem>
int MyVector<TElem>::size() const{
    return n;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename TElem>
class IteratorVector{
private:
    const MyVector<TElem>& v;
    int curent;
    void urmator();
    TElem& element();
    bool valid();
public:
    TElem& operator*();
    IteratorVector<TElem>& operator++();
    explicit IteratorVector(const MyVector<Film>& v): v{v}, curent{0}{}
    IteratorVector(const MyVector<TElem>& v, int poz): v{v}, curent{poz}{}
    bool operator==(const IteratorVector& ot);
    bool operator!=(const IteratorVector& ot);
};

template<typename TElem>
bool IteratorVector<TElem>::operator!=(const IteratorVector &ot) {
    return curent != ot.curent;
}


template<typename TElem>
bool IteratorVector<TElem>::operator==(const IteratorVector &ot) {
    return curent == ot.curent;
}

template<typename TElem>
IteratorVector<TElem> &IteratorVector<TElem>::operator++() {
    urmator();
    return *this;
}


template<typename TElem>
TElem &IteratorVector<TElem>::operator*() {
    return element();
}

template<typename TElem>
bool IteratorVector<TElem>::valid() {
    return curent < this->v.n;
}

template<typename TElem>
TElem &IteratorVector<TElem>::element() {
    return this->v.elems[curent];
}

template<typename TElem>
void IteratorVector<TElem>::urmator() {
    curent ++;
}
