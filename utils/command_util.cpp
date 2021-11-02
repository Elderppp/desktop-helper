#include "command_util.h"

CommandUtil::CommandUtil()
{

}

CommandUtil* CommandUtil::instance()
{
    static CommandUtil u;
    return &u;
}

QString CommandUtil::numberToHex(int i)
{
    return QString::number(i, 16);
}
