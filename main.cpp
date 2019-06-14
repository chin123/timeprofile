#include <QApplication>
#include <QFontDatabase>
#include <QWidget>
#include <vector>
#include <string>
#include <unordered_map>

#include "timeprofile.h"
#include "qcustomplot.h"
#include "creategraph.h"
#include "stsreader/sts.cpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // set dark background gradient:
  QCustomPlot *customPlot = new QCustomPlot;
  /*QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  customPlot->setBackground(QBrush(gradient));*/
   
  std::cout << "getting times" << std::endl;
  auto methodTimes = getTimes(std::stoi(argv[1]));
  std::cout << "done" << std::endl;
  auto idtomethod = idMap(argv[2]);
  
  QVector<double> ticks;
  QVector<QString> labels;
  std::cout << "Adding ticks and labels" << std::endl;
  for (int i = 1; i <= methodTimes.begin()->second.size(); i++) {
	  ticks << i;
	  labels << std::to_string(i).c_str();
  }
  std::cout << "done" << std::endl;

  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  customPlot->xAxis->setTicker(textTicker);
  //customPlot->xAxis->setTickLabelRotation(60);
  customPlot->xAxis->setSubTicks(false);
  //customPlot->xAxis->setTickLength(0, 4);
  //customPlot->xAxis->setRange(0, 8);
  customPlot->xAxis->setBasePen(QPen(Qt::white));
  customPlot->xAxis->setTickPen(QPen(Qt::white));
  //customPlot->xAxis->grid()->setVisible(true);
  //customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  customPlot->xAxis->setTickLabelColor(Qt::white);
  customPlot->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  //customPlot->yAxis->setRange(0, 400);
  //customPlot->yAxis->setPadding(5); // a bit more space to the left border
  customPlot->yAxis->setLabel("Time taken in microseconds");
  customPlot->yAxis->setBasePen(QPen(Qt::white));
  customPlot->yAxis->setTickPen(QPen(Qt::white));
  customPlot->yAxis->setSubTickPen(QPen(Qt::white));
  //customPlot->yAxis->grid()->setSubGridVisible(true);
  customPlot->yAxis->setTickLabelColor(Qt::white);
  customPlot->yAxis->setLabelColor(Qt::white);
  //customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  //customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  QCPBars *prev = nullptr;
  int count = 0;
  std::cout << "Adding bars" << std::endl;
  for (auto kv: methodTimes) {
    QCPBars *mdata = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    mdata->setAntialiased(false);
    mdata->setStackingGap(1);
    QPen qp(QColor((20+count) % 255, (20 + count*2) % 255, (20 + count*10) % 255).lighter(150));
    mdata->setPen(qp);
    mdata->setBrush(QColor((20+count) % 255, (20 + count*2) % 255, (20 + count*10) % 255));
    if (prev != nullptr) {
      mdata->moveAbove(prev);
    }
    prev = mdata;
    QVector<double> mtimes;
    for (int time: kv.second) {
      mtimes << time;
    }
    mdata->setData(ticks, mtimes);
    mdata->setName((idtomethod[kv.first].substr(0,20) + "...").c_str());
    count+=10;
  }
  std::cout << "done" << std::endl;


  // setup legend:
  customPlot->legend->setVisible(true);
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
  customPlot->legend->setBrush(QColor(255, 255, 255, 100));
  customPlot->legend->setBorderPen(Qt::NoPen);
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

  customPlot->show();

  return app.exec();
}
