#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QHash>

#include "Question.h"

class Questions : public QAbstractListModel
{
    Q_OBJECT
public:
    enum QuestionsRoles {
        IntituleRole = Qt::UserRole + 1,
        ReponseARole ,
        ReponseBRole ,
        ReponseCRole ,
        ReponseDRole
    };

    Questions(QObject * parent = 0);
    void addQuestion(Question * question);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    Q_INVOKABLE void chargeAnwsers(const QString &name);

protected:
    QHash<int,QByteArray> roleNames() const;

private:
    QList<Question *> m_questions;
};

#endif // QUESTIONS_H
