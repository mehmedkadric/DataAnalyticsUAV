#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QString>
#include <QMap>

class JsonParser
{
public:
    JsonParser();
    QMap<QString, QString> getAddress(QString jsonString);
};

#endif // JSONPARSER_H
