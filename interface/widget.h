#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QGraphicsView>
#include "baseclass.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void setBaseClass(BaseClass &_baseClass);

private:
    Ui::Widget *ui;
    BaseClass baseClass;
    QGraphicsView graphicsView;
    int sliderX = 0, sliderY = 0, sliderZ = 0;

private slots:
    void onTranslateBtnClicked();
    void onRotateBtnClicked();
    void onScaleBtnClicked();
    void onGenerateBtnClicked();
    void onClearBtnClicked();
    void onLoadBtnClicked();

    void onXSliderValueChanged();
    void onYSliderValueChanged();
    void onZSliderValueChanged();
    void onLightChanged();

    void onRuleAdded();
    void onRuleDeleted();
    void onPatternChanged();
};

#endif // WIDGET_H
