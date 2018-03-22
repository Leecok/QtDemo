#include "widget.h"

#include <QtWidgets/QWidget>
#include <QRandomGenerator>
//#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_listCount(3),
      m_listValue(7),
      m_maxValue(10),
      m_dataTabel(generateRandomData(3, 10, 7))
{
    QGridLayout *mainLayout = new QGridLayout( this );

    QChartView *chartView = new QChartView( createLineChart() );

    mainLayout->addWidget( chartView );

    setLayout( mainLayout );
}

Widget::~Widget()
{

}

DataTabel Widget::generateRandomData(int listCount, int maxValue, int listValue)
{
    DataTabel dataTabel;
    for(int i(0); i<listCount; ++i)
    {
        DataList dataList;
        for(int j(0); j<listValue; ++j)
        {
            qreal valueY = j + QRandomGenerator::global()->bounded( maxValue/(qreal)listValue );
            QPointF value( j, valueY );
            QString label = "Slice" + QString::number(i) + QString::number(j);
            dataList << Data( value, label );
        }
        dataTabel << dataList;
    }
    return dataTabel;
}

QChart *Widget::createLineChart() const
{
    QChart *chart = new QChart();

    for( int i=0; i<m_listCount; ++i )
    {
        QLineSeries *series = new QLineSeries();
        DataList dataList = m_dataTabel.at(i);
        for( int j=0; j<m_listValue; ++j )
        {
            series->append( dataList.at(j).first );
        }
        series->setName("series " + QString::number(i));
        chart->addSeries( series );
    }
    chart->createDefaultAxes();

    return chart;
}

