#include "Countries.h"

Countries::Countries(QObject *parent)
{

}

void Countries::addPays(Pays *pays)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_countries << pays;

    endInsertRows();
}

int Countries::rowCount(const QModelIndex &) const
{
    return m_countries.count();
}

QVariant Countries::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_countries.count())
        return QVariant();

    Pays * pays = m_countries[index.row()];
    if(role == nomRole) {
        return pays->nom();
    }
    if(role == pathRole) {
        return pays->path();
    }

    return QVariant();
}

bool Countries::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() < 0 || index.row() >= m_countries.count())
        return false;

    if(data(index, role) == value){
        return true;
    }

    Pays *pays = m_countries[index.row()];
    if(role == pathRole) {
        return false;
    }
    if(role == nomRole) {
        pays->setnom(value.toString());
    }

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft = index.sibling(0,0);
    QModelIndex bottomRight = index.sibling(m_countries.count()-1, 0);

    emit dataChanged(topLeft, bottomRight, roles);

    return true;
}

QHash<int, QByteArray> Countries::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[nomRole] = "nom";
    roles[pathRole] = "path";
    return roles;
}
