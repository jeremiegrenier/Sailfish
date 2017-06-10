#ifndef PAYS_H
#define PAYS_H

#include <QObject>
#include <QString>

#include "Questions.h"

class Pays : public QObject
{
    Q_OBJECT
public:
    Pays(const QString &nom = "defaultName", const QString &path = "../resources/picture/notFound.png");
    Q_PROPERTY(QString nom READ nom WRITE setnom NOTIFY nomChanged)
    Q_PROPERTY(QString path READ path WRITE setpath NOTIFY pathChanged)

    QString nom() const;
    QString path() const;

signals:
    void nomChanged(QString arg);
    void pathChanged(QString arg);

public slots:
    void setnom(QString arg);
    void setpath(QString arg);

private:
    QString m_nom;
    QString m_path;
};

#endif // PAYS_H
