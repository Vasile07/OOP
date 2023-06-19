//
// Created by Irimieş Vasile on 5/7/2023.
//

#include <QFormLayout>
#include <QMessageBox>
#include "UI_QT.h"
#include "../Errors/Erori.h"
#include "UI_Cos.h"
#include "UI_Cos_ReadOnly.h"
#include "ViewModel.h"
#include <map>
#include <QComboBox>
using std::map;



void UI_QT::ruleaza_consola() {

    main->show();
    show_map();
    afiseaza_lista_ui(lista_filme.get_all_service());

}

void UI_QT::Settup_Window() {
    QHBoxLayout* layout_main = new QHBoxLayout;
    main->setLayout(layout_main);

    QWidget* left = new QWidget;
    QVBoxLayout* layout_left = new QVBoxLayout;
    left->setLayout(layout_left);

    QWidget* form = new QWidget;
    QFormLayout* layout_form = new QFormLayout;
    form->setLayout(layout_form);

    layout_form->addRow(LabelId,EditId);
    layout_form->addRow(LabelTitlu,EditTitlu);
    layout_form->addRow(LabelGen,EditGen);
    layout_form->addRow(LabelActor,EditActor);
    layout_form->addRow(LabelAn,EditAn);

    layout_left->addWidget(form);

    layout_left->addWidget(add_button);
    layout_left->addWidget(modify_button);
    layout_left->addWidget(delete_button);
    layout_left->addWidget(search_button);
    layout_left->addWidget(filter_button_by_titlu);
    layout_left->addWidget(filter_button_by_an);
    layout_left->addWidget(sort_button);
    layout_left->addWidget(undo_button);
    layout_left->addWidget(cos_crud_button);
    layout_left->addWidget(cos_necrud_button);
    layout_left->addWidget(slider);
    layout_left->addWidget(comboBox);
    comboBox->addItem("ex1");
    comboBox->addItem("ex2");
    slider->setMaximum(1000);
    slider->setOrientation(Qt::Horizontal);





    right->setLayout(layout_right);
    int Lines = 10 , Columns = 5;
    tabel_filme = new QTableWidget{Lines, Columns};

    QStringList HeaderTabel;
    HeaderTabel << "Id" << "Titlu" << "Gen" << "Actor" << "An";
    tabel_filme->setHorizontalHeaderLabels(HeaderTabel);
    tabel_filme->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    MyTabelModel* model = new MyTabelModel(tabel_filme, lista_filme);
    QTableView* TabelView = new QTableView();
    TabelView->setModel(model);
    //TabelView->show();

    //layout_right->addWidget(tabel_filme);
    layout_right->addWidget(TabelView);
    layout_right->addWidget(mapa);

    layout_main->addWidget(left);
    layout_main->addWidget(right);
    layout_main->addWidget(lista);
    layout_main->addWidget(mapa);
    mapa->setLayout(layout_map);
    main->resize(left->width() + right->width(), left->height() + right->height());


    /// MENIU COS
    QHBoxLayout* layout_cos = new QHBoxLayout;
    meniu_cos->setLayout(layout_cos);

    QWidget* left_cos = new QWidget;
    QVBoxLayout* left_layout_cos = new QVBoxLayout;
    left_cos->setLayout(left_layout_cos);
    QWidget* right_cos = new QWidget;
    QVBoxLayout* right_layout_cos = new QVBoxLayout;
    right_cos->setLayout(right_layout_cos);
    layout_cos->addWidget(left_cos);
    layout_cos->addWidget(right_cos);

    QWidget* form_cos = new QWidget;
    left_layout_cos->addWidget(form_cos);

    QFormLayout* form_layout_cos = new QFormLayout;
    form_cos->setLayout(form_layout_cos);

    form_layout_cos->addRow(LabelTitlu_cos,EditTitlu_cos);
    form_layout_cos->addRow(LabelNumar_cos,EditNumar_cos);
    form_layout_cos->addRow(LabelFileName_cos,EditFileName_cos);

    left_layout_cos->addWidget(add_cos_button);
    left_layout_cos->addWidget(goleste_cos_button);
    left_layout_cos->addWidget(random_cos_button);
    left_layout_cos->addWidget(export_cos_button);

    tabel_filme_cos = new QTableWidget{2,5};
    QStringList Header;
    Header << "Id" << "Titlu" << "Gen" << "Actor" << "An";
    tabel_filme_cos->setHorizontalHeaderLabels(Header);
    tabel_filme_cos->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    right_layout_cos->addWidget(tabel_filme_cos);

}

