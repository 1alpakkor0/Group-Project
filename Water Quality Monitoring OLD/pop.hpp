#ifndef POP_H
#define POP_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QtCharts/QValueAxis>
#include <QGridLayout>
#include <QTimer>
#include <QStackedWidget>
#include <QtCharts/QChartView>
#include <QLabel>
#include <qpushbutton.h>
#include "datamanager.hpp"
#include "fluorinatedcompounds.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadPopData();
    void updatePopPage();
    void switchPage();

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QGridLayout *popLayout;
    DataManager dataManager;
    QGridLayout *fluorLayout;
    QStackedWidget *stackedWidget;
    QPushButton *switchButton;
    FluorinatedCompounds *fluorPage;

    QWidget* createPopWidget(const QString &name, const QVector<double> &data, bool compliant);
    void setupChart(QChartView *chartView, const QVector<double> &data);
};

#endif // POP_H