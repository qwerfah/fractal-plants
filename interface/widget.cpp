#include "widget.h"
#include "ui_widget.h"
#include "command/translatecommand.h"
#include "command/scalecommand.h"
#include "command/generatecommand.h"
#include "command/rotatecommand.h"
#include "command/drawcommand.h"
#include "command/loadcommand.h"
#include "generator/fractalplantgenerateoptions.h"
#include "light/pointlight.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    graphicsView.setScene(baseClass.getScene().getRawScene());
    graphicsView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gridLayout->addWidget(&graphicsView);
    // Connect buttons
    connect(this->ui->Rotate_btn, &QPushButton::clicked, this, &Widget::onRotateBtnClicked);
    connect(this->ui->Translate_btn, &QPushButton::clicked, this, &Widget::onTranslateBtnClicked);
    connect(this->ui->Scale_btn, &QPushButton::clicked, this, &Widget::onScaleBtnClicked);
    connect(this->ui->Generate_btn, &QPushButton::clicked, this, &Widget::onGenerateBtnClicked);
    connect(this->ui->Clear_btn, &QPushButton::clicked, this, &Widget::onClearBtnClicked);
    //connect(this->ui->Load_btn, &QPushButton::clicked, this, &Widget::onLoadBtnClicked);
    connect(this->ui->addButton, &QPushButton::clicked, this, &Widget::onRuleAdded);
    connect(this->ui->removeButton, &QPushButton::clicked, this, &Widget::onRuleDeleted);
    // Connect sliders
    connect(this->ui->horizontalSlider, &QSlider::valueChanged,
            this, &Widget::onXSliderValueChanged);
    connect(this->ui->horizontalSlider_2, &QSlider::valueChanged,
            this, &Widget::onYSliderValueChanged);
    connect(this->ui->horizontalSlider_3, &QSlider::valueChanged,
            this, &Widget::onZSliderValueChanged);
    // Connect spinboxes
    connect(this->ui->LCr, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LCg, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LCb, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LPx, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LPy, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LPz, qOverload<int>(&QSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    connect(this->ui->LIntensity, qOverload<double>(&QDoubleSpinBox::valueChanged),
            this, &Widget::onLightChanged);
    // Connect comboBoxes
    connect(this->ui->patternComboBox, qOverload<int>(&QComboBox::currentIndexChanged),
            this, &Widget::onPatternChanged);

    baseClass.getScene().setColor(QColor(255, 255, 255));
    baseClass.getScene().setFillColor(QColor(255, 255, 255));

    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertRow(0);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList("Правила вывода"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setBaseClass(BaseClass &_baseClass)
{
    baseClass = _baseClass;
    graphicsView.setScene(baseClass.getScene().getRawScene());
    baseClass.getDrawManager().getScene().setLight(new PointLight(QColor(255, 255, 255),
                                                                  Point3d(0, 1000, 1000),
                                                                  1));
}

void Widget::onTranslateBtnClicked()
{
    std::vector<Command*> commands({new TranslateCommand(baseClass,
                                    (double)ui->doubleSpinBox->value(),
                                    (double)ui->doubleSpinBox_2->value(),
                                    (double)ui->doubleSpinBox_3->value()),
                                    new DrawCommand(baseClass)});
    for (auto& command : commands)
    {
        command->execute();
        delete command;
    }
}

void Widget::onRotateBtnClicked()
{
    std::vector<Command*> commands({new RotateCommand(baseClass,
                                    (Axis)ui->comboBox->currentIndex(),
                                    (double)ui->doubleSpinBox_7->value() * TO_RADIANS),
                                    new DrawCommand(baseClass)});
    for (auto& command : commands)
    {
        command->execute();
        delete command;
    }
}

void Widget::onXSliderValueChanged()
{
    int old = ui->doubleSpinBox_7->value();
    ui->comboBox->setCurrentIndex(Axis::X);
    ui->doubleSpinBox_7->setValue(ui->horizontalSlider->value() - sliderX);
    onRotateBtnClicked();
    sliderX = ui->horizontalSlider->value();
    ui->doubleSpinBox_7->setValue(old);
}

void Widget::onYSliderValueChanged()
{
    int old = ui->doubleSpinBox_7->value();
    ui->comboBox->setCurrentIndex(Axis::Y);
    ui->doubleSpinBox_7->setValue(ui->horizontalSlider_2->value() - sliderY);
    onRotateBtnClicked();
    sliderY = ui->horizontalSlider_2->value();
    ui->doubleSpinBox_7->setValue(old);
}

void Widget::onZSliderValueChanged()
{
    int old = ui->doubleSpinBox_7->value();
    ui->comboBox->setCurrentIndex(Axis::Z);
    ui->doubleSpinBox_7->setValue(ui->horizontalSlider_3->value() - sliderZ);
    onRotateBtnClicked();
    sliderZ = ui->horizontalSlider_3->value();
    ui->doubleSpinBox_7->setValue(old);
}

void Widget::onLightChanged()
{
    QColor color(ui->LCr->value(), ui->LCg->value(), ui->LCb->value());
    Point3d position(ui->LPx->value(), ui->LPy->value(), ui->LPz->value());
    double intensity = ui->LIntensity->value();
    PointLight* light = new PointLight(color, position, intensity);

    baseClass.getDrawManager().getScene().setLight(light);

    auto command = new DrawCommand(baseClass);
    command->execute();
    delete command;
}

void Widget::onRuleAdded()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Widget::onRuleDeleted()
{
    if (ui->tableWidget->rowCount() > 1)
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount() - 1);
    }
}

void Widget::onPatternChanged()
{
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }
    ui->axiomEdit->clear();

    switch (ui->patternComboBox->currentIndex())
    {
    case USER:
        break;

    case TREE1:
        for (int i = 0; i < 4; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        }
        ui->tableWidget->item(0, 0)->setText
                ("A = [++BB[--C][++C][__C][^^C]A]/////+BBB[--C][++C][__C][^^C]A");
        ui->tableWidget->item(1, 0)->setText
                ("B = \\B");
        ui->tableWidget->item(2, 0)->setText
                ("B = B");
        ui->tableWidget->item(3, 0)->setText
                ("C =");
        ui->axiomEdit->setText("BBBBBA");
        ui->doubleSpinBox_11->setValue(13);
        ui->doubleSpinBox_12->setValue(13);
        ui->doubleSpinBox_13->setValue(13);
        ui->spinBox_14->setValue(5);
        break;

    case TREE2:
        for (int i = 0; i < 3; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        }
        ui->tableWidget->item(0, 0)->setText
                ("A = B[+A]\\\\[+A]\\\\[+A]\\\\BA");
        ui->tableWidget->item(1, 0)->setText
                ("B = BB");
        ui->tableWidget->item(2, 0)->setText
                ("B = A/B");
        ui->axiomEdit->setText("A");
        ui->doubleSpinBox_11->setValue(30);
        ui->doubleSpinBox_12->setValue(30);
        ui->doubleSpinBox_13->setValue(30);
        ui->spinBox_14->setValue(4);
        break;

    case TREE3:
        for (int i = 0; i < 3; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        }
        ui->tableWidget->item(0, 0)->setText
                ("A=A[+A]BA[-A]");
        ui->tableWidget->item(1, 0)->setText
                ("BA=BBA");
        ui->tableWidget->item(2, 0)->setText
                ("BB=BBB");
        ui->axiomEdit->setText("A");
        ui->doubleSpinBox_11->setValue(33);
        ui->doubleSpinBox_12->setValue(33);
        ui->doubleSpinBox_13->setValue(33);
        ui->spinBox_14->setValue(8);
        break;

    case FERN:
        for (int i = 0; i < 3; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        }
        ui->tableWidget->item(0, 0)->setText
                ("A = [++++++++++++++EC]B^+B[--------------ED]B+BA");
        ui->tableWidget->item(1, 0)->setText
                ("C =[---------EE][+++++++++EE]B__+C");
        ui->tableWidget->item(2, 0)->setText
                ("D = [---------EE][+++++++++EE]B__-D");
        ui->axiomEdit->setText("EEEA");
        ui->doubleSpinBox_11->setValue(4);
        ui->doubleSpinBox_12->setValue(4);
        ui->doubleSpinBox_13->setValue(4);
        ui->spinBox_14->setValue(12);
        break;
    }
}

