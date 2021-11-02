#ifndef COMMANDUTIL_H
#define COMMANDUTIL_H

#include <QObject>
#include <QString>

class CommandUtil : public QObject
{
    Q_OBJECT
public:
    CommandUtil();

    /**
     * @brief 数字转hex
     * @return hex字符串
     */
    Q_INVOKABLE QString numberToHex(int);

    /**
     * @brief 唯一实例
     * @return 唯一实例
     */
    static CommandUtil* instance();
};

#endif // COMMANDUTIL_H
