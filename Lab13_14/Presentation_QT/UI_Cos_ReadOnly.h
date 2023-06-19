//
// Created by Irimieş Vasile on 5/31/2023.
//

#ifndef LAB10_11_UI_COS_READONLY_H
#define LAB10_11_UI_COS_READONLY_H


#include "../Utilitar/Observer.h"
#include "../Bussines/ServiceFilme.h"
#include <QWidget>
#include <QPainter>



class UI_Cos_ReadOnly : public Observer, public QWidget {
private:
    ServiceFilme& lista_filme;
    void paintEvent(QPaintEvent* event) override{
        QPainter painter{this};
        int x = 10;
        for(auto& film : lista_filme.get_cos()){
            painter.drawEllipse(x,10,10,10);
            x+=20;
        }
    }

    void update()override{
        repaint();
    }
public:
    UI_Cos_ReadOnly(ServiceFilme& service) : lista_filme{service}{
        lista_filme.adauga_observer(this);
    }
};


#endif //LAB10_11_UI_COS_READONLY_H
