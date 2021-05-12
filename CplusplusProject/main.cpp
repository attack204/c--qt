#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<BigNumber.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    vector<int> v1; v1.push_back(1);
    vector<int> v2; v2.push_back(2);
    Int a1(v1), b1(v2);
    cout << a1 + b1;
    return a.exec();
}
