#include <QCoreApplication>

#include <iostream>
#include "MyVector.h"
#include "MyListForward.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    runMyVector();
    runMyListForward();



    return a.exec();
}
