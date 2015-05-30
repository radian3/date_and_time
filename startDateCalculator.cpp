// input the finish date and number of days
// output is the start
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
 
 
 void subtractDays(int daysToSub){
 
  int daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysLeft = day;
  while (true){
  
  if (daysLeft >= daysToSub){
  	day -= daysToSub;
  	return;
  }
  else{
  	daysToSub -= daysLeft;
  	month -= 1;
  	if (month < 1){
  		month = 12;
  		year -= 1;
  		if (year < 0){
  			year = 99;
		  }
	  }
	daysLeft = month[daylist];
	day = daysLeft; 
  }
  
}
 }
};
 int main()
 {
 int monthValue;
 int dayValue;
 int yearValue;
 int subDays;
 char date[8];
 
 cout << "Enter the finish date (mm/dd/yy): ";
 cin >> date;
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0');
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 Date date1;
 date1.setTime(monthValue, dayValue, yearValue);
 
 cout << "Enter the amount of days to subtract: ";
 cin >> subDays;
 date1.subtractDays(subDays);
 
 
 
 cout << "Subtracting " << subDays << " days to " << date << " gives us a start on ";
 date1.printDate();
 

 return 0;
 }
