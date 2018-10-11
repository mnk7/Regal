#include "buchanzeige.h"

Buchanzeige::Buchanzeige(QWidget *parent, Buch& book) : QWidget(parent)
{
    //test Buchanzeige
    //Buch b("handle","title","sub","auth",Buch::Politics,100,20180101,20180102,8,Buch::German);
    //Buchanzeige *a = new Buchanzeige(this,b);
    //test Buchanzeige

    //test Buchanzeige
    //this->layout()->addWidget(a);

    b=book;
    QGridLayout *layout = new QGridLayout(this);
    QLabel *label;
    QLineEdit *eingabe;
    QComboBox *selector;
    QPushButton *dateButton;
    QHBoxLayout *l;
    startCalendar = new QCalendarWidget(this);
    setCalendarVisible(startCalendar,false);
    endCalendar = new QCalendarWidget(this);
    setCalendarVisible(endCalendar,false);

    for(int i=0; i<20; ++i){
        if(!(i%2)){
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
            label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
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
            l= new QHBoxLayout(this);
            l->addWidget(dateButton);
            l->addWidget(startCalendar);
            connect(dateButton, &QPushButton::clicked, this, &Buchanzeige::openStartCalendar);
            layout->addLayout(l, i/2, i%2);
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
    setCalendarVisible(startCalendar,true);
    connect(startCalendar, &QCalendarWidget::clicked, this, &Buchanzeige::changeStartRead);
    connect(startCalendar, &QCalendarWidget::activated, this, &Buchanzeige::setStartInvisible);
}

void Buchanzeige::openEndCalendar() {
    setCalendarVisible(endCalendar,true);
    connect(endCalendar, &QCalendarWidget::clicked, this, &Buchanzeige::changeEndRead);
    connect(endCalendar, &QCalendarWidget::activated, this, &Buchanzeige::setEndInvisible);
}

void Buchanzeige::changeTitle(const QString &t){
    this->b.setTitle(t.toStdString());
}

void Buchanzeige::changeSubtitle(const QString &s){
    this->b.setSubtitle(s.toStdString());
}

void Buchanzeige::changeAuthor(const QString &a){
    this->b.setAuthor(a.toStdString());
}

void Buchanzeige::changeGenre(const int &g){
    this->b.setGenre((Buch::GENRE)g);
}

void Buchanzeige::changePagecount(const QString &p){
    this->b.setPagecount(p.toUInt());
}

void Buchanzeige::changeStartRead(const QDate& date) {
    this->b.setStart(date.year()*10000+date.month()*100+date.day());
}

void Buchanzeige::changeEndRead(const QDate &date){
    this->b.setEnd(date.year()*10000+date.month()*100+date.day());
}

void Buchanzeige::changeRating(const QString &r){
    this->b.setRating(r.toFloat());
}

void Buchanzeige::changeLanguage(const int &l){
    this->b.setLanguage((Buch::LANGUAGE)l);
}

void Buchanzeige::changeNotes(){
    this->b.setNotes((notesIn->toPlainText()).toStdString());
}


void Buchanzeige::setStartInvisible(){
    setCalendarVisible(this->startCalendar,false);
}

void Buchanzeige::setEndInvisible(){
    setCalendarVisible(this->endCalendar,false);
}

void Buchanzeige::setCalendarVisible(QCalendarWidget *c, bool v){
    c->setGridVisible(v);
    c->setNavigationBarVisible(v);
}
