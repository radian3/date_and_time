// input a start time and amount of time for each activity
// output: the time that your activities are anticipated to be done by

 #include <iostream>
 #include <cmath>
 #include <string>
 #include <cstdlib>
 using namespace std;

 class Time
 { 
 private:
 int hours,
     minutes;
 char meridiem;


 public:
 
 Time()
 {
 	hours = 0;
 	minutes = 0;
 	meridiem = 'a';
 }
 
 void setTime(int hr, int min, char mer) // used for the start time
 { hours = hr;
   minutes = min;
   meridiem = mer;
 }

 void printTime() // printing out the time that everything will be finished by
  {
 
  if (minutes == 0)
  {cout << "\nYou will finish at " << hours << ":" << "00" << meridiem << 'm' << "\n";}
  
  else if (minutes < 10)
  {cout << "\nYou will finish at " << hours << ":" << "0" << minutes << meridiem << 'm' << "\n";}	
  
  else
 	{cout << "\nYou will finish at " << hours << ":" << minutes << "" << meridiem << 'm' << "\n";}

  } // done with function
 
 void meridiemSwap(){ // changing am to pm (or pm to am)
  if (meridiem == 'a')
  	{meridiem = 'p';}
  
  else
  {meridiem = 'a';}
  	
 }
 
 void addTime(int hrs, int mins){ // used to add time to the current time of our time object
  if (hours == 12) // the program needs to swap meridiems if the start is a 12 because if it ends at 12, it is going to swap the meridiem 
  {meridiemSwap();} // and we dont want the meridiem being changed if it started so here it would be swapped twice which gets us what we started with
  
  hours += hrs; // adding in the hours that the user inputted
  minutes += mins; // adding in the minutes that the user inputted
 
  if (minutes >= 60){ // if we have too many minutes...
   hours += minutes/60; // adding to our hours and setting our minutes to a valid value
   minutes = minutes%60;}
 
  if (hours > 12){ // if we have too many hours...
  hours -= 12; // subtract 12 and swap the meridiem
  meridiemSwap();}
 
  if (hours == 12) // if we end with 12 hours, swap the meridiem swap
  	{meridiemSwap();} // but what if we started at 12 and the hours didn't change? that is why we swapped it first so that this one undoes it
 
  } // done with our addTime function 
  
  
}; // done with our class part


 int main()
 {
 int hours,
     minutes;

 char timer[6],
      meridiem;

 cout << "Enter the start time (ex: 11:32pm): "; // asking the user to enter the start time
 cin >> timer;
 cout << "You entered " << timer << "\n"; // telling the user what they entered incase they are concerned that it wasn't read
 cout << "Type '0 0' without the quotes to exit at any time\n\n"; // telling the user how to exit
 

 if (timer[1]==':'){ // need to see if the user entered a single digit hour (1-9)
    hours = timer[0]-'0'; // computing the hours from the input (string to int)
    minutes = (timer[2]-'0')*10+(timer[3]-'0'); // computing the minutes from the input (string to int)
    meridiem = timer[4]; // grabbing the meridiem
}
    
else{ // user entered double digit hours (10, 11, or 12)
 hours = (timer[0]-'0')*10+(timer[1]-'0');
 minutes = (timer[3]-'0')*10+(timer[4]-'0');
 meridiem = timer[5];	
}

 Time time1; // making an object time1 under the Time class
 time1.setTime(hours, minutes, meridiem); // setting the time to the start time
 
 int counter = 1; // initializing a counter that will be used to track which activit we are on
 while (true){
 
  cout << "Enter amount of time for activity " << counter << " (ex: 1 23 for 1 hr 23 mins): "; // asking the user to input how long the activity will take
  cin >> hours >> minutes;
  if (hours == 0 and minutes == 0) // if the user entered 0 0, that means the next activity is 0 hours and 0 minutes (meaning they want to quit inputting)
  {break;}
  time1.addTime(hours, minutes); // adding the amount of time that the user requested to be added to the current time (before the next user input)
  counter+=1;
}
 
 time1.printTime(); // printing off the time that everything will be done by

 return 0;
 }
