//
// Created by Irimieş Vasile on 5/29/2023.
//

#include <QVBoxLayout>
#include <QFormLayout>
#include "UI_Cos.h"

void UI_Cos::afisare_lista(vector<Film> l) {
    lista->clear();
    for ( auto& film : l ){
        string film_s = std::to_string(film.get_id()) + " " + film.get_titlu() + " " + film.get_gen() + film.get_actor_principal() + " " +
                        std::to_string(film.get_an_aparitie());
        lista->addItem(QString::fromStdString(film_s));
    }
}

void UI_Cos::Design() {
    QWidget* left = new QWidget;
    QWidget* right = new QWidget;
    QHBoxLayout* main_layout = new QHBoxLayout;
    main_window->setLayout(main_layout);
    QVBoxLayout* left_layout = new QVBoxLayout;
    left->setLayout(left_layout);
    QVBoxLayout* right_layout = new QVBoxLayout;
    right->setLayout(right_layout);
    main_layout->addWidget(left);
    main_layout->addWidget(right);

    QWidget* form = new QWidget;
    QFormLayout* form_layout= new QFormLayout;
    form->setLayout(form_layout);
    form_layout->addRow("Titlu", edit_titlu);
    form_layout->addRow("Numar", edit_numarGenerare);
    left_layout->addWidget(form);
    left_layout->addWidget(buton_adauga);
    left_layout->addWidget(buton_genereaza);
    left_layout->addWidget(buton_goleste);

    right_layout->addWidget(lista);

    main_window->move(500,500);
}

void UI_Cos::AssignButtons() {
    QObject::connect(buton_adauga,&QPushButton::clicked, this, &UI_Cos::adauga_cos_ui);
    QObject::connect(buton_genereaza,&QPushButton::clicked, this, &UI_Cos::genereaza_cos_ui);
    QObject::connect(buton_goleste,&QPushButton::clicked, this, &UI_Cos::goleste_cos_ui);
}

