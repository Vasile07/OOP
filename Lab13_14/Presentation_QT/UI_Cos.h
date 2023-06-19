//
// Created by Irimieş Vasile on 5/29/2023.
//

#ifndef LAB10_11_UI_COS_H
#define LAB10_11_UI_COS_H
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include "../Utilitar/Observer.h"
#include "../Bussines/ServiceFilme.h"

class UI_Cos : public QWidget, public Observer{
private:
    void update() override{
        afisare_lista(lista_filme.get_cos());
    }
    QWidget* main_window = new QWidget;
    ServiceFilme& lista_filme;
    QListWidget* lista = new QListWidget;

    QLineEdit* edit_titlu = new QLineEdit;
    QLineEdit* edit_numarGenerare = new QLineEdit;
    QPushButton* buton_adauga = new QPushButton("Adauga");
    QPushButton* buton_genereaza = new QPushButton("Genereaza");
    QPushButton* buton_goleste = new QPushButton;


    void afisare_lista(vector<Film> l);
    void Design();
    void AssignButtons();

    void adauga_cos_ui(){
        string titlu = edit_titlu->text().toStdString();
        lista_filme.adauga_cos_service(titlu);
        afisare_lista(lista_filme.get_cos());
    }
    void genereaza_cos_ui(){
        int numar = edit_numarGenerare->text().toInt();
        lista_filme.genereaza_cos_service(numar);
        afisare_lista(lista_filme.get_cos());
    }
    void goleste_cos_ui(){
        lista_filme.goleste_cos_service();
        afisare_lista(lista_filme.get_cos());
    }

public:
    UI_Cos(ServiceFilme& service): lista_filme{service}{
        lista_filme.adauga_observer(this);
        Design();
        AssignButtons();
    }
    void ruleaza_ui(){
        main_window->show();
        afisare_lista(lista_filme.get_cos());
    }
};


#endif //LAB10_11_UI_COS_H
