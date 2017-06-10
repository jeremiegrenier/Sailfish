#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    Question(const QString &intitule = "");
    Q_PROPERTY(QString intitule READ intitule WRITE setIntitule)
    Q_PROPERTY(QString reponseA READ reponseA WRITE setReponseA NOTIFY reponseAChanged)
    Q_PROPERTY(QString reponseB READ reponseB WRITE setReponseB NOTIFY reponseBChanged)
    Q_PROPERTY(QString reponseC READ reponseC WRITE setReponseC NOTIFY reponseCChanged)
    Q_PROPERTY(QString reponseD READ reponseD WRITE setReponseD NOTIFY reponseDChanged)
    Q_PROPERTY(int bonneReponse READ bonneReponse WRITE setBonneReponse NOTIFY bonneReponseChanged)

    QString intitule() const;
    QString reponseA() const;
    QString reponseB() const;
    QString reponseC() const;
    QString reponseD() const;
    int bonneReponse() const;

signals:
    void reponseAChanged(QString arg);
    void reponseBChanged(QString arg);
    void reponseCChanged(QString arg);
    void reponseDChanged(QString arg);
    void bonneReponseChanged(int arg);

public slots:
    void setIntitule(QString arg);
    void setReponseA(QString arg);
    void setReponseB(QString arg);
    void setReponseC(QString arg);
    void setReponseD(QString arg);
    void setBonneReponse(int arg);

private:
    QString m_intitule;
    QString m_reponseA= "A" ;
    QString m_reponseB ;
    QString m_reponseC ;
    QString m_reponseD ;
    int m_bonneReponse;
};

#endif // QUESTION_H
