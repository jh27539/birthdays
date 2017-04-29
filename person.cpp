////////////////////////
//	Joshua Hernandez  //
//	905752791		  //
//	jh27539@vt.edu	  //
//	ECE 3574		  //
////////////////////////

#include <QDate>
#include <QString>
#include "person.h"

//Constructors
Person::Person()
{
	name = "";
	birthday = QDate::currentDate();
}

Person::Person(QString entryName, QDate entryDate)
{
	this->name = entryName;
	this->birthday = entryDate;
}

//Setters
void Person::setName(QString newName)
{
	this->name = newName;
}

void Person::setBirthday(QDate newDate)
{
	this->birthday = newDate;
}

//Getters
QString Person::getName()
{
	return this->name;
}

QString Person::getBirthday()
{
	return this->birthday.toString();
}