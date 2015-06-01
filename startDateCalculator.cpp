// input the finish date and number of days
// output is the start
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
 
 Date()
 {
 	month = 1;
 	day = 1;
 	year = 11;
 }
 
 void setTime(int monthInput, int dayInput, int yearInput) // this will set the time for the finish date
 { month = monthInput; 
   day = dayInput;
   year = yearInput;
   
 }

 void printDate() // this will print the current date
  {
  if (month < 10){ // checking if single digit months so we know to print a leading 0
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
 } // done with printDate function
 
 
 void subtractDays(int daysToSub){ // subtracting days from the current day (used to compute the start date)
 
  int daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days in each month with a bogus value for the first slot to make indexing easier

  while (true){ // iterating until we have subtracted all of the days needed
  
  if (day >= daysToSub){ // needing to see if the amount of days left to subtract will keep us within our month now
  	day -= daysToSub;
  	break;
  }
 /* 
  if (day = daysToSub){ // special case for having 0 days left to avoid error
  	month -= 1;
  	if (month < 1){
  		month = 12;
  		year -= 1;
  		if (year < 0){
  			year = 99;
		  }
	  }
	day = month[daylist]; 
	break;
  }
  */
  else{ // more days left to subtract than what we have left in the month
  	daysToSub -= day;
  	month -= 1;
  	if (month < 1){ // checking if we are going from january to decemeber, if so, we need to go back a year
  		month = 12;
  		year -= 1;
  		if (year < 0){
  			year = 99;
		  }
	  }

	day = month[daylist]; // setting the day to the last day in the month
  }
  
} // done with the while loop
  if (day == 0) // if we are on the 0th day, we will go to the last day of the previous month
  {
  
    month -= 1;
  	if (month < 1){
  		month = 12;
  		year -= 1;
  		if (year < 0){
  			year = 99;
		  }
	  }
	day = month[daylist];
 }
 } // done with the subtractDays function

}; // done with class definitions
 
 int main()
 {
 int monthValue, // the month value the user inputted
     dayValue, // the day value the user inputted
     yearValue, // the year value the user inputted
     subDays; // the amount of days the user wants to take away from the finish date
 char date[8];
 
 cout << "Enter the finish date (mm/dd/yy): "; // requesting user input
 cin >> date;
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0'); // extracting the month value
 dayValue = 10*(date[3]-'0')+(date[4]-'0'); // extracting the day value
 yearValue = 10*(date[6]-'0')+(date[7]-'0'); // extracting the year value
 
 Date date1; // making an object named date1 of the Date class 
 date1.setTime(monthValue, dayValue, yearValue); // setting our object with the finish date that the user inputted
 
 cout << "Enter the amount of days to subtract: "; // asking for user input
 cin >> subDays; 
 date1.subtractDays(subDays); // subtracting the days from our time1 object
 
 cout << "Subtracting " << subDays << " days to " << date << " gives us a start on "; // printing our results
 date1.printDate(); // printing the start date
 

 return 0;
 }
