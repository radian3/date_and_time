// input the start date and finish date, days the class meets
// the output is the amount of days that the class meets
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
 
 int getDayOfWeek(int monthVal, int dayVal, int yearVal) // this function is for printing the amount of time between the two inputted dates
 {
  int numDays = 0, // this variable counts the number of days between the two inputted dates
      daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // amount of days in each month, giving garbage value for the first so the index is easier
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
 
 //int retVal = daysOfWeek[numDays%7];
 return numDays%7; // printing the total day count incase the user wants that but it's a high number  	
 
 
 } // closing our getDayOfWeek function
 
 
 
 void printDays(int monthVal, int dayVal, int yearVal, char dayResponses[], int dayOfWeek) // this function is for printing the amount of time between the two inputted dates
 {
  int numDays = 0, // this variable counts the number of days between the two inputted dates
      daylist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // amount of days in each month, giving garbage value for the first so the index is easier
  if (dayOfWeek == 0)
  {dayOfWeek = 7;}
  
  
  
  int counter = 0; // used to count the number of class days per week
  int valueOfDays[8]; // array storing the number of class days up to the day
  valueOfDays[0] = 0; // setting the date for the first day to 0 incase there are 0 days
  
  for (int i = 0; i < 7; i++) // setting up our array that states how many class days there are up to each day of the week
  {
  	if (dayResponses[dayOfWeek-1] == 'y') // checking if the user has a class day on this day
  	{
  		  
		  counter += 1; // if so we add to our counter
	  }

	valueOfDays[i+1] = counter; // storing the amount of class days up to the day
	dayOfWeek+=1; // going to the next day of the week

	if (dayOfWeek>7) // if we get passed the last day of the week, go back to the first day
	{
		dayOfWeek = 1;
	  }  
  }

  while (month != monthVal or year != yearVal) // we will keep iterating until we have the month and year correct, then we'll add the days after
  { 	
  	 
  	 if (month == 2 and (year%4==0) and (year==0 or (year+2000)%4==0) ) // checking if leap year and february
	   {numDays += 29-day;} // if so, 29 days in the month
	 else 
	 {numDays += month[daylist]-day;} // adding the number of days left in the month to our counter
     
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

 
 cout << "\nThere are " << (numDays%365)/7 << " weeks and " << (numDays%365)%7 << " days between the two dates."
 << "\nAlternatively, this was " << numDays+1 << " days total (inclusive)."; // printing the total day count incase the user wants that but it's a high number  	
 // the number of class days will be the full number of weeks of class * the amount of days of class per week + the remaining left over class days (will be 0-6)
 cout << "\nThis class meets " << (((numDays+1)/7)*counter) + (valueOfDays[(numDays+1)%7]) << " times."; // printing number of class days
 
 } // closing our printDays function


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

}; // closing the class section


 int main() // starting our main function!
 {
 int monthValue, // first month (computed)
     dayValue, // first day (computed)
     yearValue, // first year (computed)
     addDays,
 //    subDays, // a

     computedDays;
 
 char date[8]; // this will store the first date read in from the user

 
 cout << "Enter the first day of the term (mm/dd/yy): "; // getting the user to input the first date
 cin >> date; // storing the date
 
 monthValue = 10*(date[0]-'0')+(date[1]-'0'); // computing the month, day, year from the format
 dayValue = 10*(date[3]-'0')+(date[4]-'0');
 yearValue = 10*(date[6]-'0')+(date[7]-'0');
 
 Date date1; // creating an object, date1, under the Date class
 date1.setTime(monthValue, dayValue, yearValue); // setting the time to what the user entered
 
 
 
 

 //char response;
 cout << "Enter the amount of days to add: "; // asking the user to put in the amount of days they are adding to get to the final date
 cin >> addDays;
 
 string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 int counterVal = 0;
 int dayValues[8];
 
 int idx = 2;
 
 dayValues[0] = 0;
 char ClassDays[7];
 for (int i = 0; i < 7; i++ ) // checking which day the user has class on
 {
 	cout << "Is " << daysOfWeek[i] << " a business day (y/n)? ";
 	cin >> ClassDays[i];
 	if (ClassDays[i] == 'y')
 	{
 		counterVal += 1;
	 }
	dayValues[idx] = counterVal;
	idx += 1;
	if (idx > 7)
	{
		idx = 1;
	 } 
 }
 
 int dayOfWeek; 
 
 Date dateOfWeekBlock;
 dateOfWeekBlock.setTime(1, 1, 0);
 dayOfWeek = dateOfWeekBlock.getDayOfWeek(monthValue, dayValue, yearValue);
 dateOfWeekBlock.setTime(1, 1, 0);
 string daysssOfWeek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
 

 
 int businessDayCounter = 0;
 int totalDays = 0;
 int index = (dayOfWeek-1)%7;
 
 // start the index with the day of the week
 
 while (businessDayCounter < addDays)
 {
  if (ClassDays[index] == 'y')
  {
  	businessDayCounter += 1;
	  }	
  totalDays += 1;
  index += 1;
  if (index > 6)
  {
  	index = 0;
		}	  
  } 
 
 int indexx = (dayOfWeek-1)%7;
 
 cout << "\n" ;
 
 if (ClassDays[indexx] != 'y')// if first day was not business day, sub 1
 {
 	totalDays -= 1;

 }
 
 date1.addDays(totalDays); // adding in the days the user requested
 
// cout << "\n" << dayOfWeek << "\n" << ClassDays << "\n";

 date1.printDate();
 
 return 0;
 }
