// input the start date and finish date
// the output is the amount of days/weeks/years that passed by between the two inputted dates
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
 
 void setTime(int monthInput, int dayInput, int yearInput) // this will be used to make an object for the start date
 { month = monthInput; 
   day = dayInput;
   year = yearInput;
   
 }
 
 void printDays(int monthVal, int dayVal, int yearVal) // this function is for printing the amount of time between the two inputted dates
 {
  int numDays = 0, // this variable counts the number of days between the two inputted dates
      daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // amount of days in each month, giving garbage value for the first so the index is easier
  string daysOfWeek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  while (month != monthVal or year != yearVal) // we will keep iterating until we have the month and year correct, then we'll add the days after
  { 	
  	 if (month == 2 and (year%4==0) and (year==0 or (year+2000)%4==0) ){
  	 	numDays += 29-day;
	   }
	 else{
	   
	 numDays += month[daylist]-day; // adding the number of days left in the month to our counter
     }
	 day = 0; // changing our day value to 0 since we added the number of days left to our counter
  	 month += 1; // adding our month to 0 since we made it to the next month by adding the days left in te month
  	 if (month > 12) // if we get to the "13th" month, we'll set back to the first month
  	 {
  	   month = 1;
	   year += 1; // we reached the new year so we add 1 to the year
	   if (year > 99) // since our year is a 2 digit representation, we check the rare possibility of it being the year '99 and going to the next new year
	   {
	   	year = 0;
	   }	 	
	 }
  } // closing while loop
 
 numDays += dayVal-day; // adding the days from the final month manually to our counter value
 
// now ready to print our results below!


 

  // we will print the years, left over weeks, and left over days apart
 cout  << daysOfWeek[(numDays%7)]; // printing the total day count incase the user wants that but it's a high number  	
 
 
 } // closing our printDays function


}; // closing the class section


 int main() // starting our main function!
 {
 int monthValue, // first month (computed)
     dayValue, // first day (computed)
     yearValue, // first year (computed)
 //    subDays, // a
 
     computedDays;
 
 char date[8], // this will store the first date read in from the user
      secondDate[8]; // this will store the second date read in from the user
 
 cout << "Enter the start date (mm/dd/yy): "; // getting the user to input the first date
 cin >> date; // storing the date
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0'); // computing the month, day, year from the format
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 
 Date date1; // creating an object, date1, under the Date class
 date1.setTime(1, 1, 0); // setting the time to what the user entered
 

 date1.printDays(monthValue, dayValue, yearValue); // printing off the number of days between the date1 object and the input for the second date

 return 0;
 }
