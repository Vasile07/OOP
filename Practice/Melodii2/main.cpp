#include <QApplication>
#include <QPushButton>
#include "Teste/Teste.h"
#include "Presentation/GUI.h"
int main(int argc, char *argv[]) {
    Teste test;
    test.ruleaza_toate_testele();
    QApplication a(argc, argv);
    RepoMelodii repo{"melodii.txt"};
    Validator validator;
    ServiceMelodii service{repo,validator};
    GUI gui{service};
    gui.ruleaza_gui();
    return QApplication::exec();
}
