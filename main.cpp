#include <QCoreApplication>

#include <iostream>
#include "MyVector.h"
#include "MyListForward.h"
#include "MyList.h"
#include "MyStackArray.h"
#include "MyStackList.h"
#include "MyQueueArray.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    runMyVector();
//    runMyListForward();
//    runMyList();
//    runMyStackArray();
//    runMyStackList();
    runMyQueueArray();



    return a.exec();
}
