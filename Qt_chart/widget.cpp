#include "widget.h"

#include <QDebug>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtCharts>
#include <QGridLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_dataTable(generateRandomData(3, 10, 7))
{
    resize(300, 300);

    m_label = new QLabel( tr("示例表格"), this );
    m_comboBox = new QComboBox( this );

    m_comboBox->addItem("Ice cold", "csIce");
    m_comboBox->addItem("Dark", "csDark");
    m_comboBox->addItem("Qt", "csQt");

    QGridLayout *gridLayout = new QGridLayout( this );
    QHBoxLayout *lineLayout = new QHBoxLayout( this );

    //gridLayout->addWidget( m_label, 0, 0 );
    //gridLayout->addWidget( m_comboBox, 0, 1 );
    lineLayout->addWidget( m_label );
    lineLayout->addWidget( m_comboBox );
    lineLayout->addStretch();

    gridLayout->addLayout( lineLayout, 0, 0 );
    //什么时候可以不用delete对象。
    //Qt具有半自动内存管理机制，
    //必须是QObject或其派生类的对象，并指定了父窗口（父子关系）。
    QChartView *chartView;

    chartView = new QChartView( createLineChart() );
    //gridLayout->addWidget(chartView, 1, 0, 1, 2 );
    gridLayout->addWidget( chartView, 1, 0 );


    setLayout( gridLayout );

    QPalette pal = qApp->palette();
    //pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
    //pal.setColor(QPalette::WindowText, QRgb(0x404044));
    pal.setColor(QPalette::Window, QRgb(0x121218));
    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    qApp->setPalette(pal);

    connect( m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI()) );
}

Widget::~Widget()
{

}

DataTable Widget::generateRandomData(int listCount, int valueMax, int valueCount)
{
    DataTable DataTable;
    for( int i(0); i < listCount; ++i )
    {
        DataList DataList;
        qreal yValue(0);

        for( int j(0); j < valueCount; ++j )
        {
            yValue = yValue + QRandomGenerator::global()->bounded( valueMax/(qreal)listCount );
            QPointF value((j+QRandomGenerator::global()->generateDouble())*valueMax/listCount,
                          yValue);
            QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
            DataList << Data( value, label );
            //qDebug( "%f, %f\n", yValue, generData );
        }
        DataTable << DataList;
    }
    return DataTable;
}

QChart *Widget::createLineChart() const
{
    QChart *chart = new QChart();
    chart->setTitle("Line chart");

    int nameIndex = 0;
    for(const DataList &list : m_dataTable)
    {
        QLineSeries *series = new QLineSeries(chart);
        for(const Data &data : list)
        {
            series->append(data.first);
        }
        series->setName("Series"+ QString::number(nameIndex));
        ++nameIndex;
        chart->addSeries(series);
    }

    chart->createDefaultAxes();
  //  chart->axisX()->setRange(0, 10);
  //  chart->axisY()->setRange(0, 7);

    static_cast<QValueAxis *>(chart->axisY())->setLabelFormat("%.1f  ");

    return chart;
}

void Widget::updateUI()
{
    QString comStr = m_comboBox->itemData( m_comboBox->currentIndex() ).toString();
    //qDebug("select %s", comStr.data());
    QPalette pal = window()->palette();

    if( comStr == "csIce" )
    {
        pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if( comStr == "csDark" )
    {
        pal.setColor(QPalette::Window, QRgb(0xcee7f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if( comStr == "csQt")
    {
        pal.setColor(QPalette::Window, QRgb(0x40434a));
        pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    }
    qApp->setPalette(pal);
}
