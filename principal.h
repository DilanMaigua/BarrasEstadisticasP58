#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_cmdDibujar_clicked();

    void on_inNota1_valueChanged(int arg1);

    void on_inNota2_valueChanged(int arg1);

    void on_inNota3_valueChanged(int arg1);

    void on_actionAbrir_triggered();

    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
    //Declarar el objeto sobre el cual se va a dibujar
    QPixmap lienzo;

    void dibujar();
};
#endif // PRINCIPAL_H
