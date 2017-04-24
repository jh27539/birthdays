////////////////////////
//	Joshua Hernandez  //
//	905752791		  //
//	jh27539@vt.edu	  //
//	ECE 3574		  //
////////////////////////


//#include "Person.h"
#include <QDate>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTextStream>

void testDates();

//argc counts the number of arguments
//argv stores pointers to them in a vector
int main(int argc, char *argv[])
{
	//testDates();

	QTextStream out(stdout);
    QStringList outputList;

    //Read in birthdays.dat
    QFile file("birthdays.dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
    	qDebug() << "Could not open file!";
    	return 0;
    }

    //Fill up outputList with each entry
    QTextStream in(&file);
    while (!file.atEnd())
    {
	    QString name  = file.readLine();
	    QString date = file.readLine();
	    name.remove("\n");

	    if(name.size() > 15)
	    	name.append("\t");
	    else
	    	name.append("\t\t");

	    name.append(date);
	    outputList << name;
    }

    switch (argc)
    {
    	// No arguments
    	// List all birthdays coming up in the next 30 days
	    case 1:
	    {
	    	for(int i=0; i<outputList.size(); i++)
	    	{
	    		//do stuff
	    	}
	    }
	    break;

	    case 2:
	    {	
	    	if(*argv[1] == '-' && *(argv[1]+1) == 'u')
	    	{
	    		//qDebug() << *argv[1];
	    		qDebug() << "Update records";
	    	}

	    	//else if(*(argv[1]+1) > 65 || *(argv[1]+1) < 91 )
	    		//qDebug() << "Show all birthdays for that name";

	    	else
	    	{
	    		qDebug() << "search for" << argv[1];
	    	}
	    }
	    break;

	    case 3:
	    {
	    	if (*argv[1] == '-' && *(argv[1]+1) == 'n')
	    	{
	    		qDebug() << "Show all bdays within the next" << argv[2] << "days";
	    	}

	    	else if (*argv[1] == '-' && *(argv[1]+1) == 'd')
	    	{ 
	    		qDebug() << "Delete all birthdays containing" << argv[2];
	    	}
	    }
	    break;

	    case 4:
	    {
	    	if (*argv[1] == '-' && *(argv[1]+1) == 'a')
	    	{
	    		qDebug() << "Add a birthday";
	    	}

	    	else if (*argv[1] == '-' && *(argv[1]+1) == 'm')
	    	{
	    		qDebug() << "Show person's birthdays in the next #days";
	    	}

	    }
	    break;
	}

    //Final Output
    out << "Name\t\t\tBirthday\n========\t\t========\n";
    for (int i=0; i<outputList.size(); i++)
    {
    	out << outputList[i];
    }

    qDebug() << endl;

    return 0;
}

void testDates()
{
	//Convert String to date
	QDate myDate = QDate(2014,12,01);
	qDebug() << "This is the myDate variable: " << myDate;

	myDate = myDate.addDays(3);
	qDebug() << "After adding days: " << myDate;
	qDebug() << "Days past current date: "
	<< myDate.daysTo(QDate::currentDate());
	
	QString testDate = "2014-09-04";
	qDebug() << "This is the testDate variable: " << testDate;

	QDate newDate = QDate::fromString(testDate, 0);
	qDebug() << "This is the newDate variable: " << newDate;

	myDate = myDate.addDays(3);
	qDebug() << "This is after adding days: " << newDate;

	qDebug() << QDate::currentDate();
}
