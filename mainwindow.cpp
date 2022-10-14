#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "acerca.h"
#include <QFileDialog>
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_CFDI_triggered()
{
    // Workaround para reiniciar las variables globales
    total=0; totalg01=0; totalg02=0; totalg03=0; totali01=0; totali02=0;
    totali03=0; totali04=0; totali05=0; totali06=0; totali07=0; totali08=0;
    totald01=0; totald02=0; totald03=0; totald04=0; totald05=0; totald06=0;
    totald07=0; totald08=0; totald09=0; totald10=0; totalp01=0;
    subtotal=0; subtotalg01=0; subtotalg02=0; subtotalg03=0; subtotali01=0; subtotali02=0;
    subtotali03=0; subtotali04=0; subtotali05=0; subtotali06=0; subtotali07=0; subtotali08=0;
    subtotald01=0; subtotald02=0; subtotald03=0; subtotald04=0; subtotald05=0; subtotald06=0;
    subtotald07=0; subtotald08=0; subtotald09=0; subtotald10=0; subtotalp01=0;

    QString nombrearchivo, usocfdi;
    QStringList filename = QFileDialog::getOpenFileNames(this,tr("Seleccionar archivos"),
                                                       nombrearchivo.toUtf8(),
                                                       tr("XML (*.xml)"));
    QString salto = "\n";

       if(!filename.isEmpty()){
       for(auto &data :filename)
           nombrearchivo.append(data).append(salto);

       }
   QStringList archivo = nombrearchivo.split(QRegularExpression("[\n]"),Qt::SkipEmptyParts);
   int final = archivo.count();
   //int final2 = 0;
   float totalcfdi,subcfdi;
   for(int i=0;i<final;i++)
   {
       QDomDocument xmlBOM;
       QFile f(archivo[i]);
       if(!f.open(QIODevice::ReadOnly))
       {
           qDebug() << "El archivo no se puede abrir";
       }
       else{
       xmlBOM.setContent(&f);
       f.close();
       QDomElement root=xmlBOM.documentElement();
       QString Type=root.tagName();
       QString tipocfdi = Type.toStdString().c_str();
       totalcfdi = root.attribute("Total", "0.00").toFloat();
       subcfdi = root.attribute("SubTotal", "0.00").toFloat();
       auto nodos = root.elementsByTagName("cfdi:Receptor");
       for(int i=0; i<nodos.count(); i++)
                   {
                       QDomNode abc = nodos.at(i);
                       if(abc.isElement())
                       {
                           usocfdi = abc.toElement().attribute("UsoCFDI").toUtf8();
                       }
                   }
       if(tipocfdi == "cfdi:Comprobante")
       {
           total = total + totalcfdi;
           subtotal = subtotal + subcfdi;
           if(usocfdi == "G01")
           {
               totalg01 = totalg01 + totalcfdi;
               subtotalg01 = subtotalg01 + subcfdi;
           }
           else if(usocfdi == "G02")
           {
               totalg02 = totalg02 + totalcfdi;
               subtotalg02 = subtotalg02 + subcfdi;
           }
           else if(usocfdi == "G03")
           {
               totalg03 = totalg03 + totalcfdi;
               subtotalg03 = subtotalg03 + subcfdi;
           }
           else if(usocfdi == "I01")
           {
               totali01 = totali01 + totalcfdi;
               subtotali01 = subtotali01 + subcfdi;
           }
           else if(usocfdi == "I02")
           {
               totali02 = totali02 + totalcfdi;
               subtotali02 = subtotali02 + subcfdi;
           }
           else if(usocfdi == "I03")
           {
               totali02 = totali03 + totalcfdi;
               subtotali02 = subtotali03 + subcfdi;
           }
           else if(usocfdi == "I04")
           {
               totali02 = totali04 + totalcfdi;
               subtotali02 = subtotali04 + subcfdi;
           }
           else if(usocfdi == "I05")
           {
               totali02 = totali05 + totalcfdi;
               subtotali02 = subtotali05 + subcfdi;
           }
           else if(usocfdi == "I06")
           {
               totali02 = totali06 + totalcfdi;
               subtotali02 = subtotali06 + subcfdi;
           }
           else if(usocfdi == "I07")
           {
               totali02 = totali07 + totalcfdi;
               subtotali02 = subtotali07 + subcfdi;
           }
           else if(usocfdi == "I08")
           {
               totali02 = totali08 + totalcfdi;
               subtotali02 = subtotali08 + subcfdi;
           }
           else if(usocfdi == "D01")
           {
               totali02 = totald01 + totalcfdi;
               subtotali02 = subtotald01 + subcfdi;
           }
           else if(usocfdi == "D02")
           {
               totali02 = totald02 + totalcfdi;
               subtotali02 = subtotald02 + subcfdi;
           }
           else if(usocfdi == "D03")
           {
               totali02 = totald03 + totalcfdi;
               subtotali02 = subtotald03 + subcfdi;
           }
           else if(usocfdi == "D04")
           {
               totali02 = totald04 + totalcfdi;
               subtotali02 = subtotald04 + subcfdi;
           }
           else if(usocfdi == "D05")
           {
               totali02 = totald05 + totalcfdi;
               subtotali02 = subtotald05 + subcfdi;
           }
           else if(usocfdi == "D06")
           {
               totali02 = totald06 + totalcfdi;
               subtotali02 = subtotald06 + subcfdi;
           }
           else if(usocfdi == "D07")
           {
               totali02 = totald07 + totalcfdi;
               subtotali02 = subtotald07 + subcfdi;
           }
           else if(usocfdi == "D08")
           {
               totali02 = totald08 + totalcfdi;
               subtotali02 = subtotald08 + subcfdi;
           }
           else if(usocfdi == "D09")
           {
               totali02 = totald09 + totalcfdi;
               subtotali02 = subtotald09 + subcfdi;
           }
           else if(usocfdi == "D10")
           {
               totali02 = totald10 + totalcfdi;
               subtotali02 = subtotald10 + subcfdi;
           }
           else
           {
               totalp01 = totalp01 + totalcfdi;
               subtotalp01 = subtotalp01 + subcfdi;
           }
       }
       }
   }
   MainWindow::on_actionTodos_triggered();
}

