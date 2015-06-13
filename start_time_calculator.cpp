// This program tells you how early you need to start in order to finish or arrive on time
// inputs: the desired finish time and time it will take to do the activities
// output: the time that you must start at to finish everything
 #include <iostream>
 #include <string>

 using namespace std;

 class Time
 { 
 private:
 
 int minutes;
 int hours;
 char meridiem;


 public:
 
 Time()
 {
    hours = 0;
 	minutes = 0; 	
 	meridiem = 'a';
 }
 
 void setTime(int hr, int min, char mer) // this will be used to set the finish time
 {  hours = hr;
    minutes = min; 
    meridiem = mer;
   
 }
 
 void printTime() // this will print off our result which is the time that we must start at in order to finish at the desired time
  {
  if (minutes == 0) // need to make sure to print 00 instead of 0 if there aren't any minutes

  {cout << "\nYou must start at " << hours << ":" << "00" << meridiem << 'm' << "\n";}
  
  else if (minutes < 10) // need to have a 0 in the tens digit if the minutes are between 1 and 9 here
  {cout << "\nYou must start at " << hours << ":" << "0" << minutes << meridiem << 'm' << "\n";}	
  
 else // otherwise we don't have to worry about printing a 0 in the tens digit
 	{cout << "\nYou must start at " << hours << ":" << minutes << "" << meridiem << 'm' << "\n";}
  }
 
 void meridiemSwap(){ // changing from am to pm and vise-versa
  if (meridiem == 'a')
  	{meridiem = 'p';}
  
  else
  {meridiem = 'a';}
  	
 }
 
 void subtractTime(int hrs, int mins){ // subtracting time from the current time
 
  if (hours == 12) // the program swap meridiems if it ends at 12, so if it starts at 12, we need to swap so it doesn't get confused
  { meridiemSwap();}

  hours -= hrs; // subtracting off the hours that the user inputted
  minutes -= mins; // subtracting off the minutes that the user inputted

  if (minutes < 0){ // if we have negative minutes, we need to add some hours back
   hours -= (-minutes/60)+1; // adding hours back 
   minutes = (minutes%60)+60;} // getting our minutes back to a positive value

  if (hours < 0){ // if we have negative hours, we need to swap the meridiem and add 12
  hours += 12;
  meridiemSwap();}

  if (hours == 12) // if we ended at 12 hours, we swap the meridiem
  	{meridiemSwap();}
  
  if (hours == 0){
  	hours += 12;
  }
  
  } // done with the subtract time function
  
}; // done with the class definitions

 int main()
 {
 int hours, // amount of hours the user inputted
     minutes; // amount of minutes the user inputted
     
 char timer[7], // this will store the finish time
      meridiem; // this is the meridiem the user inputted
 cout << "Enter the desired finish time (ex: 11:32pm): "; // time that everything must be done by
 cin >> timer; // storing input
 cout << "You entered " << timer << "\n"; // confirming to the user that their input was received
 cout << "Type '0 0' without the quotes to exit at any time\n\n"; // telling user how to exit
 

 if (timer[1]==':'){ // if the user entered single digit hours...
 
    hours = timer[0]-'0'; // storing hours from converting string to int
    minutes = (timer[2]-'0')*10+(timer[3]-'0'); // storing minutes
    meridiem = timer[4]; // storing meridiem
}
    
else{ // this means the user had double digit hours for input
 hours = (timer[0]-'0')*10+(timer[1]-'0');// storing hours from converting string to int
 minutes = (timer[3]-'0')*10+(timer[4]-'0'); // storing minutes
 meridiem = timer[5]; // storing meridiem
}

 Time time1; // making an object named time1 of the Time class
 time1.setTime(hours, minutes, meridiem); // setting the time to the finish time that the user entered
 
 int counter = 1; // counter for our loop to indicate which activity we are on
 while (true){ // adding in time for each activity
 
  cout << "Enter amount of time for activity " << counter << " (ex: 1 23 for 1 hr 23 mins): "; // asking for input
  cin >> hours >> minutes; // storing the hours and minutes input
 
  if (hours == 0 and minutes == 0) // if activity takes 0 time, then assume the user wants to quit
  {break;} // exiting our while loop
 
  time1.subtractTime(hours, minutes); // subtracting off the time that the user inputted
  counter+=1; // adding to our counter to store the activity number
}
 
 time1.printTime(); // printing out the start time necessary to finish at the desired finish time


 return 0;
 }
