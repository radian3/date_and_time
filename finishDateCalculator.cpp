// input the start date and number of days
// output is the end date
 #include <iostream>
 #include <cmath>
 #include <string>
 #include <cstdlib>
 using namespace std;

 class Date
 { 
 private:
 int month;
 int day;
 int year;


 public:
 
 Date()
 {
 	month = 1;
 	day = 1;
 	year = 11;
 }
 
 void setTime(int monthInput, int dayInput, int yearInput)
 { month = monthInput; 
   day = dayInput;
   year = yearInput;
   
 }
 int getMonth()
  {return month;}
 
 void printDate()
  {
  if (month < 10){
  	cout << "0";
  	cout << month;
  }
  else{
  	cout << month;
  }
  cout << "/";
  
  if (day < 10){
  	cout << "0";
  	cout << day;
  }
  else{
  	cout << day;
  }
  cout << "/";
  
  if (year < 10){
  	cout << "0";
  	cout << year;
  }
  else{
  	cout << year;
  }
 }
 
 
 void addDays(int daysToAdd){
 
  int daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysLeft = month[daylist]-day;
  while (true){
  
  if (daysLeft >= daysToAdd){
  	day += daysToAdd;
  	return;
  }
  else{
  	daysToAdd -= daysLeft;
  	day = 0;
  	month += 1;
  	if (month > 12){
  		month = 1;
  		year += 1;
  		if (year > 99){
  			year = 0;
		  }
	  }
	daysLeft = month[daylist];  
  }
  
}
 }
};
 int main()
 {
 int monthValue;
 int dayValue;
 int yearValue;
 int addDays;
 char date[8];
 
 cout << "Enter the start time (mm/dd/yy): ";
 cin >> date;
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0');
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 Date date1;
 date1.setTime(monthValue, dayValue, yearValue);
 
 cout << "Enter the amount of days to add: ";
 cin >> addDays;
 date1.addDays(addDays);
 
 
 
 cout << "Adding " << addDays << " days to " << date << " gives us ";
 date1.printDate();
 

 return 0;
 }