void MainWindow::on_actionG01_Adquisici_n_de_mercanc_as_triggered()
{

    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totalg01));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotalg01));

}

void MainWindow::on_actionG02_Devoluciones_descuentos_o_bonificaciones_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totalg02));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotalg02));
}

void MainWindow::on_actionG03_Gastos_en_general_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totalg03));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotalg03));
}


void MainWindow::on_actionTodos_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(total));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotal));
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

void MainWindow::on_actionI01_Construcciones_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali01));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali01));
}

void MainWindow::on_actionI02_Mobiliario_y_equipo_de_oficina_por_inversiones_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali02));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali02));
}

void MainWindow::on_actionI03_Equipo_de_transporte_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali03));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali03));
}

void MainWindow::on_actionI04_Equipo_de_c_mputo_y_accesorios_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali04));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali04));
}

void MainWindow::on_actionI05_Dados_troqueles_moldes_matrices_y_herramental_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali05));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali05));
}

void MainWindow::on_actionI06_Comunicaciones_telef_nicas_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali06));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali06));
}

void MainWindow::on_actionI07_Comunicaciones_satelitales_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali07));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali07));
}

void MainWindow::on_actionI08_Otra_maquinaria_y_equipo_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totali08));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotali08));
}

void MainWindow::on_actionD01_Honorarios_m_dicos_dentales_y_gastos_hospitalarios_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald01));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald01));
}

void MainWindow::on_actionD02_Gastos_m_dicos_por_incapacidad_o_discapacidad_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald02));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald02));
}

void MainWindow::on_actionD03_Gastos_funerales_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald03));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald03));
}

void MainWindow::on_actionD04_Donativos_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald04));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald04));
}

void MainWindow::on_actionD05_Intereses_reales_efectivamente_pagados_por_cr_ditos_hipotecarios_casahabitaci_n_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald05));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald05));
}

void MainWindow::on_actionD06_Aportaciones_voluntarias_al_SAR_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald06));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald06));
}

void MainWindow::on_actionD07_Primas_por_seguros_de_gastos_m_dicos_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald07));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald07));
}

void MainWindow::on_actionD08_Gastos_de_transportaci_n_escolar_obligatoria_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald08));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald08));
}

void MainWindow::on_actionD09_Dep_sitos_en_cuentas_para_el_ahorro_primas_que_tengan_como_base_planes_de_pensiones_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald09));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald09));
}

void MainWindow::on_actionD10_Pagos_por_servicios_educativos_colegiaturas_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totald10));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotald10));
}

void MainWindow::on_actionP01_Por_definir_triggered()
{
    ui->totalDisplay->clear();
    ui->subtotalDisplay->clear();
    ui->totalDisplay->insert(total2.setNum(totalp01));
    ui->subtotalDisplay->insert(subtotal2.setNum(subtotalp01));
}
