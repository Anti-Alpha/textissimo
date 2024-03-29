#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <qtextedit.h>
#include <QFontDialog>
#include <QFont>
#include <QFontDatabase>
#include <QTextCursor>
#include <QColor>
#include <QColorDialog>
#include <QSyntaxHighlighter>
#include <QtGui>
#include <QCursor>
#include <QRegExp>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); // Removes the sidegaps from the text editor
    m_htmlHightLighter = new HtmlHighLighter(ui->textEdit->document());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path=""; // Clear the path
    ui->textEdit->setText(""); // Make the editor blank
}

void MainWindow::on_actionOpen_triggered()
{
 QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
 QFile file (file_name);
 file_path=file_name;

  if(!file.open(QFile::ReadOnly | QFile::Text)){
    QMessageBox::critical(this,"Error Opening File","File Cannot be Opened!");
    return;
  }
  else{
    //Read the file
    //QTextStream inputData(&file);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    QString text = ReadFile.readAll();
    ui->textEdit->setPlainText(text);
    file.close();
  }
}

void MainWindow::on_actionSave_triggered()
{
     QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
      return;
    }
    else{
      QTextStream out(&file);
      out << ui->textEdit->document()->toRawText();
      file.flush();
      file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty()) return;
    QTextDocumentWriter writer(fileName);
    QFile file(fileName);
    bool success=0;
    if(file.open(QIODevice::WriteOnly)){
        success = 1;
        QTextStream out(&file);
        out << ui->textEdit->document()->toRawText();
        file.close();
    }
    //success = writer.write(ui->textEdit->document()->toPlainText());

    if (success)
    {
        QMessageBox::information(this, "Отлично!", "Экспорт прошел успешно");
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "При сохранении файла произошла ошибка");
    }
}

void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt Creator.");
}

void MainWindow::on_actionLeft_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionRight_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionCenter_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionFont_Dialog_triggered()
{
    bool ok;
    QFont fontStyle = QFontDialog::getFont(&ok,this);

    if(ok){
            QTextCharFormat format;
            format.setFont(fontStyle);
            QTextCursor txtCursor(ui->textEdit->textCursor());
            txtCursor.setCharFormat(format);
            txtCursor.clearSelection();
            ui->textEdit->setTextCursor(txtCursor);
    }
    else{
            return;
    }

}

void MainWindow::on_actionColour_Dialog_triggered()
{

    QColor txtColour = QColorDialog::getColor();
    ui->textEdit->setTextColor(txtColour);

}

bool MainWindow::checkRegExp(QRegExp rx)
{
    if(rx.isValid() && !rx.isEmpty() && !rx.exactMatch("")) {
        return true;
    }   else
        QMessageBox::information(this, "", "Неккоректний шаблон регулярного выражения");
    return false;
}
