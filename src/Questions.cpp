#include "Questions.h"


Questions::Questions(QObject *parent)
{

}

void Questions::addQuestion(Question *question)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_questions << question;
    endInsertRows();
}

int Questions::rowCount(const QModelIndex &parent) const
{
    return m_questions.count();
}

QVariant Questions::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_questions.count())
        return QVariant();

    Question *question = m_questions[index.row()];
    if(role == IntituleRole){
        return question->intitule();
    }else if (role == ReponseARole) {
        return question->reponseA();
    }else if (role == ReponseBRole) {
        return question->reponseB();
    }else if (role == ReponseCRole) {
        return question->reponseC();
    }else if (role == ReponseDRole) {
        return question->reponseD();
    }

    return QVariant();
}

bool Questions::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() < 0 || index.row() >= m_questions.count())
        return false;

    Question *question = m_questions[index.row()];
    if(role == IntituleRole){
        return false;
    }else if (role == ReponseARole) {
        question->setReponseA(value.toString());
        return true;
    }else if (role == ReponseBRole) {
        question->setReponseB(value.toString());
        return true;
    }else if (role == ReponseCRole) {
        question->setReponseC(value.toString());
        return true;
    }else if (role == ReponseDRole) {
        question->setReponseD(value.toString());
        return true;
    }

    return false;
}

void Questions::chargeAnwsers(const QString &name)
{
    for (int var = 0; var < rowCount(); ++var) {

//        setData(, "Huitre", ReponseARole);
        m_questions[var]->setReponseA("Huitre");
        m_questions[var]->setReponseB("Marseillaise");
        m_questions[var]->setReponseC("Bannane");
        m_questions[var]->setReponseD("Mangue");
        m_questions[var]->setBonneReponse(2);
    }
}

QHash<int, QByteArray> Questions::roleNames() const
{
    QHash<int,QByteArray> roles ;
    roles[IntituleRole] = "intitule";
    roles[ReponseARole] = "reponseA";
    roles[ReponseBRole] = "reponseB";
    roles[ReponseCRole] = "reponseC";
    roles[ReponseDRole] = "reponseD";

    return roles;
}
