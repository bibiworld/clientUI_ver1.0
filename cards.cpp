#include "cards.h"
#include <QHBoxLayout>
#include <QListView>
#include <QAction>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QList>
#include <QStringList>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QFile>
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QPageLayout>

Cards::Cards(MainWindow* p) : parent(p)
{
    del = new QPushButton(parent);
    pri = new QPushButton(parent);
    del->setText("Delete");
    pri->setText("Print");
    del->setGeometry(275, 150, 100, 30);
    del->show();
    connect(del, SIGNAL(clicked(bool)), this, SLOT(remove()));
    pri->setGeometry(275, 200, 100, 30);
    pri->show();
    connect(pri, SIGNAL(clicked(bool)), this, SLOT(printPdf()));
    for(int i = 0; i < 20; ++i) {
        parent->eng.push_back(QString::number(i));
        parent->chi.push_back(QString::number(i));
    }
    list = new QListWidget(parent);
    list->setGeometry(50, 50, 200, 200);
    for(int i = 0; i < (int)parent->eng.size(); ++i) {
        QListWidgetItem* item = new QListWidgetItem(parent->eng[i] + " " + parent->chi[i]);
        list->addItem(item);
    }
    list->setAlternatingRowColors(1);
    list->setSelectionMode(QAbstractItemView::MultiSelection);
    list->show();
}

Cards::~Cards() {
    if(list) delete list;
    if(del) delete del;
    if(pri) delete pri;
}

void Cards::remove() {
    QList<QListWidgetItem*> items = list->selectedItems();
    if(items.size() == 0) return;
    int ret = QMessageBox::warning(0, "", "Do you really want to delete these cards?", QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes) {
        for(int i = 0; i < (int)items.size(); ++i) {
            int j = list->row(items[i]);
            qDebug() << "row =" << j;
            parent->eng.erase(parent->eng.begin() + j);
            parent->chi.erase(parent->chi.begin() + j);
            qDebug() << "number = " << parent->eng.size();
            //list->removeItemWidget(items[i]);
            //list->show();
            list->takeItem(j);
        }
    }
}

void Cards::printPdf() {
    print(parent->eng, parent->chi);
}

void Cards::print(vector<QString>& eng, vector<QString>& chi/*, QPdfWriter *pdf_writer, QPainter *pdf_painter*/) {
    if(eng.size() == 0) return;
    QFile pdf_file("QPdfWriter.pdf");
    pdf_file.open(QIODevice::WriteOnly);
    QPdfWriter *pdf_writer = new QPdfWriter(&pdf_file);
    QPainter *pdf_painter= new QPainter(pdf_writer);
    pdf_writer->setPageSize(QPagedPaintDevice::A4);

    int line = 6;
    int col = 3;
    int wid = pdf_writer->width() / 3;
    int height = pdf_writer->height() / 6;
    int pages = eng.size() / (line * col);
    //qDebug() << pages;
    qDebug() << eng.size();
    int left = eng.size() % (line * col);
    qDebug() << "left = " << left;
    if(left > 0) {
        pages++;
        //qDebug() << "++";
    }
    qDebug() << pages;
    int sup = line*col - left;
    vector<QString> Eng = eng;
    vector<QString> Chi = chi;
    for(int i = 0; i < sup; ++i) {
        Chi.push_back("");
        Eng.push_back("");
    }
    drawLines(pdf_painter);
    int counter = 0;
    int counter2 = 2;
    for(int i = 0; i < pages; ++i) {
        for(int j = 0; j < line; ++j) {
            pdf_painter->save();
            pdf_painter->translate(0, j * height);
            for(int k = 0; k < col; ++k) {
                QFont font;
                font.setBold(1);
                if(Eng[counter].length() > 10) {
                    font.setPointSize(20);
                }else {
                    font.setPointSize(30);
                }
                pdf_painter->setFont(font);
                pdf_painter->drawText(QRect(0, 0, wid, height), Qt::AlignHCenter | Qt::AlignVCenter, Eng[counter]);
                ++counter;
                pdf_painter->translate(wid, 0);
            }
            pdf_painter->restore();
        }
        pdf_writer->newPage();
        drawLines(pdf_painter);
        for(int j = 0; j < line; ++j) {
            pdf_painter->save();
            pdf_painter->translate(0, j * height);
            for(int k = 0; k < col; ++k) {
                QFont font;
                if(Eng[counter2 - k].length() > 10) {
                    font.setPointSize(20);
                }else {
                    font.setPointSize(30);
                }
                pdf_painter->setFont(font);
                pdf_painter->drawText(QRect(0, 0, wid, height), Qt::AlignHCenter | Qt::AlignVCenter, Chi[counter2 - k]);
                pdf_painter->translate(wid, 0);
            }
            pdf_painter->restore();
            counter2 += 3;
        }
        if(i != pages-1) {
            pdf_writer->newPage();
            drawLines(pdf_painter);
        }
    }
    qDebug() << wid;
    qDebug() << height;

    delete pdf_painter;
    delete pdf_writer;
    pdf_file.close();
    int ret = QMessageBox::information(0, "Finished!", "All cards have been printed! Do you want to clear them?", QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes) {
        eng.clear();
        chi.clear();
        list->clear();
    }
}

void Cards::drawLines(QPainter* pdf_painter) {
    int wid = 9583;
    int height = 13699;
    int times = 3;
    int times2 = 6;
    wid /= times;
    height /= times2;
    pdf_painter->setPen(Qt::DashDotLine);
    for(int i = 1; i < times2; ++i) {
        pdf_painter->drawLine(0, height * i, 9583, height * i);
    }
    for(int i = 1; i < times; ++i) {
        pdf_painter->drawLine(wid * i, 0, wid * i, 13699);
    }
}
