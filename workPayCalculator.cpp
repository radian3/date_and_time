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
 
 void printDays(int monthVal, int dayVal, int yearVal, char dayResponses[], int dayOfWeek, float salary, int hrs) // this function is for printing the amount of time between the two inputted dates
 {
  int numDays = 0, // this variable counts the number of days between the two inputted dates
      daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // amount of days in each month, giving garbage value for the first so the index is easier
 
  int counter = 0;
  int valueOfDays[8] = {0, 0, 0 , 0, 0, 0, 0, 0};
 // cout << valueOfDays[1];
  valueOfDays[0] = 0;
  for (int i = 0; i < 7; i++)
  {
  	if (dayResponses[dayOfWeek-1] == 'y')
  	{
  		  
		  counter += 1;
	  }
	valueOfDays[i+1] = counter;
	dayOfWeek+=1;
	if (dayOfWeek>7)
	{
		dayOfWeek = 1;
	  }  
  }

  while (month != monthVal or year != yearVal) // we will keep iterating until we have the month and year correct, then we'll add the days after
  { 	
  	 numDays += month[daylist]-day; // adding the number of days left in the month to our counter
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

 if (numDays < 7) // checking if the two dates the user entered were less than a week apart
 {
 cout << "There are " << numDays << " days between the two dates."; // this means we only print the days
 }
 
 else if (numDays < 365) // checking if the two dates were more than a week apart but less than a year apart
 {
 cout << "\nThere are " << numDays/7 << " weeks and " << numDays%7 << " days between the two dates." // printing weeks and left over days from the last week
 << "\nAlternatively, this was " << numDays << " days total."; // printing the total in days incase the user wants that information too 	
 }
 
 else // this means the user entered two dates that were a year or further apart
 { // we will print the years, left over weeks, and left over days apart
 cout << "\nThere are " << numDays/365 << " years, " << (numDays%365)/7 << " weeks, and " << (numDays%365)%7 << " days between the two dates."
 << "\nAlternatively, this was " << numDays << " days total."; // printing the total day count incase the user wants that but it's a high number  	
 }
 
 
 //cout << "\nThere are " << (numDays/7)*counter << " work during this time period.";
 cout << "\nThere are " << (((numDays+1)/7)*counter) + (valueOfDays[(numDays+1)%7]) << " work days during this time period earning a salary of $" << salary*hrs*(((numDays+1)/7)*counter) + (valueOfDays[(numDays+1)%7]);
 
 } // closing our printDays function


}; // closing the class section


 int main() // starting our main function!
 {
 int monthValue, // first month (computed)
     dayValue, // first day (computed)
     yearValue, // first year (computed)
 //    subDays, // a
     months, // second month input
     days, // second day input
     years, // second year input
//     date2, // secnd date that is inputted
     computedDays;
 
 char date[8], // this will store the first date read in from the user
      secondDate[8]; // this will store the second date read in from the user
 
 cout << "Enter the start date (mm/dd/yy): "; // getting the user to input the first date
 cin >> date; // storing the date
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0'); // computing the month, day, year from the format
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 
 Date date1; // creating an object, date1, under the Date class
 date1.setTime(monthValue, dayValue, yearValue); // setting the time to what the user entered
 
 
 cout << "Enter the finish date (mm/dd/yy): "; // getting the user to input the second date
 cin >> secondDate; // storing the second date
 
 months = 10*(secondDate[0]-'0')+(secondDate[1]-'0'); // computing the month, day, year from the format
 days = 10*(secondDate[3]-'0')+(secondDate[4]-'0');
 years = 10*(secondDate[6]-'0')+(secondDate[7]-'0');

 //char response;
 string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 char workOrClassDays[7];
 for (int i = 0; i < 7; i++ )
 {
 	cout << "Do you work on " << daysOfWeek[i] << " (y/n)? ";
 	cin >> workOrClassDays[i];
 }
 float wage;
 cout << "Enter hourly wage: ";
 cin >> wage;
 
 int hrsWorked;
 cout << "Enter amount of hours worked per day: ";
 cin >> hrsWorked;
 
 int dayOfWeek;
 cout << "Enter an integer representing the day of the week for the\nstart date (ex: 1 = Sunday, 2 = Monday, ... , 7 = Saturday): ";
 cin >> dayOfWeek;
 
 date1.printDays(months, days, years, workOrClassDays, dayOfWeek, wage, hrsWorked); // printing off the number of days between the date1 object and the input for the second date

 return 0;
 }
