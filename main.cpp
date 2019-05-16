#include<QApplication>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QCompleter>
#include<QVBoxLayout>


int main(int argc,char *argv[]){
    QApplication app(argc,argv);

    QWidget w;
    w.show();
    QPushButton button;
    button.setText("Button");
    button.setParent(&w);
    button.show();
    QLineEdit edit;
    edit.setParent(&w);
    edit.setGeometry(50,50,200,25);
    edit.setPlaceholderText("please input");
    QCompleter completer(QStringList()<<"abc"<<"123"<<"998");
    completer.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&completer);
    edit.show();
    QObject::connect(&button,SIGNAL(clicked()),&w,SLOT(close()));

    QVBoxLayout layout;
    layout.addWidget(&edit);
    layout.addWidget(&button);


    w.setWindowTitle("HelloWorld");
    w.setLayout(&layout);

    return app.exec();

}
