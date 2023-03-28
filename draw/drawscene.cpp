#include "drawscene.h"
#include <QPainter>

DrawScene::DrawScene()
{
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene());
    pen = QPen(QColor(255, 255, 255));
    brush = QBrush(QColor(0, 0, 0));
    scene->setBackgroundBrush(QColor(0, 0, 0));
}

void DrawScene::addLine(const Edge2d &line)
{
    Point2d start = line.p1();
    Point2d end = line.p2();
    scene->addLine(start.x(), start.y(), end.x(), end.y(), pen);
}

void DrawScene::addPolygon(const std::vector<Point2d>& polygon)
{
    QPolygon pol;

    for (size_t i = 0; i < polygon.size(); i++)
    {
        pol.push_back(QPoint(polygon[i].x(), polygon[i].y()));;
    }
    scene->addPolygon(pol, pen, brush);
}

void DrawScene::addCircle(const Point2d& center, double radius)
{
    double radius_2 = radius * 2;
    scene->addEllipse(center.x() - radius, center.y() - radius,
                      radius_2, radius_2, pen, brush);
}

void DrawScene::addFrame(const QPixmap& frame)
{
    scene->addPixmap(frame);
}

void DrawScene::pushFrame(const QPixmap &frame)
{
    frameStack.push_back(frame);
}

void DrawScene::render()
{
    for (auto frame : frameStack)
    {
        scene->addPixmap(frame);
        // Delay for requered FPS
    }
}

void DrawScene::setLight(Light *l)
{
    light = std::shared_ptr<Light>(l);
}

void DrawScene::setColor(const QColor& color)
{
    pen = QPen(color);
}

void DrawScene::setFillColor(const QColor& color)
{
    brush = QBrush(color);
}

void DrawScene::setBackgroundColor(const QColor &color)
{
    scene->setBackgroundBrush(QBrush(color));
}

void DrawScene::setFPS(uint framePerSec)
{
    fps = framePerSec;
}

void DrawScene::clear()
{
    scene->clear();
    scene->clearFocus();
    //scene->setBackgroundBrush(QBrush(QColor(0, 0, 0)));
}

QGraphicsScene* DrawScene::getRawScene() const
{
    return scene.get();
}

Light* DrawScene::getLight() const
{
    return light.get();
}

QPen DrawScene::getPen() const
{
    return pen;
}

QBrush DrawScene::getBrush() const
{
    return brush;
}
