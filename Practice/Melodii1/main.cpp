#include <QApplication>
#include <QPushButton>
#include "Test/Test.h"
#include "Persistance/RepoMelodii.h"
#include "Business/ServiceMelodii.h"
#include "Validator/Validator.h"
#include "Presentation/GUI.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    Test test;
    test.ruleaza_toate_testele();

    RepoMelodii repo{"melodii.txt"};
    Validator validator;
    ServiceMelodii service{repo,validator};
    GUI gui{service};
    gui.ruleaza_ui();
    return QApplication::exec();
}