void Widget::onScaleBtnClicked()
{
    std::vector<Command*> commands({new ScaleCommand(baseClass, (double)ui->doubleSpinBox_4->value(),
                                                                (double)ui->doubleSpinBox_5->value(),
                                                                (double)ui->doubleSpinBox_6->value()),
                                    new DrawCommand(baseClass)});
    for (auto& command : commands)
    {
        command->execute();
        delete command;
    }
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

void Widget::onGenerateBtnClicked()
{
    bool flag = false;
    std::vector<Rule> rules;

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i, 0);
        if (item)
        {
            if (item->text() == "")
            {
                flag = false;
            }
            else
            {
                rules.push_back(Rule(item->text().toStdString()));
                flag = true;
            }
        }
    }

    if (!flag)
    {
        QMessageBox::warning(this, "Ошибка", "Generating: no rules in list");
        return;
    }

    DrawMode mode = ui->checkBox->isChecked() ? FILL : CARCASS;
    FractalPlantGenerateOptions* options =
            new FractalPlantGenerateOptions(ui->spinBox_14->value(),
                                            rules,
                                            ui->axiomEdit->text().toStdString(),
                                            ui->constantsEdit->text().toStdString(),
                                            Point3d(ui->doubleSpinBox_8->value(),
                                                    ui->doubleSpinBox_9->value(),
                                                    ui->doubleSpinBox_10->value()),
                                            ui->doubleSpinBox_11->value(),
                                            ui->doubleSpinBox_12->value(),
                                            ui->doubleSpinBox_13->value(),
                                            QColor(ui->bR->value(), ui->bG->value(), ui->bB->value()),
                                            QColor(ui->fR->value(), ui->fG->value(), ui->fB->value()),
                                            ui->doubleSpinBox_14->value(),
                                            ui->doubleSpinBox_15->value(),
                                            mode);

    std::vector<Command*> commands({new GenerateCommand(baseClass, FRACTALPLANTGENERATOR, options),
                                    new DrawCommand(baseClass)});
    size_t tb, te;
    tb = tick();
    for (auto& command : commands)
    {  
        try
        {
            command->execute();
        }
        catch (BadStream &e)
        {
            QMessageBox::warning(this, "Ошибка", e.what());
        }
        catch (CorruptedData &e)
        {
            QMessageBox::warning(this, "Ошибка", e.what());
        }
        delete command;
    }
    te = tick();
    qInfo() << te - tb;
}

