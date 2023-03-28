#ifndef BASECLASS_H
#define BASECLASS_H


#include "manager/drawmanager.h"
#include "manager/rotatemanager.h"
#include "manager/scalemanager.h"
#include "manager/translatemanager.h"
#include "manager/generatemanager.h"
#include "manager/loadmanager.h"
#include "mainscene.h"


 class BaseClass
 {
public:
     BaseClass();
     void push(std::shared_ptr<TransformableObject> &obj);
     DrawScene& getScene();

     RotateManager& getRotateManager();
     ScaleManager& getScaleManager();
     TranslateManager& getTranslateManager();
     DrawManager& getDrawManager();
     GenerateManager& getGenerateManager();
     LoadManager& getLoadManager();
     MainScene& getMainScene();

private:
     RotateManager rotateManager;
     ScaleManager scaleManager;
     TranslateManager translateManager;
     DrawManager drawManager;
     GenerateManager generateManager;
     LoadManager loadManager;
     MainScene scene;
 };


#endif // BASECLASS_H
