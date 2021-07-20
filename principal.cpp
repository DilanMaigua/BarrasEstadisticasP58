#include "principal.h"
#include "ui_principal.h"



Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //Crear el lienzo
    lienzo = QPixmap(500,500);

    //Invocar al metodo dibujar
    this->dibujar();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //Rellenar el lienzo de color blanco
    lienzo.fill(Qt::white);

    //Crear el pintor
    QPainter painter(&lienzo);

    int x = 50;
    int y = 50;
    int ancho = 100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Crear el pincel para el borde
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    //Establecer el pincel al pintor
    painter.setPen(pincel);

    //Dibujar la primera barra
    painter.drawRect(x, y+(400-alto_1), ancho, alto_1);

    //Crear un nuevo color
    QColor colorBorde2(78,3,48);
    QColor colorRelleno2(190,120,162);

    //Establecer el nuevo color al pincel
    pincel.setColor(colorBorde2);

    //Volver a establecer el pincel al objeto painter
    painter.setPen(pincel);

    //Establecer el color de la brocha del objeto painter
    painter.setBrush(colorRelleno2);

    //Dibujar la segunda barra
    painter.drawRect(x+150, y+(400-alto_2), ancho, alto_2);

    //Creando los colores de la tercera barra
    QColor colorRelleno3(253,253,115);
    QColor colorBorde3(174,174,51);

    //Establecer nuevo color al pincel
    pincel.setColor(colorBorde3);
    //Establecer el pincel y la brocha al painter
    painter.setPen(pincel);
    painter.setBrush(colorRelleno3);
    //Dibujar el rectangulo
    painter.drawRect(x+300, y+(400-alto_3), ancho, alto_3);

    //Mostrar el lienzo en el cuadro
    ui->cuadro->setPixmap(lienzo);
}

//Funcion que permite al boton mandar a dibujar en el lienzo
void Principal::on_cmdDibujar_clicked()
{
    dibujar();
}

//Funcion que nos permiten dibujar cada que el numero del spin roll sea cambiado
void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}

//Funcion que nos sirven para guardar la imagen que creemos en el lienzo
void Principal::on_actionAbrir_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guardado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

//Funcion para salir del programa
void Principal::on_actionSalir_triggered()
{
    this->close();
}

