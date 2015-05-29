// This program uses a class to represent time.
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
 
 
 /*
 void addTime(int hrs, int mins){
  if (hours == 12)
  {meridiemSwap();}
  
  hours += hrs;
  minutes += mins;
  if (minutes >= 60){
   hours += minutes/60;
   minutes = minutes%60;}
  if (hours > 12){
  hours -= 12;
  meridiemSwap();}
  if (hours == 12)
  	{meridiemSwap();}
  } 
*/  
}
};
 int main()
 {
 int monthValue;
 int dayValue;
 int yearValue;
 char date[7];
 
 cout << "Enter the start time (mm/dd/yy): ";
 cin >> date;
 cout << "You entered " << date << "\n"; 

 

 /*

 Time time1;
 time1.setTime(hours, minutes, meridiem);
 int counter = 1;
 while (true){
 
  cout << "Enter amount of time for activity " << counter << " (ex: 1 23 for 1 hr 23 mins): ";
  cin >> hours >> minutes;
  if (hours == 0 and minutes == 0)
  {break;}
  time1.addTime(hours, minutes);
  counter+=1;
}
 
 time1.printTime();

*/
 return 0;
 }
