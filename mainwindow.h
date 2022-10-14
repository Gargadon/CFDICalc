#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    float total=0, totalg01=0, totalg02=0, totalg03=0, totali01=0, totali02=0;
    float totali03=0, totali04=0, totali05=0, totali06=0, totali07=0, totali08=0;
    float totald01=0, totald02=0, totald03=0, totald04=0, totald05=0, totald06=0;
    float totald07=0, totald08=0, totald09=0, totald10=0, totalp01=0;
    float subtotal=0, subtotalg01=0, subtotalg02=0, subtotalg03=0, subtotali01=0, subtotali02=0;
    float subtotali03=0, subtotali04=0, subtotali05=0, subtotali06=0, subtotali07=0, subtotali08=0;
    float subtotald01=0, subtotald02=0, subtotald03=0, subtotald04=0, subtotald05=0, subtotald06=0;
    float subtotald07=0, subtotald08=0, subtotald09=0, subtotald10=0, subtotalp01=0;
    QString total2,subtotal2;

    ~MainWindow();

private slots:
    void on_actionAbrir_CFDI_triggered();

    void on_actionG01_Adquisici_n_de_mercanc_as_triggered();

    void on_actionG02_Devoluciones_descuentos_o_bonificaciones_triggered();

    void on_actionG03_Gastos_en_general_triggered();

    void on_actionTodos_triggered();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionI01_Construcciones_triggered();

    void on_actionI02_Mobiliario_y_equipo_de_oficina_por_inversiones_triggered();

    void on_actionI03_Equipo_de_transporte_triggered();

    void on_actionI04_Equipo_de_c_mputo_y_accesorios_triggered();

    void on_actionI05_Dados_troqueles_moldes_matrices_y_herramental_triggered();

    void on_actionI06_Comunicaciones_telef_nicas_triggered();

    void on_actionI07_Comunicaciones_satelitales_triggered();

    void on_actionI08_Otra_maquinaria_y_equipo_triggered();

    void on_actionD01_Honorarios_m_dicos_dentales_y_gastos_hospitalarios_triggered();

    void on_actionD02_Gastos_m_dicos_por_incapacidad_o_discapacidad_triggered();

    void on_actionD03_Gastos_funerales_triggered();

    void on_actionD04_Donativos_triggered();

    void on_actionD05_Intereses_reales_efectivamente_pagados_por_cr_ditos_hipotecarios_casahabitaci_n_triggered();

    void on_actionD06_Aportaciones_voluntarias_al_SAR_triggered();

    void on_actionD07_Primas_por_seguros_de_gastos_m_dicos_triggered();

    void on_actionD08_Gastos_de_transportaci_n_escolar_obligatoria_triggered();

    void on_actionD09_Dep_sitos_en_cuentas_para_el_ahorro_primas_que_tengan_como_base_planes_de_pensiones_triggered();

    void on_actionD10_Pagos_por_servicios_educativos_colegiaturas_triggered();

    void on_actionP01_Por_definir_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
