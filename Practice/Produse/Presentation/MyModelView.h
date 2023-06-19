//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_MYMODELVIEW_H
#define PRODUSE_BUN_MYMODELVIEW_H
#include "QAbstractTableModel"
#include "QBrush"
#include "../Domain/Produs.h"
#include <vector>
using std::vector;
class MyModelView : public QAbstractTableModel{
private:
    vector<Produs> lista;
    int pret_filtrare = 0;

    int numar_vocale(string nume)const{
        int cont = 0;
        for(const auto& litera : nume){
            if(strchr("aeiouAEIOU",litera))
                cont++;
        }
        return cont;
    }
public:
    MyModelView(){}
    void set_lista(vector<Produs> new_list){
        lista = new_list;
        emit layoutChanged();
    }

    void set_pret(int new_pret){
        pret_filtrare = new_pret;
        emit layoutChanged();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        return (int)lista.size();
    };
    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        return 5;
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const {
        int row = index.row();
        int column = index.column();
        Produs produs = lista[row];
        if(role == Qt::DisplayRole){
            switch (column) {
                case 0:
                    return QString::number(produs.get_id());
                case 1:
                    return QString::fromStdString(produs.get_nume());
                case 2:
                    return QString::fromStdString(produs.get_tip());
                case 3:
                    return QString::number(produs.get_pret());
                case 4:
                    return QString::number(numar_vocale(produs.get_nume()));
            }
        }
        if(role == Qt::ForegroundRole){
            if(produs.get_pret() <= pret_filtrare)
                return QBrush(Qt::magenta);
        }
        return QVariant();
    };
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const{
        if(role == Qt::DisplayRole){
            if(orientation == Qt::Horizontal){
                switch (section) {
                    case 0:
                        return QString{"ID"};
                    case 1:
                        return QString{"NUME"};
                    case 2:
                        return QString{"TIP"};
                    case 3:
                        return QString{"PRET"};
                    case 4:
                        return QString{"VOCALE"};
                }
            }else{
                return QString::number(section+1);
            }
        }
        return QVariant();
    };

};


#endif //PRODUSE_BUN_MYMODELVIEW_H
