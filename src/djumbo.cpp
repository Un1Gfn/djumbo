#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QStackedWidget>
// #include <QComboBox>
#include <QListWidget>

#include "djumbo.h"

static QWidget *page1(){

	// three buttons in a row
	QHBoxLayout *hl = new QHBoxLayout;
	for(int i = 0; i < 3; ++i){
		QWidget *b = new QPushButton();
		hl->addWidget(b);
	}
	// QGroupBox *g = new QGroupBox;
	QWidget *g = new QWidget;
	g->setLayout(hl);

	// four rows
	QVBoxLayout *l = new QVBoxLayout;
	QWidget *r = new QWidget;
	for(int i = 0; i < 3; ++i){
		QWidget *b = new QPushButton();
		l->addWidget(b);
	}
	l->addWidget(g);
	r->setLayout(l);
	return r;

}

Djumbo::Djumbo()
{
	const int numberOfPages = 2;
	QWidget *p[numberOfPages] = {new QWidget, page1()};

	QStackedWidget *s = new QStackedWidget;
	for(int i = 0; i < numberOfPages; ++i)
		s->addWidget(p[i]);

	// QComboBox *c = new QComboBox;
	// for(int i = 0; i < numberOfPages; ++i)
	// 	c->addItem(QString("Page %1").arg(i));
	// // connect(c, &QComboBox::activated, s, &QStackedWidget::setCurrentIndex);
	// connect(c, &QComboBox::currentIndexChanged, s, &QStackedWidget::setCurrentIndex);

	QListWidget *nav = new QListWidget;
	for(int i = 0; i < numberOfPages; ++i)
		nav->addItem(QString("Page %1").arg(i));
	connect(nav, &QListWidget::currentRowChanged, s, &QStackedWidget::setCurrentIndex);

	QHBoxLayout *l = new QHBoxLayout;
	// l->addWidget(c);
	l->addWidget(nav);
	l->addWidget(s);
	this->setLayout(l);

}

