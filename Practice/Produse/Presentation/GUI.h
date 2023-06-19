//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_GUI_H
#define PRODUSE_BUN_GUI_H
#include "QWidget"
#include "QTableView"
#include "QSlider"
#include "QLineEdit"
#include "QPushButton"
#include "../Business/ServiceProduse.h"
#include "MyModelView.h"

class GUI : public QWidget{
private:
    ServiceProduse& service;

    QLineEdit* edit_id = new QLineEdit;
    QLineEdit* edit_nume = new QLineEdit;
    QLineEdit* edit_tip = new QLineEdit;
    QLineEdit* edit_pret = new QLineEdit;

    QSlider* slider_pret = new QSlider;

    QPushButton* buton_adauga = new QPushButton{"Adauga Produs"};

    QTableView* tableView = new QTableView;
    MyModelView* model = new MyModelView;

    void Design();
    void AssignTask();

    void afisare();

    void adauga();

    void filtru();

    void clear_fields();

    vector<QWidget*> ferestre;
    void formare_ferestre();

    void for_select();

public:
    GUI(ServiceProduse& service):service{service}{
        Design();
        AssignTask();
    }

    void ruleaza_gui(){
        this->show();
        afisare();
    }

    void closeEvent(QCloseEvent *event) override{
        for(auto& fereastra : ferestre){
            delete fereastra;
        }
        ferestre.clear();
    }
};


#endif //PRODUSE_BUN_GUI_H
