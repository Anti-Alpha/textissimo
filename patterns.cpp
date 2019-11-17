#include "patterns.h"
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
patterns::patterns()
{
}
    QStringList patterns::keywP_e() {

    QStringList keywordPatterns_end;
    keywordPatterns_end << "<!\\bDOCTYPE\\b" << "</\\ba\\b" << "</\\babbr\\b" << "</\\bacronym\\b" << "</\\baddress\\b" << "</\\bapplet\\b"
                        << "</\\barea\\b" << "</\\barticle\\b" << "</\\baside\\b" << "</\\baudio\\b" << "</\\bb\\b"
                        << "</\\bbase\\b" << "</\\bbasefont\\b" << "</\\bbdi\\b" << "</\\bbdo\\b" << "</\\bbgsound\\b"
                        << "</\\bblockquote\\b" << "</\\bbig\\b" << "</\\bbody\\b" << "</\\bblink\\b" << "</\\bbr\\b"
                        << "</\\bbutton\\b" << "</\\bcanvas\\b" << "</\\bcaption\\b" << "</\\bcenter\\b" << "</\\bcite\\b"
                        << "</\\bcode\\b" << "</\\bcol\\b" << "</\\bcolgroup\\b" << "</\\bcommand\\b" << "</\\bcomment\\b"
                        << "</\\bdata\\b" << "</\\bdatalist\\b" << "</\\bdd\\b" << "</\\bdel\\b" << "</\\bdetails\\b"
                        << "</\\bdfn\\b" << "</\\bdialog\\b" << "</\\bdir\\b" << "</\\bdiv\\b" << "</\\bdl\\b"
                        << "</\\bdt\\b" << "</\\bem\\b" << "</\\bembed\\b" << "</\\bfieldset\\b" << "</\\bfigcaption\\b"
                        << "</\\bfigure\\b" << "</\\bfont\\b" << "</\\bfooter\\b" << "</\\bform\\b" << "</\\bframe\\b"
                        << "</\\bframeset\\b" << "</\\bh1\\b" << "</\\bh2\\b" << "</\\bh3\\b" << "</\\bh4\\b"
                        << "</\\bh5\\b" << "</\\bh6\\b" << "</\\bhead\\b" << "</\\bheader\\b" << "</\\bhgroup\\b"
                        << "</\\bhr\\b" << "</\\bhtml\\b" << "</\\bi\\b" << "</\\biframe\\b" << "</\\bimg\\b"
                        << "</\\binput\\b" << "</\\bins\\b" << "</\\bisindex\\b" << "</\\bkbd\\b" << "</\\bkeygen\\b"
                        << "</\\blabel\\b" << "</\\blegend\\b" << "</\\bli\\b" << "</\\blink\\b" << "</\\blisting\\b"
                        << "</\\bmain\\b" << "</\\bmap\\b" << "</\\bmarquee\\b" << "</\\bmark\\b" << "</\\bmenu\\b"
                        << "</\\bamenuitem\\b" << "</\\bmeta\\b" << "</\\bmeter\\b" << "</\\bmulticol\\b" << "</\\bnav\\b"
                        << "</\\bnobr\\b" << "</\\bnoembed\\b" << "</\\bnoindex\\b" << "</\\bnoframes\\b" << "</\\bnoscript\\b"
                        << "</\\bobject\\b" << "</\\bol\\b" << "</\\boptgroup\\b" << "</\\boption\\b" << "</\\boutput\\b"
                        << "</\\bp\\b" << "</\\bparam\\b" << "</\\bpicture\\b" << "</\\bplaintext\\b" << "</\\bpre\\b"
                        << "</\\bprogress\\b" << "</\\bq\\b" << "</\\brp\\b" << "</\\brt\\b" << "</\\brtc\\b" << "</\\bruby\\b"
                        << "</\\bs\\b" << "</\\bsamp\\b" << "</\\bscript\\b" << "</\\bsection\\b" << "</\\bselect\\b"
                        << "</\\bsmall\\b" << "</\\bsource\\b" << "</\\bspacer\\b" << "</\\bspan\\b" << "</\\bstrike\\b"
                        << "</\\bstrong\\b" << "</\\bstyle\\b" << "</\\bsub\\b" << "</\\bsummary\\b" << "</\\bsup\\b"
                        << "</\\btable\\b" << "</\\btbody\\b" << "</\\btd\\b" << "</\\btemplate\\b" << "</\\btextarea\\b"
                        << "</\\btfoot\\b" << "</\\bth\\b" << "</\\bthead\\b" << "</\\btime\\b" << "</\\btitle\\b"
                        << "</\\btr\\b" << "</\\btrack\\b" << "</\\btt\\b" << "</\\bu\\b" << "</\\bul\\b" << "</\\bvar\\b"
                        << "</\\bvideo\\b" << "</\\bwbr\\b" << "</\\bxmp\\b";
    return keywordPatterns_end;
    }
    QStringList patterns::keywP()   {
    QStringList keywordPatterns;

    keywordPatterns << "<\\ba\\b" << "<\\babbr\\b" << "<\\bacronym\\b" << "<\\baddress\\b" << "<\\bapplet\\b"
                    << "<\\barea\\b" << "<\\barticle\\b" << "<\\baside\\b" << "<\\baudio\\b" << "<\\bb\\b"
                    << "<\\bbase\\b" << "<\\bbasefont\\b" << "<\\bbdi\\b" << "<\\bbdo\\b" << "<\\bbgsound\\b"
                    << "<\\bblockquote\\b" << "<\\bbig\\b" << "<\\bbody\\b" << "<\\bblink\\b" << "<\\bbr\\b"
                    << "<\\bbutton\\b" << "<\\bcanvas\\b" << "<\\bcaption\\b" << "<\\bcenter\\b" << "<\\bcite\\b"
                    << "<\\bcode\\b" << "<\\bcol\\b" << "<\\bcolgroup\\b" << "<\\bcommand\\b" << "<\\bcomment\\b"
                    << "<\\bdata\\b" << "<\\bdatalist\\b" << "<\\bdd\\b" << "<\\bdel\\b" << "<\\bdetails\\b"
                    << "<\\bdfn\\b" << "<\\bdialog\\b" << "<\\bdir\\b" << "<\\bdiv\\b" << "<\\bdl\\b"
                    << "<\\bdt\\b" << "<\\bem\\b" << "<\\bembed\\b" << "<\\bfieldset\\b" << "<\\bfigcaption\\b"
                    << "<\\bfigure\\b" << "<\\bfont\\b" << "<\\bfooter\\b" << "<\\bform\\b" << "<\\bframe\\b"
                    << "<\\bframeset\\b" << "<\\bh1\\b" << "<\\bh2\\b" << "<\\bh3\\b" << "<\\bh4\\b"
                    << "<\\bh5\\b" << "<\\bh6\\b" << "<\\bhead\\b" << "<\\bheader\\b" << "<\\bhgroup\\b"
                    << "<\\bhr\\b" << "<\\bhtml\\b" << "<\\bi\\b" << "<\\biframe\\b" << "<\\bimg\\b"
                    << "<\\binput\\b" << "<\\bins\\b" << "<\\bisindex\\b" << "<\\bkbd\\b" << "<\\bkeygen\\b"
                    << "<\\blabel\\b" << "<\\blegend\\b" << "<\\bli\\b" << "<\\blink\\b" << "<\\blisting\\b"
                    << "<\\bmain\\b" << "<\\bmap\\b" << "<\\bmarquee\\b" << "<\\bmark\\b" << "<\\bmenu\\b"
                    << "<\\bamenuitem\\b" << "<\\bmeta\\b" << "<\\bmeter\\b" << "<\\bmulticol\\b" << "<\\bnav\\b"
                    << "<\\bnobr\\b" << "<\\bnoembed\\b" << "<\\bnoindex\\b" << "<\\bnoframes\\b" << "<\\bnoscript\\b"
                    << "<\\bobject\\b" << "<\\bol\\b" << "<\\boptgroup\\b" << "<\\boption\\b" << "<\\boutput\\b"
                    << "<\\bp\\b" << "<\\bparam\\b" << "<\\bpicture\\b" << "<\\bplaintext\\b" << "<\\bpre\\b"
                    << "<\\bprogress\\b" << "<\\bq\\b" << "<\\brp\\b" << "<\\brt\\b" << "<\\brtc\\b" << "<\\bruby\\b"
                    << "<\\bs\\b" << "<\\bsamp\\b" << "<\\bscript\\b" << "<\\bsection\\b" << "<\\bselect\\b"
                    << "<\\bsmall\\b" << "<\\bsource\\b" << "<\\bspacer\\b" << "<\\bspan\\b" << "<\\bstrike\\b"
                    << "<\\bstrong\\b" << "<\\bstyle\\b" << "<\\bsub\\b" << "<\\bsummary\\b" << "<\\bsup\\b"
                    << "<\\btable\\b" << "<\\btbody\\b" << "<\\btd\\b" << "<\\btemplate\\b" << "<\\btextarea\\b"
                    << "<\\btfoot\\b" << "<\\bth\\b" << "<\\bthead\\b" << "<\\btime\\b" << "<\\btitle\\b"
                    << "<\\btr\\b" << "<\\btrack\\b" << "<\\btt\\b" << "<\\bu\\b" << "<\\bul\\b" << "<\\bvar\\b"
                    << "<\\bvideo\\b" << "<\\bwbr\\b" << "<\\bxmp\\b";
    return keywordPatterns;
    }
    QRegExp patterns::kSE() {
        return QRegExp("<!--");
    }
    QRegExp patterns::kEE() {
        return QRegExp("-->");
    }
    QRegExp patterns::q() {
        return QRegExp("\"");
    }

