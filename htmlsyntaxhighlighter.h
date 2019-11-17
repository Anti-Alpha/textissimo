#ifndef HTMLSYNTAXHIGHLIGHTER_H
#define HTMLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <patterns.h>
QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE

class HtmlHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit HtmlHighLighter(QTextDocument *p = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    enum States {
        None,Tag,Comment,Quote
    };

    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> startTagRules;
    QVector<HighlightingRule> endTagRules;

    QRegExp openTag;
    QRegExp closeTag;
    QTextCharFormat edgeTagFormat;
    QTextCharFormat insideTagFormat;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat multiLineCommentFormat;

    QRegExp quotes;
    QTextCharFormat quotationFormat;
    QTextCharFormat tagsFormat;
};

#endif // HTMLSYNTAXHIGHLIGHTER_H
