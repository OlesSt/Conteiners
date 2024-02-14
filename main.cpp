#include <QCoreApplication>

#include <iostream>
#include "MyVector.h"
#include "MyListForward.h"
#include "MyList.h"
#include "MyStackArray.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    runMyVector();
//    runMyListForward();
//    runMyList();
    runMyStackArray();



    return a.exec();
}
