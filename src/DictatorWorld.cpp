/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QGuiApplication>
#include <QQuickView>

#include "Countries.h"
#include "Pays.h"
#include "Questions.h"


int main(int argc, char *argv[])
{
    Countries countries;

    countries.addPays(new Pays("France", "france.ico"));
    countries.addPays(new Pays("Allemagne", "allemagne.png"));
    countries.addPays(new Pays("Italie", "italie.png"));
    countries.addPays(new Pays("Etats-Unis", "etats-unis.png"));
    countries.addPays(new Pays("Russie", "russie.png"));
    countries.addPays(new Pays("Espagne", "espagne.png"));
    countries.addPays(new Pays("Belgique", "belgique.png"));
    countries.addPays(new Pays("Royaume-Uni", "angleterre.png"));

    Questions questions;

    questions.addQuestion(new Question("Quel est l'hymne national du pays?"));
    questions.addQuestion(new Question("Quel la population du pays?"));
    questions.addQuestion(new Question("Quel est le nom du dirigeant actuel du pays?"));
    questions.addQuestion(new Question("Quel est la superficie du pays?"));
    questions.addQuestion(new Question("Quel est la capitale du pays?"));

    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();

    view->rootContext()->setContextProperty("myCountries", &countries);
    view->rootContext()->setContextProperty("questions", &questions);

    qmlRegisterType<Pays>("Pays", 1 , 0, "Pays");
    qmlRegisterType<Question>("Question", 1, 0, "Question");

    view->setSource(SailfishApp::pathTo("qml/DictatorWorld.qml"));
    view->show();

    return app->exec();
}
