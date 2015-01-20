#include "widget.h"
#include <QApplication>
#include <QtSerialPort/QSerialPortInfo>
#include <QVBoxLayout>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QObject::tr("Info about all available serial ports."));

    QVBoxLayout *layout = new QVBoxLayout;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
           QString s = QObject::tr("Port: ") + info.portName() + "\n"
                       + QObject::tr("Location: ") + info.systemLocation() + "\n"
                       + QObject::tr("Description: ") + info.description() + "\n"
                       + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                       + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                       + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                       + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                       + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

           QLabel *label = new QLabel(s);
           layout->addWidget(label);
       }

    w.setLayout(layout);
    w.show();

    return a.exec();
}
