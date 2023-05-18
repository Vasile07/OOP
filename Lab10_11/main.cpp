#include <QApplication>
#include <QPushButton>
#include "Tests/Teste.h"
#include "Presentation_QT/UI_QT.h"
#include "Repository/RepoFilme.h"
#include "Repository/FileRepoFilme.h"
#include "Validator/Validator.h"
#include "Bussines/ServiceFilme.h"

int main(int argc, char *argv[]) {
    Teste t;
    t.ruleaza_toate_testele();

    QApplication a(argc, argv);

    FileRepoFilme repo{"input.txt"};
    Validator validator;
    ServiceFilme service{repo,validator};

    UI_QT console{service};
    console.ruleaza_consola();

    return QApplication::exec();
}
