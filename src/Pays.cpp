#include "Pays.h"

Pays::Pays(const QString &nom, const QString &path)
    :m_nom(nom), m_path(path)
{

}

QString Pays::nom() const
{
    return m_nom;
}

void Pays::setnom(QString arg)
{
    if(arg != m_nom){
        m_nom = arg;
        emit nomChanged(arg);
    }
}

QString Pays::path() const
{
    return m_path;
}

void Pays::setpath(QString arg)
{
    if(arg != m_path){
        m_path = arg;
        emit pathChanged(arg);
    }
}
