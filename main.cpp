#include <QCoreApplication>
#include <application.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    application app;
    app.menu();

    return a.exec();
}
