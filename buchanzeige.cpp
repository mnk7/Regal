#include "buchanzeige.h"

Buchanzeige::Buchanzeige(QWidget *parent, Buch& book) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    QLabel *label;
    QLineEdit *eingabe;
    QComboBox *selector;
    QTextEdit *notesIn;
    QPushButton *dateButton;
    QCalendarWidget *calendar;

    for(int i=0; i<20; ++i){
        if(!i%2){
            label = new QLabel(this);
            switch(i){
            case 0:
                label->setText("Title");
                break;
            case 2:
                label->setText("Subtitle");
                break;
            case 4:
                label->setText("Author");
                break;
            case 6:
                label->setText("Genre");
                break;
            case 8:
                label->setText("Pages");
                break;
            case 10:
                label->setText("Started Reading");
                break;
            case 12:
                label->setText("Finished Reading");
                break;
            case 14:
                label->setText("Rating");
                break;
            case 16:
                label->setText("Language");
                break;
            case 18:
                label->setText("Notes");
                break;
            default:
                label->setText("This should not have happened!");
                break;
            }
            layout->addWidget(label, i/2,i%2);
        }
        else switch (i) {
        case 1:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(book.getTitle()));
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 3:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(book.getSubtitle()));
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 5:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(book.getAuthor()));
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 7:
            selector = new QComboBox(this);
            selector->addItem("SciFi");
            selector->addItem("Fantasy");
            selector->addItem("Literary Fiction");
            selector->addItem("Thriller");
            selector->addItem("Politics");
            selector->addItem("Philosophy");
            selector->addItem("Biography");
            selector->addItem("none");
            selector->setCurrentIndex(book.getGenre());
            layout->addWidget(selector,i/2,i%2);
            break;
        case 9:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(book.getPagecount()));
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 11:
            dateButton = new QPushButton(this);
            dateButton->setText(QString::number(book.getStartRead()/10000)+"/"+QString::number((book.getStartRead()%10000)/100)+"/"+QString::number(book.getStartRead()%100));
            connect(dateButton, &QPushButton::clicked, this, &Buchanzeige::openCalendar);
            layout->addWidget(dateButton, i/2, i%2);
            break;
        case 13:
            dateButton = new QPushButton(this);
            dateButton->setText(QString::number(book.getEndRead()/10000)+"/"+QString::number((book.getEndRead()%10000)/100)+"/"+QString::number(book.getEndRead()%100));
            connect(dateButton, &QPushButton::clicked, this, &Buchanzeige::openCalendar);
            layout->addWidget(dateButton, i/2, i%2);
            break;
        case 15:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(book.getRating()));
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 17:
            selector = new QComboBox(this);
            selector->addItem("English");
            selector->addItem("German");
            selector->addItem("NA");
            selector->setCurrentIndex(book.getLanguage());
            layout->addWidget(selector,i/2,i%2);
            break;
        case 19:
            notesIn = new QTextEdit(this);
            notesIn->setText(QString::fromStdString(book.getNotes()));
            layout->addWidget(notesIn,i/2,i%2);
            break;
        default:
            break;
        }
    }
}
