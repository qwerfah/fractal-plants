#ifndef STATICCAMERA_H
#define STATICCAMERA_H


#include "camera.h"


class StaticCamera : public Camera
{
public:
    StaticCamera() = default;
    StaticCamera(Position& pos) : Camera(pos) {}
    ~StaticCamera() = default;
};


#endif // STATICCAMERA_H
