//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_MYMODELVIEW_H
#define IRIMIES_VASILE_EMILIAN_MYMODELVIEW_H
#include "QAbstractTableModel"
#include <vector>
#include "QBrush"
#include "../Domain/Student.h"

using std::vector;

class MyModelView :public QAbstractTableModel{
private:
    vector<Student> lista_studenti;
public:

    MyModelView(vector<Student>lista):lista_studenti{lista}{}

    int rowCount(const QModelIndex &parent = QModelIndex()) const{
        return lista_studenti.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        return 4;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const{
        int row = index.row();
        int column = index.column();
        Student student = lista_studenti[row];
        if(role == Qt::DisplayRole){
            switch (column) {
                case 0:
                    return QString::number(student.get_numar_matricol());
                case 1:
                    return QString::fromStdString(student.get_nume());
                case 2:
                    return QString::number(student.get_varsta());
                case 3:
                    return QString::fromStdString(student.get_facultate());
            }
        }
        if(role == Qt::BackgroundRole){
            if(student.get_facultate() == "mate")
                return QBrush(Qt::red);
            if(student.get_facultate() == "info")
                return QBrush(Qt::blue);
            if(student.get_facultate() == "mate-info")
                return QBrush(Qt::magenta);
            if(student.get_facultate() == "ai")
                return QBrush(Qt::green);
        }
        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const{
        if(role == Qt::DisplayRole){
            if(orientation == Qt::Horizontal)
            switch (section) {
                case 0:
                    return QString("NR. MATRICOL");
                case 1:
                    return QString("NUME");
                case 2:
                    return QString("VARSTA");
                case 3:
                    return QString("FACULTATE");
            }
            else return QString::number(section+1);
        }
        return QVariant();
    }

    void set_lista(vector<Student> lista){
        lista_studenti = lista;
        emit layoutChanged();
    }
};

#endif //IRIMIES_VASILE_EMILIAN_MYMODELVIEW_H
