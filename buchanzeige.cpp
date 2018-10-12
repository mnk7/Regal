#include "buchanzeige.h"

Buchanzeige::Buchanzeige(QWidget *parent, Buch& book) : QWidget(parent)
{
    b = &book;
    outer = new QVBoxLayout(this);
    iconKnopf = new QPushButton(this);
    iconKnopf->setFlat(true);
    setzeIcon();
    iconKnopf->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(iconKnopf, &QPushButton::clicked, this, &Buchanzeige::chooseIcon);

    outer->addWidget(iconKnopf);
    layout = new QGridLayout(this);
    outer->addLayout(layout);
    QLabel *label;
    QLineEdit *eingabe;
    QComboBox *selector;

    for(int i=0; i<20; ++i){
        if(!(i%2)){
            label = new QLabel(this);
            switch(i){
            case 0:
                label->setText("Titel");
                break;
            case 2:
                label->setText("Untertitel");
                break;
            case 4:
                label->setText("Autor");
                break;
            case 6:
                label->setText("Genre");
                break;
            case 8:
                label->setText("Seitenzahl");
                break;
            case 10:
                label->setText("Angefangen");
                break;
            case 12:
                label->setText("Beendet");
                break;
            case 14:
                label->setText("Bewertung");
                break;
            case 16:
                label->setText("Sprache");
                break;
            case 18:
                label->setText("Anmerkungen");
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
            eingabe->setText(QString::fromStdString(b->getTitle()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeTitle);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 3:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(b->getSubtitle()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeSubtitle);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 5:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(b->getAuthor()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeAuthor);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 7:
            selector = new QComboBox(this);
            selector->addItem("SciFi");
            selector->addItem("Fantasy");
            selector->addItem("Literary Fiction");
            selector->addItem("Thriller");
            selector->addItem("Politik");
            selector->addItem("Philosophie");
            selector->addItem("Biographie");
            selector->addItem("keines");
            selector->setCurrentIndex(b->getGenre());
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&Buchanzeige::changeGenre);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 9:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(b->getPagecount()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changePagecount);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 11:
            startCalendar = new QDateEdit(this);
            startCalendar->setDate(QDate::fromString(QString::fromStdString(b->getStartRead()),"yyyy.MM.dd"));
            startCalendar->setCalendarPopup(true);
            connect(startCalendar,&QDateEdit::dateChanged,this,&Buchanzeige::changeStartRead);
            layout->addWidget(startCalendar,i/2,i%2);
            break;
        case 13:
            endCalendar = new QDateEdit(this);
            endCalendar->setDate(QDate::fromString(QString::fromStdString(b->getEndRead()),"yyyy.MM.dd"));
            endCalendar->setCalendarPopup(true);
            connect(endCalendar,&QDateEdit::dateChanged,this,&Buchanzeige::changeEndRead);
            layout->addWidget(endCalendar,i/2,i%2);
            break;
        case 15:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(b->getRating()));
            connect(eingabe,&QLineEdit::textChanged,this,&Buchanzeige::changeRating);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 17:
            selector = new QComboBox(this);
            selector->addItem("Englisch");
            selector->addItem("Deutsch");
            selector->addItem("NA");
            selector->setCurrentIndex(b->getLanguage());
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&Buchanzeige::changeLanguage);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 19:
            notesIn = new QTextEdit(this);
            notesIn->setText(QString::fromStdString(b->getNotes()));
            connect(notesIn,&QTextEdit::textChanged,this,&Buchanzeige::changeNotes);
            layout->addWidget(notesIn,i/2,i%2);
            break;
        default:
            break;
        }
    }
}

void Buchanzeige::changeTitle(const QString &t){
    this->b->setTitle(t.toStdString());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeSubtitle(const QString &s){
    this->b->setSubtitle(s.toStdString());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeAuthor(const QString &a){
    this->b->setAuthor(a.toStdString());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeGenre(const int &g){
    this->b->setGenre((Buch::GENRE)g);
    emit Buchanzeige::changed();
}

void Buchanzeige::changePagecount(const QString &p){
    this->b->setPagecount(p.toUInt());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeStartRead(const QDate& date) {
    this->b->setStart((date.toString("yyyy.MM.dd")).toStdString());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeEndRead(const QDate &date){
    this->b->setEnd((date.toString("yyyy.MM.dd")).toStdString());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeRating(const QString &r){
    this->b->setRating(r.toFloat());
    emit Buchanzeige::changed();
}

void Buchanzeige::changeLanguage(const int &l){
    this->b->setLanguage((Buch::LANGUAGE)l);
    emit Buchanzeige::changed();
}

void Buchanzeige::changeNotes(){
    this->b->setNotes((notesIn->toPlainText()).toStdString());
    emit Buchanzeige::changed();
}


void Buchanzeige::setzeIcon() {
    QPixmap *icon;
    if(b->getPath().size() > 0){
        icon = new QPixmap(QString::fromStdString(b->getPath()));
    } else {
        icon = new QPixmap(":/Bilder/Buch");
    }

    *icon = icon->scaled(physicalDpiY() / 2,physicalDpiY() / 2);

    iconKnopf->setIcon(*icon);
    iconKnopf->setIconSize(QSize(icon->width(), icon->height()));
    emit update();
    emit changed();
}

void Buchanzeige::chooseIcon(){
    auto pfad = QFileDialog::getOpenFileName(
                this, "Lade Icon",
                QDir::home().absolutePath(), tr("Images (*.png *.xpm *.jpg)"));

    QFileInfo check_file(pfad);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        b->setPath(pfad.toStdString());
    } else {
        pfad = "";
    }

    setzeIcon();
}
