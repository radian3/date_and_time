// input the start date and number of days
// output is the end date
 #include <iostream>
 #include <string>

 using namespace std;

 class Date
 { 
 private:
 int month;
 int day;
 int year;


 public:
 
 Date() // constructor
 {
 	month = 1;
 	day = 1;
 	year = 11;
 }
 
 void setTime(int monthInput, int dayInput, int yearInput) // this will be used for the start time
 { month = monthInput; 
   day = dayInput;
   year = yearInput;
   
 }

 void printDate() // this will be used to print out the current date
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
 
 
 void addDays(int daysToAdd){ // this is used to add more days to the current date and will udpate the months/year if the days is more than whats in the month
 
  int daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // array of days per month, giving a bogus value to the first index to make indexing easier
  int daysLeft = month[daylist]-day; // amount of days left in the current month
  
  while (daysLeft < daysToAdd) // adding the days to our time class
  {
  	daysToAdd -= daysLeft; // subtracting off all of the days left in the month since there's still more days left to add
  	day = 0;
  	month += 1; // adding a month since we added the rest o the days
  	if (month > 12) // checking if it's the new year
	  {
  		month = 1;
  		year += 1;
  		if (year > 99)
		  {
  			year = 0;
		  }
	  }
  
    if (month == 2 and (year%4==0) and (year==0 or (year+2000)%4==0) ) // checking if leap year and february
	   {daysLeft = 29-day;} // if so, 29 days in the month
	 else 
	 {daysLeft = month[daylist];}  
  
 } // closing the while loop

 day += daysToAdd; // adding the left-over days from the last month

 } // done with addDays 
}; // done with our class definitions

 int main() 
 {
 int monthValue, // this will compute the month that the user entered
     dayValue, // this will compute the day that the user entered
     yearValue, // this will compute the year that the user entered
     addDays; // this is the amount of days the user wants to add to find the finish date
 
 char date[8]; // this will store the entire date input from the user
 
 cout << "Enter the start time (mm/dd/yy): "; // asking the user to input the start date
 cin >> date;
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0'); // computing/extracting the month from the format
 dayValue = 10*(date[3]-'0')+(date[4]-'0'); // computing the day from the format
 yearValue = 10*(date[6]-'0')+(date[7]-'0'); // computing the year from the format
 
 Date date1; // making an object named date1 of the Date class
 date1.setTime(monthValue, dayValue, yearValue); // setting the time to what the user inputted
 
 cout << "Enter the amount of days to add: "; // asking the user to put in the amount of days they are adding to get to the final date
 cin >> addDays;
 date1.addDays(addDays); // adding in the days the user requested
 
 
 
 cout << "Adding " << addDays << " days to " << date << " gives us "; // printing off our result which is the final date that we computed
 date1.printDate();
 

 return 0;
 }
