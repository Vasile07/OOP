//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_GUI_H
#define MELODII_1_GUI_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QPainter>
#include <QTableWidget>
#include <QTAbleView>

#include "../Business/ServiceMelodii.h"
#include "MyAbstractMode.h"

class GUI : public QWidget{
private:

    ServiceMelodii& service;

    void paintEvent(QPaintEvent *event) override{
        QPainter painter{this};
        int y = this->height() - 20;
        for ( int rank = 9 ; rank >=0 ; rank--){
            auto l =  service.filtru_dupa_rank(rank);
            painter.drawRect(10,y,10*l.size(),10);
            y = y-20;
        }
    }


    QLineEdit* Edit_id = new QLineEdit;
    QLineEdit* Edit_titlu = new QLineEdit;
    QLineEdit* Edit_artist = new QLineEdit;
    QSlider* Edit_rank = new QSlider;

    QPushButton* buton_adauga = new QPushButton{"Adauga"};
    QPushButton* buton_modifica = new QPushButton{"Modifica"};
    QPushButton* buton_sterge = new QPushButton{"Sterge"};

    QTableView* tableView = new QTableView;
    MyAbstractModel* model = new MyAbstractModel{service.get_all()};
    QTableWidget* tabel = new QTableWidget;

    void AssignTask();
    void Design();

    void adauga_ui();
    void sterge_ui();
    void modifica_ui();
    void incarca_date_ui();
    void afiseaza_ui(vector<Melodie>lista);



public:
    GUI(ServiceMelodii& service):service{service}{}

    void ruleaza_ui(){
        afiseaza_ui(service.get_all());
        Design();
        AssignTask();
        this->show();
    };
};


#endif //MELODII_1_GUI_H
