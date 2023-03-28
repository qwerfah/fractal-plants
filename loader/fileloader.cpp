#include "fileloader.h"
#include "builder/psurfacebuilder.h"
#include <fstream>

FileLoader::FileLoader(const QString &filename)
    : filename(filename.toStdString())
{
}

FileLoader::FileLoader(const std::string &filename)
    : filename(filename)
{
}

FileLoader::FileLoader(const char *filename)
    : filename(std::string(filename))
{
}

FileLoader::~FileLoader()
{
}

PolygonConnection FileLoader::loadConnection(const std::string& data) const
{
    std::string buff, temp = data + ' ';
    PolygonConnection connection;

    for (size_t i = 0; i < temp.length(); i++)
    {
        if (temp[i] == ' ')
        {
            if (buff.length())
            {
                size_t num;

                try
                {
                    num = std::stoi(buff);
                }
                catch (std::invalid_argument)
                {
                    throw CorruptedData("FileLoader: file data is damaged.");
                }

                connection.push(num - 1);
                buff = "";
            }
        }
        else
        {
            buff += temp[i];
        }
    }

    return connection;
}

Point3d FileLoader::loadPoint3d(const std::string& data) const
{
    std::string buff, temp = data + ' ';
    std::vector<double> tmp;

    for (uint i = 0; i < temp.length(); i++)
    {
        if (temp[i] == ' ')
        {
            if (buff.length())
            {
                try
                {
                    tmp.push_back(std::stod(buff));
                }
                catch (std::invalid_argument)
                {
                    throw CorruptedData("FileLoader: file data is damaged.");
                }

                buff = "";
            }
        }
        else
        {
            buff += temp[i];
        }
    }

    return Point3d(tmp[0], tmp[1], tmp[2]);
}

QColor FileLoader::loadRGBColor(const std::string& data) const
{
    std::string buff = "", temp = data + ' ';
    std::vector<int> tmp;

    for (uint i = 0; i < temp.length(); i++)
    {
        if (temp[i] == ' ')
        {
            if (buff.length())
            {
                try
                {
                    tmp.push_back(std::stoi(buff));
                }
                catch (std::invalid_argument)
                {
                    throw CorruptedData("FileLoader: file data is damaged.");
                }

                buff = "";
            }
        }
        else
        {
            buff += temp[i];
        }
    }

    return QColor(tmp[0], tmp[1], tmp[2]);
}

std::shared_ptr<TransformableObject> FileLoader::load()
{
    char buff[500];
    std::shared_ptr<TransformableObject> object;

    fstream.open(filename);
    if (!fstream)
    {
        throw BadStream("FileLoader: stream damaged or not opened.");
    }

    fstream.getline(buff, 500);

    if (!std::string("PS").compare(buff))
    {
        object =  loadPolygonSurface();
        fstream.close();
    }
    else
    {
        fstream.close();
        throw WrongObjectType("FileLoader: wrong loading object type in file", buff);
    }

    return object;
}

std::shared_ptr<TransformableObject> FileLoader::loadPolygonSurface()
{
    PSurfaceBuilder builder;

    char buff[500];

    while (!fstream.eof())
    {
        fstream.getline(buff, sizeof(buff));
        if (buff[0] == 'b')
        {
            buff[0] = ' ';
            if (buff[1] == ' ')
            {
                QColor color = loadRGBColor(buff);
                builder.setBoarderColor(color);
            }
        }
        else if (buff[0] == 'l')
        {
            buff[0] = ' ';
            if (buff[1] == ' ')
            {
                QColor color = loadRGBColor(buff);
                builder.setFillColor(color);
            }
        }
        else if (buff[0] == 'v')
        {
            buff[0] = ' ';
            if (buff[1] == ' ')
            {
                Point3d point = loadPoint3d(buff);
                builder.push(point);
            }
        }
        else if (buff[0] == 'f')
        {
            buff[0] = ' ';
            PolygonConnection connection = loadConnection(buff);
            builder.push(connection);
        }
        buff[0] = '\0';
    }

    return builder.build();
}
