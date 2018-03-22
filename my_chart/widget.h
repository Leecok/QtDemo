/**************************************************
-   Copyright (C), 2018-2019, LeeCok
-
-
-
-
-
-
-*************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTabel;

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //成员函数
    /*************************************
     * Function : generateRandomData
     * Description : 随机生成DataTabel的数据
     * Author : leeCok
     * Data : 2018/03/17
     *
     * Input : listCount
     * Output :
     * Return :
     * Others :
     * ***********************************/
    DataTabel generateRandomData(int listCount, int maxValue, int listValue);

    QChart *createLineChart() const;

private:
    DataTabel m_dataTabel;
    int m_listCount;
    int m_maxValue;
    int m_listValue;
};

#endif // WIDGET_H
