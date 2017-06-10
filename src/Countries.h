#ifndef COUNTRIES_H
#define COUNTRIES_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QHash>

#include "Pays.h"

class Countries : public QAbstractListModel
{
    Q_OBJECT

public:
    enum CountriesRoles {
        nomRole = Qt::UserRole + 1,
        pathRole
    };

    Countries(QObject *parent = 0);


    void addPays(Pays *pays);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

protected:
    QHash<int,QByteArray> roleNames() const;

private:
    QList<Pays*> m_countries;
};

#endif // COUNTRIES_H
