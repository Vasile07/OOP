//
// Created by Irimieş Vasile on 6/15/2023.
//

#include "GUI.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QFormLayout"
#include "QHeaderView"
#include "QMessageBox"
#include "../Erors/Erori.h"

void GUI::Design() {
    QHBoxLayout* this_layout = new QHBoxLayout;
    this->setLayout(this_layout);

    QWidget* left = new QWidget;
    QVBoxLayout* layout_left = new QVBoxLayout;
    left->setLayout(layout_left);

    QWidget* form = new QWidget;
    QFormLayout* layout_form = new QFormLayout;
    form->setLayout(layout_form);

    layout_form->addRow("Id",edit_id);
    layout_form->addRow("Titlu",edit_titlu);
    layout_form->addRow("Artist",edit_artist);
    layout_form->addRow("Gen",edit_gen);

    layout_form->addRow(buton_adauga);
    layout_form->addRow(buton_sterge);

    layout_left->addWidget(form);

    QWidget* right = new QWidget;
    QVBoxLayout* layout_right = new QVBoxLayout;
    right->setLayout(layout_right);

    QStringList header;
    header << "ID" << "TITLU" << "ARTIST" << "GEN";
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    layout_right->addWidget(table);
    layout_right->addWidget(tableView);

    this_layout->addWidget(left);
    this_layout->addWidget(right);
    this->move(0,0);
    this->resize(1000,800);

}

void GUI::AssignTask() {
    QObject::connect(buton_adauga,&QPushButton::clicked,this,&GUI::adauga_gui);
    QObject::connect(buton_sterge,&QPushButton::clicked,this,&GUI::sterge_gui);
    QObject::connect(table,&QTableWidget::itemSelectionChanged,this,&GUI::populare_gui);
}

void GUI::adauga_gui() {
    int id = edit_id->text().toInt();
    string titlu = edit_titlu->text().toStdString();
    string artist = edit_artist->text().toStdString();
    string gen = edit_gen->text().toStdString();

    try{
        lista_melodii.adauga_melodie_service(id,titlu,artist,gen);
        afisare_gui();
        clear_contents();
    }catch (RepoError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }catch (ValidationError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }
}

void GUI::sterge_gui() {
    int id = edit_id->text().toInt();
    try{
        lista_melodii.sterge_melodie_dupa_id_service(id);
        afisare_gui();
        clear_contents();
    }catch (RepoError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }catch (ValidationError& eroare){
        QMessageBox::warning(this,"Warning",QString::fromStdString(eroare.get_msg()));
    }
}

void GUI::afisare_gui() {
    table->clearContents();
    table->setRowCount(lista_melodii.len());
    table->setColumnCount(4);
    int row = 0;
    for (const auto &melodie:lista_melodii.get_all()) {
        table->setItem(row,0,new QTableWidgetItem(QString::number(melodie.get_id())));
        table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(melodie.get_titlu())));
        table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(melodie.get_artist())));
        table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(melodie.get_gen())));
        row++;
    }
    repaint();
}

void GUI::clear_contents() {
    edit_id->clear();
    edit_titlu->clear();
    edit_artist->clear();
    edit_gen->clear();
}

void GUI::populare_gui() {
    auto items = table->selectedItems();
    if(items.size()==4){
        edit_id->setText(items[0]->text());
        edit_titlu->setText(items[1]->text());
        edit_artist->setText(items[2]->text());
        edit_gen->setText(items[3]->text());
    }
}

