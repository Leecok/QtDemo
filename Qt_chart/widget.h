#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_BEGIN_NAMESPACE
class QLabel;
class QComboBox;
QT_END_NAMESPACE


QT_CHARTS_BEGIN_NAMESPACE
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

typedef QPair<QPointF,QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    DataTable generateRandomData(int listCount, int valueMax, int valueCount);
    QChart *createLineChart() const;

private slots:
    void updateUI();

private:
    QLabel *m_label;
    QComboBox *m_comboBox;

    DataTable m_dataTable;
};

#endif // WIDGET_H
