#ifndef PATTERNS_H
#define PATTERNS_H
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

class patterns
{
public:
    patterns();
    QStringList keywP_e();
    QStringList keywP();
    QRegExp kSE();
    QRegExp kEE();
    QRegExp q();

};

#endif // PATTERNS_H
