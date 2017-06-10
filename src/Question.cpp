#include "Question.h"

Question::Question(const QString &intitule)
    :m_intitule(intitule)
{

}

QString Question::intitule() const
{
    return m_intitule;
}

QString Question::reponseA() const
{
    return m_reponseA;
}

QString Question::reponseB() const
{
    return m_reponseB;
}

QString Question::reponseC() const
{
    return m_reponseC;
}

QString Question::reponseD() const
{
    return m_reponseD;
}

int Question::bonneReponse() const
{
    return m_bonneReponse;
}


void Question::setReponseA(QString arg)
{
    if(arg != m_reponseA){
        m_reponseA = arg;
        emit reponseAChanged(arg);
    }
}

void Question::setReponseB(QString arg)
{
    if(arg != m_reponseB){
        m_reponseB = arg;
        emit reponseBChanged(arg);
    }
}

void Question::setReponseC(QString arg)
{
    if(arg != m_reponseC){
        m_reponseC = arg;
        emit reponseCChanged(arg);
    }
}

void Question::setReponseD(QString arg)
{
    if(arg != m_reponseD){
        m_reponseD = arg;
        emit reponseDChanged(arg);
    }
}

void Question::setBonneReponse(int arg)
{
    if(arg != m_bonneReponse){
        m_bonneReponse = arg;
        emit bonneReponseChanged(arg);
    }
}

void Question::setIntitule(QString arg)
{
    if(arg != m_intitule){
        m_intitule = arg;
    }
}
