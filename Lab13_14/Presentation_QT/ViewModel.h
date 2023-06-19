//
// Created by Irimieş Vasile on 5/31/2023.
//

#ifndef LAB10_11_VIEWMODEL_H
#define LAB10_11_VIEWMODEL_H
#include <QAbstractTableModel>
#include <QBrush>
#include <QFont>
#include <QString>

class MyTabelModel : public QAbstractTableModel{
private:
    ServiceFilme& service;
public:
    MyTabelModel(QObject* parent, ServiceFilme& service): QAbstractTableModel(parent), service{service}{}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override{
        //return service.len();
        return service.len();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override{
        return 5;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const override{

    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override{
        int row = index.row();
        int column = index.column();
        auto& lista = service.get_all_service();
        if ( role == Qt::DisplayRole ){
            if ( row < service.len()) {
                switch (column) {
                    case 0:
                        return QString::number(lista[row].get_id());
                    case 1:
                        return QString::fromStdString(lista[row].get_titlu());
                    case 2:
                        return QString::fromStdString(lista[row].get_gen());
                    case 3:
                        return QString::number(lista[row].get_an_aparitie());
                    case 4:
                        return QString::fromStdString(lista[row].get_actor_principal());
                }
            }
            return QString("");
        }
        if ( role == Qt::FontRole ){
            QFont font;
            if ( column == 0)
                font.setPixelSize(20);
            font.setBold(row % 2 == 1);
            return font;
        }
        if( role == Qt::BackgroundRole ){
            if ( row % 2 == 0){
                QBrush bg(Qt::darkCyan);
                return bg;
            }
            else
                return QBrush(Qt::magenta);
        }
        return QVariant();
    }

//    bool setData(const QModelIndex& index, const QVariant& value, int role) override{
//        if ( role == Qt::EditRole){
//            int row = index.row();
//            int column = index.row();
//            QModelIndex topleft = createIndex(row, column);
//            emit dataChanged(topleft, topleft);
//        }
//        return true;
//    }

//    void update() override{
////        QModelIndex topLeft = createIndex(0,0);
////        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
////        emit dataChanged(topLeft,bottomRight);
//        emit layoutChanged();
//    }

};

#endif //LAB10_11_VIEWMODEL_H
