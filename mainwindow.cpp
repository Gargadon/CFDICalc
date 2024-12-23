#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "acerca.h"
#include <QFileDialog>
#include <QDomDocument>
#include <QFile>
#include <QClipboard>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupFilterMenu();
    resetTotals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetTotals()
{
    cfdiTotals.clear();
    // Inicializar todas las categorías conocidas
    const QStringList categories = {
        "G01", "G02", "G03",
        "I01", "I02", "I03", "I04", "I05", "I06", "I07", "I08",
        "D01", "D02", "D03", "D04", "D05", "D06", "D07", "D08", "D09", "D10",
        "S01",
        "CP01", "CN01"
    };

    for (const auto& category : categories) {
        cfdiTotals[category] = CFDIData();
    }
    cfdiTotals["TOTAL"] = CFDIData(); // Para el total general
}

void MainWindow::processCFDIFile(const QString& filename)
{
    QDomDocument xmlDoc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se puede abrir el archivo:" << filename;
        return;
    }

    if (!xmlDoc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomElement root = xmlDoc.documentElement();
    if (root.tagName() != "cfdi:Comprobante") {
        return;
    }

    float totalCFDI = root.attribute("Total", "0.00").toFloat();
    float subCFDI = root.attribute("SubTotal", "0.00").toFloat();

    // Obtener UsoCFDI
    QString usoCFDI = ""; // Valor por defecto
    auto receptorNodes = root.elementsByTagName("cfdi:Receptor");
    if (receptorNodes.count() > 0) {
        QDomElement receptor = receptorNodes.at(0).toElement();
        usoCFDI = receptor.attribute("UsoCFDI", "");
    }

    // Actualizar totales
    cfdiTotals[usoCFDI].total += totalCFDI;
    cfdiTotals[usoCFDI].subtotal += subCFDI;
    cfdiTotals["TOTAL"].total += totalCFDI;
    cfdiTotals["TOTAL"].subtotal += subCFDI;
}

void MainWindow::on_actionAbrir_CFDI_triggered()
{
    resetTotals();

    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QStringList filenames = QFileDialog::getOpenFileNames(
        this,
        tr("Seleccionar archivos"),
        initialPath,
        tr("XML (*.xml)")
        );

    if (filenames.isEmpty()) {
        return;
    }

    for (const auto& filename : filenames) {
        processCFDIFile(filename);
    }

    updateDisplay("TOTAL");
}

void MainWindow::updateDisplayValues(float total, float subtotal)
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();

    QLocale mexico(QLocale::Spanish, QLocale::Mexico);

    // Formato con 2 decimales, símbolo de peso y separadores de miles
    QString totalStr = "$ " + mexico.toString(total, 'f', 2);
    QString subtotalStr = "$ " + mexico.toString(subtotal, 'f', 2);

    ui->totalDisplay->insert(totalStr);
    ui->subtotalDisplay->insert(subtotalStr);
}

void MainWindow::updateDisplay(const QString& usoCFDI)
{
    auto it = cfdiTotals.find(usoCFDI);
    if (it != cfdiTotals.end()) {
        updateDisplayValues(it->second.total, it->second.subtotal);
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    Acerca acerca;
    acerca.setModal(true);
    acerca.exec();
}

void MainWindow::on_actionCFDI_triggered()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action) {
        QString usoCFDI = action->property("UsoCFDI").toString();
        updateDisplay(usoCFDI);
    }
}

void MainWindow::setupFilterMenu()
{
    menuFiltrar = findChild<QMenu*>("menuFiltrar");
    if (menuFiltrar) {
        QList<QAction*> actions = menuFiltrar->actions();
        for(QAction* action : actions) {
            if(action->property("UsoCFDI").isValid()) {
                connect(action, &QAction::triggered, this, &MainWindow::on_actionCFDI_triggered);
            }
        }
    }
}

void MainWindow::on_copyTotal_clicked()
{
    // Obtener el texto del totalDisplay
    QString displayText = ui->totalDisplay->text();
    
    // Eliminar el símbolo de peso y espacios
    displayText.remove("$").remove(" ");
    
    // Convertir las comas a punto decimal si es necesario
    displayText.replace(",", "");
    
    // Copiar al portapapeles
    QApplication::clipboard()->setText(displayText);
}


void MainWindow::on_copySubtotal_clicked()
{
    // Obtener el texto del subtotalDisplay
    QString displayText = ui->subtotalDisplay->text();

    // Eliminar el símbolo de peso y espacios
    displayText.remove("$").remove(" ");

    // Convertir las comas a punto decimal si es necesario
    displayText.replace(",", "");

    // Copiar al portapapeles
    QApplication::clipboard()->setText(displayText);
}

