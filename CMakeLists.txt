cmake_minimum_required(VERSION 3.14)

project(Conteiners LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Conteiners
  main.cpp
  myvector.h
  mylistforward.h
  mylist.h
  mystackarray.h
  mystacklist.h
  myqueuearray.h
  myqueuelist.h
  mygenerictree.h
  mybinarytree.h
  binarysearchtree.h

  testclass.h
)
target_link_libraries(Conteiners Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS Conteiners
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
