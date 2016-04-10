#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedSize(671,422);
    w.setWindowTitle("DO");
    w.show();

    return a.exec();
}
