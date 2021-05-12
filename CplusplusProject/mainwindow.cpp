#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <BigNumber.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("123");
    ui->lineEdit_2->setText("456");

    QString num1 = ui->lineEdit->text();
    ui->lineEdit_3->setText(num1);
}

void MainWindow::on_btnAdd_clicked() {
    whichMode = 1;
}
void MainWindow::on_btnDec_clicked() {
    whichMode = 2;
}
void MainWindow::on_btnMul_clicked() {
    whichMode = 3;
}
void MainWindow::on_btnDiv_clicked() {
    whichMode = 4;
}
void MainWindow::on_btnCalc_clicked() {
   QString num1 = ui->lineEdit->text();
   QString num2 = ui->lineEdit_2->text();

   /*将第一个数存到vector里面*/
   vector<int> v1;
   for(int i = 0; i < num1.size(); i++) v1.emplace_back(num1.at(i).toLatin1() - 48);
   reverse(v1.begin(), v1.end());

   /*将第二个数存到vector里面*/
   vector<int> v2;
   for(int i = 0; i < num2.size(); i++) v2.emplace_back(num2.at(i).toLatin1() - 48);
   reverse(v2.begin(), v2.end());

   Int a(v1), b(v2);
   Int res(v1);
   QString ans;
   switch(whichMode) {
    case 1:
       res = a + b;
       for(int i = 0; i < res.c.size(); i++) {
           ans.append(res.c[i] + 48);
       }
       reverse(ans.begin(), ans.end());
       ui->lineEdit_3->setText(ans);
       break;

    case 2:
       res = a - b;
       for(int i = 0; i < res.c.size(); i++) {
           ans.append(res.c[i] + 48);
       }
       reverse(ans.begin(), ans.end());
       ui->lineEdit_3->setText(ans);
       break;

    case 3:
       res = a * b;
       for(int i = 0; i < res.c.size(); i++) {
           ans.append(res.c[i] + 48);
       }
       reverse(ans.begin(), ans.end());
       ui->lineEdit_3->setText(ans);
       break;
    case 4:
       res = a / b;
       for(int i = 0; i < res.c.size(); i++) {
           ans.append(res.c[i] + 48);
       }
       reverse(ans.begin(), ans.end());
       ui->lineEdit_3->setText(ans);
       break;
   }

}
 MainWindow::~MainWindow()
{
    delete ui;
}
