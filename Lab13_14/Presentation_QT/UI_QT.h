//
// Created by Irimieş Vasile on 5/7/2023.
//

#ifndef LAB10_11_UI_QT_H
#define LAB10_11_UI_QT_H
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QTextLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QRadioButton>
#include <QSlider>
#include <QListWidget>
#include <QComboBox>
#include "../Bussines/ServiceFilme.h"
#include "../Utilitar/Observer.h"



class UI_QT : public QWidget, public Observer{
private:
    QWidget* main = new QWidget;
    ServiceFilme& lista_filme;
    QComboBox* comboBox = new QComboBox;
    QLabel* LabelId = new QLabel{"Id"};
    QLineEdit* EditId = new QLineEdit;
    QLabel* LabelTitlu = new QLabel{"Titlu"};
    QLineEdit* EditTitlu = new QLineEdit;
    QLabel* LabelGen = new QLabel{"Gen"};
    QLineEdit* EditGen = new QLineEdit;
    QLabel* LabelActor= new QLabel{"Actor principal"};
    QLineEdit* EditActor = new QLineEdit;
    QLabel* LabelAn= new QLabel{"Anul aparitiei"};
    QLineEdit* EditAn = new QLineEdit;

    QPushButton* add_button = new QPushButton("Adauga Cartea");
    QPushButton* delete_button = new QPushButton("Sterge Cartea");
    QPushButton* modify_button = new QPushButton("Modifica Cartea");
    QPushButton* search_button = new QPushButton("Cauta");
    QPushButton* filter_button_by_titlu = new QPushButton("Filtreaza dupa titlu");
    QPushButton* filter_button_by_an = new QPushButton("Filtreaza dupa an");
    QPushButton* sort_button = new QPushButton("Sorteaza");
    QPushButton* undo_button = new QPushButton("Undo");
    QPushButton* cos_crud_button = new QPushButton("Cos CRUD");
    QPushButton* cos_necrud_button = new QPushButton("Cos Read Only");

    QSlider* slider = new QSlider;

    QListWidget* lista = new QListWidget;



    ////Meniu Cos
    QWidget* meniu_cos = new QWidget;
    QLabel* LabelTitlu_cos = new QLabel{"Titlu"};
    QLineEdit* EditTitlu_cos = new QLineEdit;
    QLabel* LabelNumar_cos = new QLabel{"Numar filme"};
    QLineEdit* EditNumar_cos = new QLineEdit;
    QLabel* LabelFileName_cos = new QLabel{"Fisier"};
    QLineEdit* EditFileName_cos = new QLineEdit;

    QPushButton* add_cos_button = new QPushButton("Adauga");
    QPushButton* goleste_cos_button = new QPushButton("Goleste");
    QPushButton* random_cos_button = new QPushButton("Generaza");
    QPushButton* export_cos_button = new QPushButton("Export");

    QWidget* right = new QWidget;
    QVBoxLayout* layout_right = new QVBoxLayout;

    vector <QPushButton*> butoane_de_sters;
    QWidget* mapa = new QWidget;
    QVBoxLayout* layout_map = new QVBoxLayout;

    QTableWidget* tabel_filme;
    QTableWidget* tabel_filme_cos;


    void Settup_Window();
    void Attach_Function_to_Buttons();
    void clear_content();

    void adauga_ui();
    void sterge_ui();
    void modifica_ui();
    void cauta_ui();
    void afiseaza_lista_ui(vector<Film> lista);
    void filtrare_dupa_titlu();
    void filtrare_dupa_an();
    void filtrare_ui(vector<Film> lista);
    void sort_ui();
    void undo_ui();
    void ruleaza_cos_crud_ui();
    void ruleaza_cos_necrud_ui();
    void afiseaza_cos_ui();
    void adauga_cos_ui();
    void genereaza_cos_ui();
    void goleste_cos_ui();
    void export_cos_ui();
    void fil();
    void show_map();



    void update() override{
        afiseaza_lista_ui(lista_filme.get_all_service());
    }
public:
    explicit UI_QT(ServiceFilme& service): lista_filme{service}{
        Settup_Window();
        Attach_Function_to_Buttons();
        lista_filme.adauga_observer(this);
    }

    void ruleaza_consola();
};


#endif //LAB10_11_UI_QT_H