void UI_QT::Attach_Function_to_Buttons() {
    QObject::connect(add_button,&QPushButton::clicked,this,&UI_QT::adauga_ui);
    QObject::connect(modify_button,&QPushButton::clicked,this,&UI_QT::modifica_ui);
    QObject::connect(delete_button,&QPushButton::clicked,this,&UI_QT::sterge_ui);
    QObject::connect(search_button,&QPushButton::clicked,this,&UI_QT::cauta_ui);
    QObject::connect(filter_button_by_titlu,&QPushButton::clicked,this,&UI_QT::filtrare_dupa_titlu);
    QObject::connect(filter_button_by_an,&QPushButton::clicked,this,&UI_QT::filtrare_dupa_an);
    QObject::connect(sort_button,&QPushButton::clicked,this,&UI_QT::sort_ui);
    QObject::connect(undo_button,&QPushButton::clicked,this,&UI_QT::undo_ui);
    QObject::connect(cos_crud_button,&QPushButton::clicked,this,&UI_QT::ruleaza_cos_crud_ui);
    QObject::connect(cos_necrud_button,&QPushButton::clicked,this,&UI_QT::ruleaza_cos_necrud_ui);
    QObject::connect(add_cos_button,&QPushButton::clicked,this,&UI_QT::adauga_cos_ui);
    QObject::connect(export_cos_button,&QPushButton::clicked,this,&UI_QT::export_cos_ui);
    QObject::connect(goleste_cos_button,&QPushButton::clicked,this,&UI_QT::goleste_cos_ui);
    QObject::connect(random_cos_button,&QPushButton::clicked,this,&UI_QT::genereaza_cos_ui);
    QObject::connect(slider,&QSlider::sliderReleased,this,&UI_QT::fil);


    QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){ clear_content();});

}

void UI_QT::clear_content() {
    show_map();
    EditId->clear();
    EditTitlu->clear();
    EditGen->clear();
    EditActor->clear();
    EditAn->clear();
    EditTitlu_cos->clear();
    EditNumar_cos->clear();
    EditFileName_cos->clear();
}

void UI_QT::adauga_ui() {
    int id = EditId->text().toInt();
    string titlu = EditTitlu->text().toStdString();
    string gen = EditGen->text().toStdString();
    string actor = EditActor->text().toStdString();
    int an  = EditAn->text().toInt();
    try{
        lista_filme.adauga_film_service(id, titlu, gen, an, actor);
        clear_content();
        afiseaza_lista_ui(lista_filme.get_all_service());
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_message()));
    }catch ( ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_message()));
    }
}

void UI_QT::sterge_ui() {
    int id = EditId->text().toInt();
    try{
        lista_filme.sterge_dupa_id_service(id);
        clear_content();
        afiseaza_lista_ui(lista_filme.get_all_service());
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_message()));
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_message()));
    }
}

void UI_QT::modifica_ui() {
    int id = EditId->text().toInt();
    string titlu_nou = EditTitlu->text().toStdString();
    string gen_nou = EditGen->text().toStdString();
    string actor_nou = EditActor->text().toStdString();
    int an_nou  = EditAn->text().toInt();
    try{
        lista_filme.modifica_film_service(id, titlu_nou, gen_nou, an_nou, actor_nou);
        clear_content();
        afiseaza_lista_ui(lista_filme.get_all_service());

    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_message()));
    }catch ( ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_message()));
    }
}

