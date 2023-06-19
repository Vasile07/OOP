//
// Created by Irimieş Vasile on 6/19/2023.
//

#include <QFormLayout>
#include <iostream>
#include <QMessageBox>
#include "GUI.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QHeaderView"
void GUI::Design() {
    QHBoxLayout* this_layout = new QHBoxLayout;
    this->setLayout(this_layout);

    QWidget* left = new QWidget;
    QVBoxLayout* left_layout = new QVBoxLayout;
    left->setLayout(left_layout);

    QWidget* form = new QWidget;
    QFormLayout* form_layout = new QFormLayout;
    form->setLayout(form_layout);

    form_layout->addRow("ID",edit_id);
    form_layout->addRow(buton_sterge);
    form_layout->addRow(buton_intinereste);
    form_layout->addRow(buton_imbatraneste);
    form_layout->addRow(buton_undo);
    form_layout->addRow(buton_redo);

    left_layout->addWidget(form);

    QWidget* right = new QWidget;
    QVBoxLayout* right_layout = new QVBoxLayout;
    right->setLayout(right_layout);

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setModel(model);
    right_layout->addWidget(tableView);


    this_layout->addWidget(left);
    this_layout->addWidget(right);
    this->resize(1000,800);
    this->move(0,0);

}

void GUI::AssignTask() {
    QObject::connect(buton_intinereste,&QPushButton::clicked,this,&GUI::intinereste);
    QObject::connect(buton_imbatraneste,&QPushButton::clicked,this,&GUI::imbatraneste);
    QObject::connect(tableView->selectionModel(),&QItemSelectionModel::selectionChanged,this,&GUI::selectie);
    QObject::connect(buton_sterge,&QPushButton::clicked,this,&GUI::sterge);
    QObject::connect(buton_undo,&QPushButton::clicked,this,&GUI::undo);
    QObject::connect(buton_redo,&QPushButton::clicked,this,&GUI::redo);
}

void GUI::afiseaza() {
    model->set_lista(service.get_all());
}

void GUI::intinereste() {
    lista_undo.push({{},"intinereste"});
    service.intinerire();
    afiseaza();
}

void GUI::imbatraneste() {
    lista_undo.push({{},"imbatraneste"});
    service.imbatranire();
    afiseaza();
}

void GUI::selectie() {
    string s = "";
    for(const auto& index : tableView->selectionModel()->selectedIndexes()){
        s += tableView->model()->data(index).toString().toStdString() + " ";
    }
    edit_id->setText(QString::fromStdString(s));
}

void GUI::sterge() {
    string s = edit_id->text().toStdString();
    char linie[1000];
    strcpy(linie,s.c_str());
    char* p = strtok(linie," ");
    vector<Student> l;
    while(p!=NULL){
        l.push_back(service.cauta_student_numar_matricol(atoi(p)));
        service.sterge_student_dupa_id(atoi(p));
        p = strtok(NULL, " ");
    }
    afiseaza();
    edit_id->clear();
    lista_undo.push({l,"sterge"});
}

void GUI::undo() {
    if(!lista_undo.empty()) {
        auto l = lista_undo.top();
        lista_undo.pop();
        if (l.second == "sterge")
            for (auto S: l.first)
                service.adauga_student(S);
        else if (l.second == "imbatraneste")
            service.intinerire();
        else
            service.imbatranire();
        lista_redo.push(l);
        afiseaza();
    }
    else
        QMessageBox::warning(this,"Warning",QString("Nu mai se poate face undo!"));
}

void GUI::redo() {
    if(!lista_redo.empty()){
        auto l = lista_redo.top();
        lista_redo.pop();
        if (l.second == "sterge")
            for (auto S: l.first)
                service.sterge_student_dupa_id(S.get_numar_matricol());
        else if (l.second == "imbatraneste")
            service.imbatranire();
        else
            service.intinerire();
        lista_undo.push(l);
        afiseaza();
    }
    else
        QMessageBox::warning(this,"Warning",QString("Nu mai se poate face redo!"));
}