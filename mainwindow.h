#pragma once
#include <QMainWindow>
#include <QString>
#include <unordered_map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_CFDI_triggered();
    void on_actionSalir_triggered();
    void on_actionAcerca_de_triggered();
    void updateDisplay(const QString& usoCFDI);
    void on_actionCFDI_triggered();

    void on_copyTotal_clicked();

    void on_copySubtotal_clicked();

private:
    Ui::MainWindow* ui;
    QMenu* menuFiltrar; // Añadido para acceder al menú de filtros

    struct CFDIData {
        float total = 0;
        float subtotal = 0;
    };

    std::unordered_map<QString, CFDIData> cfdiTotals;

    void resetTotals();
    void processCFDIFile(const QString& filename);
    void updateDisplayValues(float total, float subtotal);
    void setupFilterMenu(); // Nuevo método para configurar el menú
};
