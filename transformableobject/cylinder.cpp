#include "cylinder.h"
#include "draw/drawscene.h"

Cylinder::Cylinder()
{
    p1 = Point3d();
    p2 = Point3d();
    r1 = 0;
    r2 = 0;
    z = 0;
    color = QColor(0, 0, 0);
}

Cylinder::Cylinder(const Point3d& start, const Point3d& end,
                   double rd1, double rd2, QColor clr,  DrawMode m)
{
    p1 = start;
    p2 = end;
    r1 = rd1;
    r2 = rd2;
    color = clr;
    mode = m;
    setZ();
}

void Cylinder::translate(double x, double y, double z)
{
    p1.translate(x, y, z);
    p2.translate(x, y, z);
    setZ();
}

void Cylinder::scale(double kx, double ky, double kz)
{
    p1.scale(kx, ky, kz);
    p2.scale(kx, ky, kz);
    setZ();
}

void Cylinder::rotateX(double angle)
{
    p1.rotateX(angle);
    p2.rotateX(angle);
    setZ();
}

void Cylinder::rotateY(double angle)
{
    p1.rotateY(angle);
    p2.rotateY(angle);
    setZ();
}

void Cylinder::rotateZ(double angle)
{
    p1.rotateZ(angle);
    p2.rotateZ(angle);
    setZ();
}

void Cylinder::draw(DrawScene& scene,
                    std::shared_ptr<Projection>& projection,
                    const Position& pos)
{
    QColor clr = scene.getPen().color();

    scene.setColor(color);

    (void)pos;
    //p13d.translate(pos.center[0], pos.center[1], pos.center[2]);
    //p23d.translate(pos.center[0], pos.center[1], pos.center[2]);

    //p13d.rotateX(pos.orientation[0]);
    //p23d.rotateX(pos.orientation[0]);

    //p13d.rotateY(pos.orientation[1]);
    //p23d.rotateY(pos.orientation[1]);

    //p13d.rotateZ(pos.orientation[2]);
    //p23d.rotateZ(pos.orientation[2]);

    Point2d p12d = projection->project(p1);
    Point2d p22d = projection->project(p2);

    double l = Edge2d(p12d, p22d).length();

    double cosAlpha, sinAlpha;

    if (!(p22d.y() - p12d.y()))
    {
        cosAlpha = 0;
        sinAlpha = 1;
    }
    else if (!(p22d.x() - p12d.x()))
    {
        cosAlpha = 1;
        sinAlpha = 0;
    }
    else
    {
        cosAlpha = (p22d.y() - p12d.y()) / l;
        sinAlpha = (p22d.x() - p12d.x()) / l;
    }

    Point2d p1l1 = Point2d(p12d.x() - r1 * cosAlpha,
                           p12d.y() + r1 * sinAlpha);
    Point2d p2l1 = Point2d(p22d.x() - r2 * cosAlpha,
                           p22d.y() + r2 * sinAlpha);



    Point2d p1l2 = Point2d(p12d.x() + r1 * cosAlpha,
                           p12d.y() - r1 * sinAlpha);
    Point2d p2l2 = Point2d(p22d.x() + r2 * cosAlpha,
                           p22d.y() - r2 * sinAlpha);

    if (mode == FILL)
    {
        QColor fclr = scene.getBrush().color();
        double I = z / 100.0;
        if (I < 0) I = 0.0;
        if (I > 1) I = 1.0;
        QColor c = QColor(color.red() * I, color.green() * I, color.blue() * I);
        scene.setColor(c);
        scene.setFillColor(c);
        std::vector<Point2d> polygon({p1l1, p2l1, p2l2, p1l2});
        scene.addPolygon(polygon);
        scene.setFillColor(fclr);
    }
    else
    {
        scene.addCircle(p12d, r1);
        scene.addCircle(p22d, r2);
        scene.addLine(Edge2d(p1l1, p2l1));
        scene.addLine(Edge2d(p1l2, p2l2));
    }

    scene.setColor(clr);
}

bool Cylinder::operator<(const TransformableObject& other)
{
    return (z < static_cast<const Cylinder&>(other).z);
}

TransformableObject& Cylinder::operator=(const TransformableObject& other)
{
    const Cylinder& cylinder = static_cast<const Cylinder&>(other);

    p1 = cylinder.p1;
    p2 = cylinder.p2;
    r1 = cylinder.r1;
    r2 = cylinder.r2;
    z = cylinder.z;
    color = cylinder.color;
    mode = cylinder.mode;
    _id = cylinder._id;

    return *this;
}

Point3d Cylinder::getP1() const
{
    return p1;
}

Point3d Cylinder::getP2() const
{
    return p2;
}

double Cylinder::getR1() const
{
    return r1;
}

double Cylinder::getR2() const
{
    return r2;
}

QColor Cylinder::getColor() const
{
    return color;
}

DrawMode Cylinder::getDrawMode() const
{
    return mode;
}

double Cylinder::getZ() const
{
    return z;
}

double Cylinder::getDepth(double x, double y)
{
    double depth = 0;

    return depth;
}

void Cylinder::setP1(const Point3d& p)
{
    p1 = p;
}

void Cylinder::setP2(const Point3d& p)
{
    p2 = p;
}

void Cylinder::setR1(double r)
{
    r1 = r;
}

void Cylinder::setR2(double r)
{
    r2 = r;
}

void Cylinder::setColor(QColor clr)
{
    color = clr;
}

void Cylinder::setDrawMode(DrawMode m)
{
    mode = m;
}

void Cylinder::setZ()
{
    //z = (p1.z() > p2.z()) ? p1.z() : p2.z();
    z = (p1.z() + p2.z()) / 2;
}
