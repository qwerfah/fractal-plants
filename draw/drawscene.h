#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include "transformableobject/transformableobject.h"
#include "light/light.h"

// Visualisation options
#define ABSORPTION 0.9
#define DIFFUSED_LIGHT 0.1
#define HEIGHT 480
#define WIDTH 640
#define HALF_HEIGHT 240
#define HALF_WIDTH 320

class DrawScene
{
public:
    DrawScene();

    void addLine(const Edge2d& line);
    void addPolygon(const std::vector<Point2d>& polygon);
    void addCircle(const Point2d& center, double radius);
    void addFrame(const QPixmap& frame);
    void pushFrame(const QPixmap& frame);

    void render();

    void setLight(Light* l);
    void setColor(const QColor& color);
    void setFillColor(const QColor& color);
    void setBackgroundColor(const QColor& color);
    void setFPS(uint framePerSec);
    void clear();

    QGraphicsScene* getRawScene() const;
    Light* getLight() const;
    QPen getPen() const;
    QBrush getBrush() const;

private:
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Light> light;
    std::vector<QPixmap> frameStack;
    QPen pen;
    QBrush brush;
    uint fps;
};

#endif // DRAWSCENE_H
