//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_GUI_H
#define MELODII_2_GUI_H
#include "QWidget"
#include "QPainter"
#include "QPushButton"
#include "QLineEdit"
#include "QTableWidget"
#include "QTableView"
#include "../Bussines/ServiceMelodii.h"

class GUI : public QWidget{
private:
    ServiceMelodii& lista_melodii;

    QPushButton* buton_adauga = new QPushButton("Adauga");
    QPushButton* buton_sterge = new QPushButton("Sterge");

    QLineEdit* edit_id = new QLineEdit;
    QLineEdit* edit_titlu = new QLineEdit;
    QLineEdit* edit_artist = new QLineEdit;
    QLineEdit* edit_gen = new QLineEdit;

    QTableWidget* table = new QTableWidget;
    QTableView* tableView = new QTableView;

    void Design();

    void AssignTask();

    void adauga_gui();

    void sterge_gui();

    void afisare_gui();

    void clear_contents();

    void populare_gui();

    void paintEvent(QPaintEvent *event) override{
        QPoint pop{100,400},rock{400,400},folk{100,600},disco{400,600};
        QPainter painter{this};

        int r_pop = 50, r_rock = 50, r_folk = 50, r_disco = 50;
        painter.drawEllipse(pop,r_pop,r_pop);
        painter.drawEllipse(rock,r_rock,r_rock);
        painter.drawEllipse(folk,r_folk,r_folk);
        painter.drawEllipse(disco,r_disco,r_disco);

        for ( int i = 0 ; i < lista_melodii.numar_melodii_gen_dat("pop");i++){
            r_pop+=10;
            painter.drawEllipse(pop,r_pop,r_pop);
        }
        for ( int i = 0 ; i < lista_melodii.numar_melodii_gen_dat("rock");i++){
            r_rock+=10;
            painter.drawEllipse(rock,r_rock,r_rock);
        }
        for ( int i = 0 ; i < lista_melodii.numar_melodii_gen_dat("folk");i++){
            r_folk+=10;
            painter.drawEllipse(folk,r_folk,r_folk);
        }
        for ( int i = 0 ; i < lista_melodii.numar_melodii_gen_dat("disco");i++){
            r_disco+=10;
            painter.drawEllipse(disco,r_disco,r_disco);
        }
    }

public:
    GUI(ServiceMelodii& service):lista_melodii{service}{
        Design();
        AssignTask();
    }

    void ruleaza_gui(){
        this->show();
        afisare_gui();
    }
};


#endif //MELODII_2_GUI_H
