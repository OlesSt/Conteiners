#include <QCoreApplication>

#include <iostream>
#include "MyVector.h"
#include "MyListForward.h"
#include "MyList.h"
#include "MyStackArray.h"
#include "MyStackList.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    runMyVector();
//    runMyListForward();
//    runMyList();
//    runMyStackArray();
    runMyStackList();



    return a.exec();
}
