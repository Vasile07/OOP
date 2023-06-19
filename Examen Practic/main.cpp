#include <QApplication>
#include <QPushButton>

#include "Test/Test.h"
#include "Presentation/GUI.h"

#include "iostream"

class A{
    public:
    virtual void print(){
        std::cout << "printA" << std::endl;
    }
    ~A(){
        std::cout << "~A" << std::endl;
    }
};

class B:public A{
    public:
    void print(){
        std::cout << "printB" << std::endl;
    }
    ~B(){
        std::cout << "~B" << std::endl;
    }
};



int main(int argc, char *argv[]) {
    A* a = new A;
    B* b = new B;
    a->print();
    b->print();
    delete a;
    delete b;

}
