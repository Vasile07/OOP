//
// Created by Irimieş Vasile on 6/18/2023.
//

#include "GUI.h"
#include "QMessageBox"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QFormLayout"
#include "QHeaderView"
#include "QLabel"
#include "../Erori/Erori.h"

void GUI::Design() {
    QHBoxLayout* this_layout = new QHBoxLayout;
    this->setLayout(this_layout);

    QWidget* left = new QWidget;
    QVBoxLayout* left_layout = new QVBoxLayout;
    left->setLayout(left_layout);

    QWidget* form = new QWidget;
    QFormLayout* form_layout = new QFormLayout;
    form->setLayout(form_layout);

    form_layout->addRow("Id",edit_id);
    form_layout->addRow("Nume",edit_nume);
    form_layout->addRow("Tip",edit_tip);
    form_layout->addRow("Pret",edit_pret);
    form_layout->addRow(buton_adauga);
    form_layout->addRow(slider_pret);
    left_layout->addWidget(form);

    slider_pret->setOrientation(Qt::Horizontal);
    slider_pret->setMinimum(0);
    slider_pret->setMaximum(100);

    QWidget* right = new QWidget;
    QVBoxLayout* right_layout = new QVBoxLayout;
    right->setLayout(right_layout);

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setModel(model);
    right_layout->addWidget(tableView);

    this_layout->addWidget(left);
    this_layout->addWidget(right);
    this->move(0,0);
    this->resize(1000,600);
}

void GUI::AssignTask() {
    QObject::connect(buton_adauga,&QPushButton::clicked,this,&GUI::adauga);
    QObject::connect(slider_pret,&QSlider::valueChanged,this,&GUI::filtru);
    QObject::connect(tableView->selectionModel(),&QItemSelectionModel::selectionChanged,this,&GUI::for_select);
}

void GUI::afisare() {
    model->set_lista(service.get_all());
    formare_ferestre();
}

void GUI::adauga() {
    int id = edit_id->text().toInt();
    string nume = edit_nume->text().toStdString();
    string tip = edit_tip->text().toStdString();
    double pret = edit_pret->text().toDouble();
    try{
        service.adauga_produs_service(id,nume,tip,pret);
        afisare();
        clear_fields();
    }catch (RepoError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }catch (ValidationError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }
}

void GUI::filtru() {
    int pret = slider_pret->value();
    model->set_pret(pret);
}

void GUI::clear_fields() {
    edit_id->clear();
    edit_nume->clear();
    edit_tip->clear();
    edit_pret->clear();
}

void GUI::formare_ferestre() {
    for(auto& fereasta : ferestre)
        delete fereasta;
    ferestre.clear();

    auto m = service.tipuri_si_nr_aparitii();
    int x=this->width(),y=0;
    for(const auto& el : m){
        QWidget* fereastra = new QWidget;
        QVBoxLayout* layout = new QVBoxLayout;
        fereastra->setLayout(layout);
        QLabel* label = new QLabel;
        label->setText(QString::number(el.second));
        layout->addWidget(label);
        fereastra->setWindowTitle(QString::fromStdString(el.first));
        fereastra->move(x,y);
        fereastra->resize(300,50);
        y+=90;
        ferestre.push_back(fereastra);
    }

    for(const auto& fereastra : ferestre){
        fereastra->show();
    }
}

void GUI::for_select() {
    auto indexes = tableView->selectionModel()->selectedIndexes();
    if(indexes.size() == 5){
        edit_id->setText(tableView->model()->data(indexes[0]).toString());
        edit_nume->setText(tableView->model()->data(indexes[1]).toString());
        edit_tip->setText(tableView->model()->data(indexes[2]).toString());
        edit_pret->setText(tableView->model()->data(indexes[3]).toString());
    }
}
