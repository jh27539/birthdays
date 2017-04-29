////////////////////////
//	Joshua Hernandez  //
//	905752791		  //
//	jh27539@vt.edu	  //
//	ECE 3574		  //
////////////////////////

#ifndef PERSON_H
#define PERSON_H

#include <QDate>
#include <QString>

class Person
{

	QString name;
	QDate birthday;

public:

	//Constructors
	Person();
	Person(QString entryName, QDate entryDate);

	//Setters
	void setName(QString newName);
	void setBirthday(QDate newDate);

	//Getters
	QString getName();
	QString getBirthday();
};

#endif