#include "htmlsyntaxhighlighter.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>
#include <iostream>
 HtmlHighLighter::HtmlHighLighter(QTextDocument *p)
    : QSyntaxHighlighter(p)
{
    HighlightingRule rule;
    patterns pk;
    edgeTagFormat.setForeground(QBrush(QColor("#32a9dd")));
    insideTagFormat.setForeground(Qt::magenta);
    insideTagFormat.setFontWeight(QFont::Bold);
    openTag = QRegExp("<");
    closeTag = QRegExp(">");

    tagsFormat.setForeground(Qt::blue);
    tagsFormat.setFontWeight(QFont::Bold);


    for (const QString &pattern : pk.keywP())
    {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        startTagRules.append(rule);
    }

    for (const QString &pattern : pk.keywP_e())
    {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        endTagRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::darkGray);
    commentStartExpression = pk.kSE();
    commentEndExpression = pk.kEE();

    quotationFormat.setForeground(Qt::darkGreen);
    quotes = pk.q();
}

void HtmlHighLighter::highlightBlock(const QString &text)
{
    setCurrentBlockState(HtmlHighLighter::None);
    int startIndex = 0;
    if (previousBlockState() != HtmlHighLighter::Tag && previousBlockState() != HtmlHighLighter::Quote)
    {
        startIndex = openTag.indexIn(text);
    }
    std::cout <<"startIndexTag "<<startIndex << '\n';

    int subPreviousTag = previousBlockState();
    //subPreviousTag определяет находимся ли мы внутри тега или нет, если в теге, то тогда ответ - 1,в комментариях - 2, в кавычках - 3, не нашлось - 0
    std::cout <<"subPreviousTag "<<subPreviousTag << '\n';

    while (startIndex >= 0)
    {
        int endIndex = closeTag.indexIn(text, startIndex);
        std::cout <<"endIndexTag" << endIndex << '\n';
        int tagLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(HtmlHighLighter::Tag);
            tagLength = text.length() - startIndex;
        }
        else
        {
            tagLength = endIndex - startIndex + closeTag.matchedLength();
        }

        if (subPreviousTag != HtmlHighLighter::Tag)
        {
            setFormat(startIndex, 1, edgeTagFormat);
            setFormat(startIndex + 1, tagLength - 1, insideTagFormat);
        }
        else
        {
            setFormat(startIndex, tagLength, insideTagFormat);
            subPreviousTag = HtmlHighLighter::None;
        }
        setFormat(endIndex, 1, edgeTagFormat);

        int startQuoteIndex = 0;
        if (previousBlockState() != HtmlHighLighter::Quote)
        {
            startQuoteIndex = quotes.indexIn(text, startIndex);
        }

        while (startQuoteIndex >= 0 && ((startQuoteIndex < endIndex) || (endIndex == -1)))
        {
            int endQuoteIndex = quotes.indexIn(text, startQuoteIndex + 1);
            int quoteLength;
            if (endQuoteIndex == -1)
            {
                setCurrentBlockState(HtmlHighLighter::Quote);
                quoteLength = text.length() - startQuoteIndex;
            }
            else
            {
                quoteLength = endQuoteIndex - startQuoteIndex + quotes.matchedLength();
            }

            if ((endIndex > endQuoteIndex) || endIndex == -1)
            {
                setFormat(startQuoteIndex, quoteLength, quotationFormat);
                startQuoteIndex = quotes.indexIn(text, startQuoteIndex + quoteLength);
            }
            else
            {
                break;
            }
        }

        startIndex = openTag.indexIn(text, startIndex + tagLength);
    }

    for (const HighlightingRule &rule : startTagRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index + 1, length - 1, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    for (const HighlightingRule &rule : endTagRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index + 1, 1, edgeTagFormat);
            setFormat(index + 2, length - 2, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    int startCommentIndex = 0;
    if (previousBlockState() != HtmlHighLighter::Comment)
    {
        startCommentIndex = commentStartExpression.indexIn(text);
    }

    while (startCommentIndex >= 0)
    {
        int endCommentIndex = commentEndExpression.indexIn(text, startCommentIndex);
        int commentLength;

        if (endCommentIndex == -1)
        {
            setCurrentBlockState(HtmlHighLighter::Comment);
            commentLength = text.length() - startCommentIndex;
        }
        else
        {
            commentLength = endCommentIndex - startCommentIndex
                            + commentEndExpression.matchedLength();
        }

        setFormat(startCommentIndex, commentLength, multiLineCommentFormat);
        startCommentIndex = commentStartExpression.indexIn(text, startCommentIndex + commentLength);
    }
}
