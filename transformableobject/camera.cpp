#include "camera.h"

Camera::Camera()
{

}


Camera::Camera(Position& pos) : _pos(pos)
{

}


void Camera::setPosition(Position& pos)
{
    _pos = pos;
}


Position Camera::getPosition()
{
    return _pos;
}
