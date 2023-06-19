//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_MYABSTRACTMODE_H
#define MELODII_1_MYABSTRACTMODE_H
#include <QAbstractTableModel>
#include "../Domain/Melodie.h"
#include <vector>

using std::vector;

class MyAbstractModel : public QAbstractTableModel{
private:
    vector<Melodie> lista;
public:
    MyAbstractModel(vector<Melodie>lista):lista{lista}, QAbstractTableModel(){}
    int rowCount(const QModelIndex& parent = QModelIndex()) const override{
        return lista.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex())const override{
        return 4;
    }
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override{
        int row = index.row();
        int column = index.column();
        auto melodie = lista[row];
        if(role == Qt::DisplayRole){
            switch (column) {
                case 0: {
                    return QString::number(melodie.get_id());
                }
                case 1: {
                    return QString::fromStdString(melodie.get_titlu());
                }
                case 2: {
                    return QString::fromStdString(melodie.get_artist());
                }
                case 3: {
                    return QString::number(melodie.get_rank());
                }
            }
        }
        return QVariant();
    }

    void setList(vector<Melodie> lista_noua){
        lista = lista_noua;
        emit layoutChanged();
    }
};

#endif //MELODII_1_MYABSTRACTMODE_H
