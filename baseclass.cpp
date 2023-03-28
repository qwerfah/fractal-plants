#include "baseclass.h"


BaseClass::BaseClass()
{

}

void BaseClass::push(std::shared_ptr<TransformableObject> &obj)
{
    scene.push(obj);
}


RotateManager& BaseClass::getRotateManager()
{
    return rotateManager;
}

ScaleManager& BaseClass::getScaleManager()
{
    return scaleManager;
}

TranslateManager& BaseClass::getTranslateManager()
{
    return translateManager;
}

DrawManager& BaseClass::getDrawManager()
{
    return drawManager;
}

GenerateManager& BaseClass::getGenerateManager()
{
    return generateManager;
}

LoadManager& BaseClass::getLoadManager()
{
    return loadManager;
}

MainScene& BaseClass::getMainScene()
{
    return scene;
}

DrawScene& BaseClass::getScene()
{
    return drawManager.getScene();
}
