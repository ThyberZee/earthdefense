#include "gameover.h"
#include "ui_gameover.h"

Gameover::Gameover(QWidget *parent, int score) :
    QMainWindow(parent),
    score(score),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
    ui->scoreDisplayLbl->setText(QString::number(score));

    QGridLayout* grid = ui->gridLayout;

    for(size_t i = 0; i < HighScore::getInstance()->getScores().size();i++){
        Score &score = HighScore::getInstance()->getScores().at(i);
        QLabel* initLbl = new QLabel(this);
        QLabel* scoreLbl = new QLabel(this);

        initLbl->setText(QString::fromStdString(score.getInitials()));
        scoreLbl->setText(QString::number(score.getValue()));

        initLbl->setAttribute(Qt::WA_TranslucentBackground, true);
        scoreLbl->setAttribute(Qt::WA_TranslucentBackground, true);

        grid->addWidget(initLbl,i+2,0);
        grid->addWidget(scoreLbl,i+2,1);

    }

}

void Gameover::on_lineEdit_returnPressed()
{
    string initials = ui->lineEdit->text().toStdString();   //get text
    initials = initials.substr(0,initials.find(' '));       //truncate at space
    HighScore::getInstance()->addScore(score,initials);     //store text
    HighScore::getInstance()->save();                       //save scores
    MainWindow* gameWindow = new MainWindow(this);
    gameWindow->show();
    gameWindow->setEnabled(true);

    QApplication::quit();
}

Gameover::~Gameover()
{
    delete ui;
}


