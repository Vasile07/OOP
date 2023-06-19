#include <QApplication>
#include <QPushButton>
#include "Test/Test.h"
#include "Business/ServiceProduse.h"
#include "Presentation/GUI.h"

int main(int argc, char *argv[]) {
    Test test;
    test.ruleaza_toate_testele();
    QApplication a(argc, argv);
    RepoProduse repo{"produse.txt"};
    Validator validator;
    ServiceProduse service{repo,validator};
    GUI gui{service};
    gui.ruleaza_gui();
    return QApplication::exec();
}