void UI_QT::cauta_ui() {
    int id = EditId->text().toInt();
    try{
        auto film = lista_filme.cauta_film_dupa_id_service(id);
        clear_content();
        string string_film;
        string_film += "ID      " + std::to_string(film.get_id()) + '\n';
        string_film += "Titlu   " + film.get_titlu() + '\n';
        string_film += "Gen     " + film.get_gen() + '\n';
        string_film += "Actor   " + film.get_actor_principal() + '\n';
        string_film += "An      " + std::to_string(film.get_an_aparitie()) + '\n';
        QMessageBox::information(this,"Cartea Cautata",QString::fromStdString(string_film));
    }catch (RepoError& re){
        QMessageBox::warning(this,"Warning",QString::fromStdString(re.get_message()));
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_message()));
    }
}

void UI_QT::afiseaza_lista_ui(vector<Film> lista_f) {
    tabel_filme->clearContents();
    tabel_filme->setRowCount(lista_f.size());
    int linie = 0;
    for ( auto& film : lista_f){
        tabel_filme->setItem(linie,0,new QTableWidgetItem(QString::number(film.get_id())));
        tabel_filme->setItem(linie,1,new QTableWidgetItem(QString::fromStdString(film.get_titlu())));
        tabel_filme->setItem(linie,2,new QTableWidgetItem(QString::fromStdString(film.get_gen())));
        tabel_filme->setItem(linie,3,new QTableWidgetItem(QString::fromStdString(film.get_actor_principal())));
        tabel_filme->setItem(linie,4,new QTableWidgetItem(QString::number(film.get_an_aparitie())));
        linie++;
    }

    lista->clear();
    for ( auto& film : lista_f){
        string film_s = std::to_string(film.get_id()) + " " + film.get_titlu() + " " + film.get_gen() + film.get_actor_principal() + " " +
                std::to_string(film.get_an_aparitie());
        lista->addItem(QString::fromStdString(film_s));
    }
}

void UI_QT::filtrare_ui(vector<Film> lista_f) {
    QWidget* pop_up_filtru = new QWidget;
    QTableWidget* tabel_filtrat = new QTableWidget{(int)lista_f.size(),5};
    QVBoxLayout* layout_pop_up_filtru = new QVBoxLayout;
    pop_up_filtru->setLayout(layout_pop_up_filtru);
    layout_pop_up_filtru->addWidget(tabel_filtrat);

    QStringList Header;
    Header << "Id" << "Titlu" << "Gen" << "Actor" << "An";
    tabel_filtrat->setHorizontalHeaderLabels(Header);
    tabel_filtrat->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    pop_up_filtru->resize(tabel_filtrat->width(),tabel_filtrat->height());


    int Linie = 0;
    for (auto& film : lista_f ){
        tabel_filtrat->setItem(Linie,0,new QTableWidgetItem(QString::number(film.get_id())));
        tabel_filtrat->setItem(Linie,1,new QTableWidgetItem(QString::fromStdString(film.get_titlu())));
        tabel_filtrat->setItem(Linie,2,new QTableWidgetItem(QString::fromStdString(film.get_gen())));
        tabel_filtrat->setItem(Linie,3,new QTableWidgetItem(QString::fromStdString(film.get_actor_principal())));
        tabel_filtrat->setItem(Linie,4,new QTableWidgetItem(QString::number(film.get_an_aparitie())));
        Linie++;
    }

    pop_up_filtru->show();
}

void UI_QT::sort_ui() {
    QWidget* sort_pop_up = new QWidget;
    QVBoxLayout* layout_sort_pop_up = new QVBoxLayout;
    sort_pop_up->setLayout(layout_sort_pop_up);

    QPushButton* sorteaza = new QPushButton("Sorteaza");

    QRadioButton* by_titlu = new QRadioButton("By Titlu");
    QRadioButton* by_gen = new QRadioButton("By Gen");
    QRadioButton* by_actor = new QRadioButton("By Actor");
    QRadioButton* by_an = new QRadioButton("By An");
    QWidget* selectii = new QWidget;
    QHBoxLayout* sel = new QHBoxLayout;
    selectii->setLayout(sel);
    sel->addWidget(by_titlu);
    sel->addWidget(by_gen);
    sel->addWidget(by_actor);
    sel->addWidget(by_an);

    layout_sort_pop_up->addWidget(selectii);
    layout_sort_pop_up->addWidget(sorteaza);

    sort_pop_up->show();

    QObject::connect(sorteaza,&QPushButton::clicked,[=](){
       if ( by_titlu->isChecked() )
           lista_filme.sortare("titlu");
       if ( by_gen->isChecked() )
           lista_filme.sortare("gen");
       if ( by_actor->isChecked() )
           lista_filme.sortare("actor_principal");
       if ( by_an->isChecked() )
           lista_filme.sortare("an_aparitie");
        afiseaza_lista_ui(lista_filme.get_all_service());
        sort_pop_up->close();
    });

}

