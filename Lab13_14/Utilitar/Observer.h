//
// Created by Irimieş Vasile on 5/20/2023.
//

#ifndef LAB10_11_OBSERVER_H
#define LAB10_11_OBSERVER_H
#include <vector>
using std::vector;
class Observer{
public:
    virtual void update()  = 0;
};

class Observable{
private:
    vector <Observer*> lista_observere;
public:
    void notify(){
        for ( const auto obs : lista_observere ){
            obs->update();
        }
    }
    void adauga_observer(Observer* observer){
        lista_observere.push_back(observer);
    }
    void sterge_observer(Observer* observer){
        auto it = lista_observere.begin();
        while ( it != lista_observere.end() && *it != observer )
            it++;
        if ( it != lista_observere.end())
            lista_observere.erase(it);
    }


};

#endif //LAB10_11_OBSERVER_H