void Widget::onLoadBtnClicked()
{
    std::vector<Command*> commands({new LoadCommand(baseClass, ""/*ui->lineEdit->text()*/),
                                    new DrawCommand(baseClass)});
    QColor clr = baseClass.getDrawManager().getScene().getPen().color();
    QColor fclr = baseClass.getDrawManager().getScene().getBrush().color();

    baseClass.getDrawManager().getScene().setColor
            (QColor(ui->bR->value(), ui->bG->value(), ui->bB->value()));
    baseClass.getDrawManager().getScene().setFillColor
            (QColor(ui->fR->value(), ui->fG->value(), ui->fB->value()));

    for (auto& command : commands)
    {
        try
        {
            command->execute();
        }
        catch (BadStream &e)
        {
            qInfo() << e.what();
        }
        catch (CorruptedData &e)
        {
            qInfo() << e.what();
        }
        catch(WrongObjectType &e)
        {
            qInfo() << e.what();
        }
        delete command;
    }

    baseClass.getDrawManager().getScene().setColor(clr);
    baseClass.getDrawManager().getScene().setFillColor(fclr);
}

void Widget::onClearBtnClicked()
{
    while (baseClass.getMainScene().begin() != baseClass.getMainScene().end())
    {
        baseClass.getMainScene().shrink();
    }
    baseClass.getDrawManager().clear();
}
