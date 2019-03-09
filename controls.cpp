#include "controls.h"

Controls::Controls(QWidget *parent, Automata *automata, GLWidget *canvas) : QWidget(parent), automata(automata), canvas(canvas)
{
    this->iteration = 0;

    this->layout = new QGridLayout(this);
    this->layout->setGeometry(this->geometry());

    this->startButton = new QPushButton("Start", this);
    connect(this->startButton, SIGNAL(clicked()), this, SLOT(changeButtonText()));
    this->layout->addWidget(this->startButton, 0, 0, 1, 2);

    this->seedLabel = new QLabel("Seed: ", this);
    this->layout->addWidget(this->seedLabel, 1, 0);

    this->pollSeed();
    QString initSeed = QString::number(this->seed);
    this->seedTextBox = new QLineEdit(initSeed);
    connect(this->seedTextBox, SIGNAL(textChanged(const QString &)), this, SLOT(updateSeed(const QString &)));
    this->layout->addWidget(this->seedTextBox, 1, 1);

    this->randomSeed = new QPushButton("Random seed", this);
    connect(this->randomSeed, SIGNAL(clicked()), this, SLOT(updateSeedTextBox()));
    this->layout->addWidget(this->randomSeed, 2, 0, 1, 2);

    this->resolutionLabel = new QLabel("Resolution: ", this);
    this->layout->addWidget(this->resolutionLabel, 3, 0);

    QString res = QString::number(this->automata->getnCells());
    this->resolutionTextBox = new QLineEdit(res);
    this->layout->addWidget(this->resolutionTextBox, 3, 1);

    this->resolutionScrollBar = new QScrollBar(Qt::Horizontal, this);
    this->resolutionScrollBar->setRange(5, 1000);
    this->resolutionScrollBar->setValue(this->automata->getnCells());
    connect(this->resolutionScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateResolutionTextBox(int)));
    connect(this->resolutionTextBox, SIGNAL(textChanged(const QString &)), this, SLOT(updateResolutionScrollBar(const QString &)));
    this->layout->addWidget(this->resolutionScrollBar, 4, 0, 1, 2);

    this->iterationLabel = new QLabel("Iteration: ", this);
    this->layout->addWidget(this->iterationLabel, 5, 0);

    QString initIter = QString::number(this->iteration);
    this->iterationTextBox = new QLineEdit(initIter);
    connect(this->iterationTextBox, SIGNAL(textChanged(const QString &)), this, SLOT(updateIteration(const QString &)));
    this->layout->addWidget(this->iterationTextBox, 5, 1);

    this->timer = new QTimer(this->canvas);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(changeCanvas()));
}

void Controls::changeButtonText()
{
    if(this->startButton->text() == "Start")
    {
        this->disableControls();
        this->changeCanvas();
        this->startButton->setText("Stop");
        this->timer->start(1000);
    }
    else
    {
        this->enableControls();
        this->startButton->setText("Start");
        this->timer->stop();
    }
}

void Controls::changeCanvas()
{
    this->automata->randomize(this->seed);
    this->canvas->update();
    this->iteration++;
    this->iterationTextBox->setText(QString::number(this->iteration));
}

void Controls::pollSeed()
{
    auto seed = std::bind(std::uniform_int_distribution<long>(std::numeric_limits<long>::min(), std::numeric_limits<long>::max()), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    this->seed = seed();
}

void Controls::disableControls()
{
    this->seedTextBox->setDisabled(true);
    this->randomSeed->setDisabled(true);
    this->resolutionTextBox->setDisabled(true);
    this->resolutionScrollBar->setDisabled(true);
}

void Controls::enableControls()
{
    this->seedTextBox->setEnabled(true);
    this->randomSeed->setEnabled(true);
    this->resolutionTextBox->setEnabled(true);
    this->resolutionScrollBar->setEnabled(true);
}

void Controls::updateResolutionTextBox(int value)
{
    this->automata->setNCells(value, true, this->seed);
    this->canvas->update();
    QString tmp = QString::number(value);
    this->resolutionTextBox->setText(tmp);
    this->iteration = 0;
}

void Controls::updateResolutionScrollBar(const QString &value)
{
    unsigned int tmp = value.toUInt();
    this->automata->setNCells(tmp, true, this->seed);
    this->canvas->update();
    this->resolutionScrollBar->setValue(tmp);
    this->iteration = 0;
}

void Controls::updateSeedTextBox()
{
    this->pollSeed();
    QString seed = QString::number(this->seed);
    this->seedTextBox->setText(seed);
    this->iteration = 0;
}

void Controls::updateSeed(const QString &value)
{
    this->seed = value.toInt();
    this->iteration = 0;
}

void Controls::updateIteration(const QString &value)
{
   this->iteration = value.toULongLong();
}

void Controls::show()
{

}

Controls::~Controls()
{
    delete this->startButton;
    delete this->timer;
}
