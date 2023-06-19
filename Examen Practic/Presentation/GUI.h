//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_GUI_H
#define IRIMIES_VASILE_EMILIAN_GUI_H

#include <QTableView>
#include "QWidget"
#include "../Business/SerivceStudenti.h"
#include "MyModelView.h"
#include "QLineEdit"
#include "QPushButton"
#include <stack>
using std::stack;
using std::pair;

class GUI : public QWidget{
private:
    SerivceStudenti service;

    QLineEdit* edit_id = new QLineEdit;
    QPushButton* buton_sterge = new QPushButton("Sterge");
    QPushButton* buton_imbatraneste = new QPushButton("Imbatraneste");
    QPushButton* buton_intinereste = new QPushButton("Intinereste");
    QPushButton* buton_undo = new QPushButton("Undo");
    QPushButton* buton_redo = new QPushButton("Redo");


    void Design();
    void AssignTask();

    QTableView* tableView = new QTableView;
    MyModelView* model = new MyModelView{service.get_all()};

    void afiseaza();

    void intinereste();

    void imbatraneste();

    void selectie();

    void sterge();

    stack<pair<vector<Student>,string>> lista_undo;

    stack<pair<vector<Student>,string>> lista_redo;

    void undo();

    void redo();

public:
    GUI(SerivceStudenti serivce):service{serivce}{
        Design();
        AssignTask();
    }

    void ruleaza_gui(){
        this->show();
        afiseaza();
    }
};


#endif //IRIMIES_VASILE_EMILIAN_GUI_H
