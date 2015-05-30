// input the start date and finish date
// output is the amount of days/week that passed by between then
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
 
 
 void printDays(int monthVal, int dayVal, int yearVal)
 {
  int counter = 0;
  int daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (true)
  {
  	if (month == monthVal and year == yearVal)
  	{
  	 counter += dayVal-day;
	 break;  	
  		
	}
  	else
  	{
  	 counter += month[daylist]-day;
  	 day = 0;
  	 month += 1;
  	 if (month > 12)
  	 {
  	   month = 1;
	   year += 1;
	   if (year > 99)
	   {
	   	year = 0;
	   }	 	
	 }
	   	
	}
  	
  	
  }
 
 
 //
 cout << counter << "\n";
 if (counter < 7)
 {
 cout << "There are " << counter << " days between the two dates."; 
 }
 else if (counter < 365)
 {
 cout << "There are " << counter/7 << " weeks and " << counter%7 << " days between the two dates.";  	
 }
 
 else
 {
 
 cout << "There are " << counter/365 << " years, " << (counter/365)/7 << " weeks, and " << (counter/365)%7 << " days between the two dates.";	
 }
 
 //
 
 
 }


};
 int main()
 {
 int monthValue;
 int dayValue;
 int yearValue;
 int subDays;
 int months;
 int days;
 int years;
 int date2;
 int computedDays;
 char date[8];
 char datee[8];
 
 cout << "Enter the start date (mm/dd/yy): ";
 cin >> date;
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0');
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 
 Date date1;
 date1.setTime(monthValue, dayValue, yearValue);
 
 
 cout << "Enter the finish date (mm/dd/yy): ";
 cin >> datee;
 
 months = 10*(datee[0]-'0')+(datee[1]-'0');
 days = 10*(datee[3]-'0')+(datee[4]-'0');
 years = 10*(datee[6]-'0')+(datee[7]-'0');
 //cout << months << "/" << days << "/" << years;  
 //date1.computeDays(months, days, years);
 date1.printDays(months, days, years);
 //cout << "/n" << computedDays;
 
 
// cout << "Subtracting " << subDays << " days to " << date << " gives us a start on ";
 //date1.printDate();
 

 return 0;
 }
