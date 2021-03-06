#include "jsonparser.h"
#include "nlohmann/json.hpp"
#include <QMap>
#include <QDebug>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>

using json = nlohmann::json;

JsonParser::JsonParser()
{

}

QMap<QString, QString> JsonParser::getAddress(QString jsonString) {
    QMap<QString, QString> output;
    //json jsonData = json::parse(jsonString.toUtf8().constData());
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObject = doc.object();
    //Get address
    QJsonObject tempObj = jsonObject.take("address").toObject();

    foreach(const QString& key, tempObj.keys()) {
            QJsonValue value = tempObj.value(key);
            qDebug() << key << ": " << value.toString();
            output.insert(key, value.toString());
        }
    return output;
}

