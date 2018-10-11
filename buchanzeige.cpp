#include "buchanzeige.h"

Buchanzeige::Buchanzeige(QWidget *parent, Buch& b) : QWidget(parent)
{
    layout = new QGridLayout(this);
    QLabel *label;
    QLineEdit *eingabe;
    QComboBox *selector;

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
            eingabe->setText(QString::fromStdString(b.getTitle()));
            connect(eingabe,&QLineEdit::textChanged,&b,&Buch::setTitleQt);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 3:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(b.getSubtitle()));
            connect(eingabe,&QLineEdit::textChanged,&b,&Buch::setSubtitleQt);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 5:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::fromStdString(b.getAuthor()));
            connect(eingabe,&QLineEdit::textChanged,&b,&Buch::setAuthorQt);
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
            selector->setCurrentIndex(b.getGenre());
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),&b,&Buch::setGenreQt);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 9:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(b.getPagecount()));
            connect(eingabe,&QLineEdit::textChanged,&b,&Buch::setPagecountQt);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 11:
            startCalendar = new QDateEdit(this);
            startCalendar->setDate(QDate::fromString(QString::fromStdString(b.getStartRead()),"yyyy.MM.dd"));
            startCalendar->setCalendarPopup(true);
            connect(startCalendar,&QDateEdit::dateChanged,&b,&Buch::setStartQt);
            layout->addWidget(startCalendar,i/2,i%2);
            break;
        case 13:
            endCalendar = new QDateEdit(this);
            endCalendar->setDate(QDate::fromString(QString::fromStdString(b.getEndRead()),"yyyy.MM.dd"));
            endCalendar->setCalendarPopup(true);
            connect(endCalendar,&QDateEdit::dateChanged,&b,&Buch::setEndQt);
            layout->addWidget(endCalendar,i/2,i%2);
            break;
        case 15:
            eingabe = new QLineEdit(this);
            eingabe->setText(QString::number(b.getRating()));
            connect(eingabe,&QLineEdit::textChanged,&b,&Buch::setRatingQt);
            layout->addWidget(eingabe,i/2,i%2);
            break;
        case 17:
            selector = new QComboBox(this);
            selector->addItem("English");
            selector->addItem("German");
            selector->addItem("NA");
            selector->setCurrentIndex(b.getLanguage());
            connect(selector,QOverload<int>::of(&QComboBox::currentIndexChanged),&b,&Buch::setLanguageQt);
            layout->addWidget(selector,i/2,i%2);
            break;
        case 19:
            notesIn = new QTextEdit(this);
            notesIn->setText(QString::fromStdString(b.getNotes()));
            connect(this,&Buchanzeige::changeSignal,&b,&Buch::setNotesQt);
            connect(notesIn,&QTextEdit::textChanged,this,&Buchanzeige::changeNoteText);
            layout->addWidget(notesIn,i/2,i%2);
            break;
        default:
            break;
        }
    }
}

void Buchanzeige::changeNoteText(){
    emit changeSignal(notesIn->toPlainText());
}
