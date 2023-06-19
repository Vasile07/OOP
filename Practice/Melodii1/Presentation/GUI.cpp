//
// Created by Irimieş Vasile on 6/13/2023.
//

#include <QMessageBox>
#include "GUI.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QFormLayout"
#include "QStringList"
#include "QHeaderView"
#include "MyAbstractMode.h"

void GUI::AssignTask() {
    QObject::connect(buton_adauga,&QPushButton::clicked,this,&GUI::adauga_ui);
    QObject::connect(buton_modifica,&QPushButton::clicked,this,&GUI::modifica_ui);
    QObject::connect(buton_sterge,&QPushButton::clicked,this,&GUI::sterge_ui);
    QObject::connect(tabel,&QTableWidget::itemSelectionChanged,this,&GUI::incarca_date_ui);
}

void GUI::Design() {
    QHBoxLayout* layout = new QHBoxLayout;
    this->setLayout(layout);

    QWidget* left = new QWidget;
    QVBoxLayout* layout_left = new QVBoxLayout;
    left->setLayout(layout_left);
    layout->addWidget(left);

    QWidget* form = new QWidget;
    QFormLayout* layout_form = new QFormLayout;
    form->setLayout(layout_form);

    layout_form->addRow("ID",Edit_id);
    layout_form->addRow("Titlu",Edit_titlu);
    layout_form->addRow("Artist",Edit_artist);
    layout_form->addRow("Rank",Edit_rank);

    Edit_rank->setMinimum(0);
    Edit_rank->setMaximum(10);
    Edit_rank->setOrientation(Qt::Horizontal);

    layout_left->addWidget(form);
    layout_form->addWidget(buton_adauga);
    layout_form->addWidget(buton_modifica);
    layout_form->addWidget(buton_sterge);

    QWidget* right = new QWidget;
    QVBoxLayout* layout_right = new QVBoxLayout;
    right->setLayout(layout_right);
    layout->addWidget(right);


    QStringList header;
    header << "ID" << "Titlu" << "Artist" << "Rank";
    tabel->setHorizontalHeaderLabels(header);
    tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    layout_right->addWidget(tabel);

    tableView->setModel(model);
    layout_right->addWidget(tableView);

}

void GUI::adauga_ui() {
    int id = Edit_id->text().toInt();
    string titlu = Edit_titlu->text().toStdString();
    string artist = Edit_artist->text().toStdString();
    int rank = Edit_rank->value();
    try{
        service.adauga_melodie_service(id, titlu, artist,rank);
        afiseaza_ui(service.get_all());
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_msg()));
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_msg()));
    }
}

void GUI::sterge_ui() {
    int id = Edit_id->text().toInt();
    try{
        service.sterge_melodie_dupa_id_service(id);
        afiseaza_ui(service.get_all());
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_msg()));
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_msg()));
    }
}

void GUI::modifica_ui() {
    int id = Edit_id->text().toInt();
    string titlu = Edit_titlu->text().toStdString();
    string artist = Edit_artist->text().toStdString();
    int rank = Edit_rank->value();
    try{
        service.modifica_melodie_service(id, titlu, artist,rank);
        afiseaza_ui(service.get_all());
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_msg()));
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_msg()));
    }
}

void GUI::incarca_date_ui() {
    auto selected_items = tabel->selectedItems();
    if(selected_items.size() == 4){
        Edit_id->setText(selected_items[0]->text());
        Edit_titlu->setText(selected_items[1]->text());
        Edit_artist->setText(selected_items[2]->text());
        Edit_rank->setValue(selected_items[3]->text().toInt());
    }
}

void GUI::afiseaza_ui(vector<Melodie> lista) {
    repaint();
    int nrLinie=0;
    tabel->clearContents();
    tabel->setRowCount(lista.size());
    tabel->setColumnCount(4);
    for(const auto& melodie : lista){
        tabel->setItem(nrLinie,0,new QTableWidgetItem{QString::number(melodie.get_id())});
        tabel->setItem(nrLinie,1,new QTableWidgetItem{QString::fromStdString(melodie.get_titlu())});
        tabel->setItem(nrLinie,2,new QTableWidgetItem{QString::fromStdString(melodie.get_artist())});
        tabel->setItem(nrLinie,3,new QTableWidgetItem{QString::number(melodie.get_rank())});
        nrLinie++;
    }
    model->setList(service.get_all());
}
