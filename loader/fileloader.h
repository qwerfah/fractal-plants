#ifndef FILELOADER_H
#define FILELOADER_H


#include <QString>
#include <fstream>
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QStringList"
#include "enums.h"
#include "exceptions.h"
#include "factory/builderfactory.h"
#include "loader.h"
#include "auxiliarystructures/polygonconnection.h"


class FileLoader : public Loader
{
public:
    FileLoader(const QString &filename);
    FileLoader(const std::string &filename);
    FileLoader(const char *filename);
    ~FileLoader();

    virtual std::shared_ptr<TransformableObject> load() override;


private:
    std::string filename;
    std::ifstream fstream;

    PolygonConnection loadConnection(const std::string& data) const;
    Point3d loadPoint3d(const std::string& data) const;
    QColor loadRGBColor(const std::string& data) const;
    std::shared_ptr<TransformableObject> loadPolygonSurface();
};

#endif // FILELOADER_H
