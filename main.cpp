#include "interface/window.h"
#include "interface/qtwindow.h"
#include "baseclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window window(new QtMainWindow());
    BaseClass baseClass;

    a.setApplicationName("Курсовой проект по теме \"Моделирование растений с использованием фрактальных структур\"");
    window.setBaseClass(baseClass);
    window.show();

    return a.exec();
}
