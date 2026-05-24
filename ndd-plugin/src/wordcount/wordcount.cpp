#include "wordcount.h"
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>

NDD_PROC_IDENTIFY(NDD_PROC_DATA* pData)
{
    pData->nVersion = NDD_PLUGIN_VERSION;
    strcpy(pData->szName, "WordCount");
    return true;
}

NDD_PROC_MENU_CLICK(int nMenuID)
{
    if (nMenuID != 1001) return;

    char szText[8192 * 10] = {0};
    NDD_GetSelectedText(szText, sizeof(szText));
    QString text = QString::fromUtf8(szText);

    if (text.isEmpty()) {
        NDD_GetText(szText, sizeof(szText));
        text = QString::fromUtf8(szText);
    }

    if (text.isEmpty()) {
        QMessageBox::information(nullptr, "字数统计", "文本为空！");
        return;
    }

    int total = text.length();
    int chinese = 0;
    int letters = 0;
    int spaces = 0;

    QRegularExpression chineseReg("[\\u4e00-\\u9fa5]");
    for (QChar c : text) {
        if (chineseReg.match(c).hasMatch()) chinese++;
        else if (c.isLetterOrNumber()) letters++;
        else if (c.isSpace()) spaces++;
    }

    QString result = QString("📊 字数统计结果\n\n")
                   + QString("总字符数：%1\n").arg(total)
                   + QString("汉字数：%1\n").arg(chinese)
                   + QString("英文/数字：%1\n").arg(letters)
                   + QString("空格数：%1").arg(spaces);

    QMessageBox::information(nullptr, "字数统计", result);
}