void UI_QT::filtrare_dupa_titlu() {
    string titlu = EditTitlu->text().toStdString();
    clear_content();
    filtrare_ui(lista_filme.filtrare_dupa_titlu(titlu));
}

void UI_QT::filtrare_dupa_an() {
    int an = EditAn->text().toInt();
    clear_content();
    filtrare_ui(lista_filme.filtrare_dupa_an(an));
}

void UI_QT::undo_ui() {
    try{
        lista_filme.undo();
        afiseaza_lista_ui(lista_filme.get_all_service());
        clear_content();
    }catch (ValidationError& ve){
        QMessageBox::warning(this,"Warning",QString::fromStdString(ve.get_message()));
    }
}

void UI_QT::ruleaza_cos_crud_ui() {
    UI_Cos* cos = new UI_Cos{lista_filme};
    cos->ruleaza_ui();
}

void UI_QT::ruleaza_cos_necrud_ui() {
    UI_Cos_ReadOnly* cos = new UI_Cos_ReadOnly{lista_filme};
    cos->show();
}


void UI_QT::adauga_cos_ui() {
    string titlu = EditTitlu_cos->text().toStdString();
    lista_filme.adauga_cos_service(titlu);
    clear_content();
    afiseaza_cos_ui();
}

void UI_QT::genereaza_cos_ui() {
    int numar = EditNumar_cos->text().toInt();
    lista_filme.genereaza_cos_service(numar);
    clear_content();
    afiseaza_cos_ui();
}

void UI_QT::goleste_cos_ui() {
    lista_filme.goleste_cos_service();
    clear_content();
    afiseaza_cos_ui();
}

void UI_QT::export_cos_ui() {
    string fisier = EditFileName_cos->text().toStdString();
    lista_filme.export_cos_service(fisier);
    clear_content();
}

void UI_QT::afiseaza_cos_ui() {
    tabel_filme_cos->clearContents();
    tabel_filme_cos->setRowCount(lista_filme.size_cos());

    int Linie = 0;
    for ( auto& film : lista_filme.get_cos() ){
        QTableWidgetItem* id = new  QTableWidgetItem(QString::number(film.get_id()));
        //id->setTextColor(Qt::red);
        tabel_filme_cos->setItem(Linie, 0, id);
        tabel_filme_cos->setItem(Linie, 1, new QTableWidgetItem(QString::fromStdString(film.get_titlu())));
        tabel_filme_cos->setItem(Linie, 2, new QTableWidgetItem(QString::fromStdString(film.get_gen())));
        tabel_filme_cos->setItem(Linie, 3, new QTableWidgetItem(QString::fromStdString(film.get_actor_principal())));
        tabel_filme_cos->setItem(Linie, 4, new QTableWidgetItem(QString::number(film.get_an_aparitie())));
        Linie++;
    }
}

void UI_QT::fil() {
    string ana = "Ana are " + std::to_string(slider->value()) + " mere";
    QMessageBox::warning(this,"Warning",QString::fromStdString(ana));
}

void UI_QT::show_map(){

    for ( auto& buton : butoane_de_sters)
        delete buton;

    butoane_de_sters.clear();

    auto dictionar = lista_filme.get_all_filme_dupa_actor();
    for (auto pereche : dictionar){
        auto actor = pereche.first;
        auto filme = pereche.second;
        QPushButton* buton = new QPushButton(QString::fromStdString(actor));
        butoane_de_sters.push_back(buton);
        QObject::connect(buton, &QPushButton::clicked,[this, filme](){
            QMessageBox::information(this, "Numar",QString::number(filme.size()));
        });
        layout_map->addWidget(buton);
    }
}
