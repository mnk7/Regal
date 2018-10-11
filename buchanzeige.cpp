#include "buchanzeige.h"

Buchanzeige::Buchanzeige(QWidget *parent, Buch& book) : QWidget(parent)
{
    b=book;
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
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeTitle);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 3:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(book.getSubtitle()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeSubtitle);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 5:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(book.getAuthor()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeAuthor);
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
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&Buchanzeige::changeGenre);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 9:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(book.getPagecount()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changePagecount);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 11:
            dateButton = new QPushButton(this);
            dateButton->setText(QString::number(book.getStartRead()/10000)+"/"+QString::number((book.getStartRead()%10000)/100)+"/"+QString::number(book.getStartRead()%100));
            connect(dateButton, &QPushButton::clicked, this, &Buchanzeige::openStartCalendar);
            layout->addWidget(dateButton, i/2, i%2);
            break;
        case 13:
            dateButton = new QPushButton(this);
            dateButton->setText(QString::number(book.getEndRead()/10000)+"/"+QString::number((book.getEndRead()%10000)/100)+"/"+QString::number(book.getEndRead()%100));
            connect(dateButton, &QPushButton::clicked, this, &Buchanzeige::openEndCalendar);
            layout->addWidget(dateButton, i/2, i%2);
            break;
        case 15:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(book.getRating()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeRating);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 17:
            selector = new QComboBox(this);
            selector->addItem("English");
            selector->addItem("German");
            selector->addItem("NA");
            selector->setCurrentIndex(book.getLanguage());
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&Buchanzeige::changeLanguage);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 19:
            notesIn = new QTextEdit(this);
            notesIn->setText(QString::fromStdString(book.getNotes()));
            connect(notesIn,&QTextEdit::textChanged,this,&Buchanzeige::changeNotes);
            layout->addWidget(notesIn,i/2,i%2);
            break;
        default:
            break;
        }
    }
}


void Buchanzeige::openStartCalendar() {
    QCalendarWidget *calendar = new QCalendarWidget(sender());
    connect(calendar, &QCalendarWidget::clicked, this, changeStartRead);
    connect(calendar, &QCalendarWidget::activated, calendar, &QCalendarWidget::~QCalendarWidget);
}

void Buchanzeige::openEndCalendar() {
    QCalendarWidget *calendar = new QCalendarWidget(sender());
    connect(calendar, &QCalendarWidget::clicked, this, changeEndRead);
    connect(calendar, &QCalendarWidget::activated, calendar, &QCalendarWidget::~QCalendarWidget);
}

void Buchanzeige::changeTitle(const QString &t){
    this->b.setTitle(QString::toStdString(t));
}

void Buchanzeige::changeSubtitle(const QString &s){
    this->b.setSubtitle(QString::toStdString(s));
}

void Buchanzeige::changeAuthor(const QString &a){
    this->b.setAuthor(QString::toStdString(a));
}

void Buchanzeige::changeGenre(const int &g){
    this->b.setGenre(g);
}

void Buchanzeige::changePagecount(const QString &p){
    this->b.setPagecount(QString::toUInt(p));
}

void Buchanzeige::changeStartRead(const QDate& date) {
    this->b.setStart(date.year*10000+date.month*100+date.day);
}

void Buchanzeige::changeEndRead(const QDate &date){
    this->b.setEnd(date.year*10000+date.month*100+date.day);
}

