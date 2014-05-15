#include <QApplication>
#include <QMainWindow>

#include <QPushButton>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QMainWindow *mw = new QMainWindow(0, Qt::Window);
    mw->setWindowTitle("Hello Qt4");
    mw->resize(400, 200);
    mw->show();

    QPushButton *button = new QPushButton(
         QString::fromLocal8Bit("&Выход") ); // Кнопка.
     button->setFont(QFont("Times", 16, QFont::Bold));
     QObject::connect(
       button,            // Источник сигнала.
           SIGNAL(clicked()), // Сигнал о нажатии кнопки.
        &app,              // Приёмник сигнала.
         SLOT( quit() ) );  // Функция-слот (обработчик события).
     button->show();

    return app.exec();
}
