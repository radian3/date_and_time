// This program tells you how early you need to start each task in order to finish or arrive on time
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

  {cout << hours << ":" << "00" << meridiem << 'm' << "\n";}
  
  else if (minutes < 10) // need to have a 0 in the tens digit if the minutes are between 1 and 9 here
  {cout << hours << ":" << "0" << minutes << meridiem << 'm' << "\n";}	
  
 else // otherwise we don't have to worry about printing a 0 in the tens digit
 	{cout << hours << ":" << minutes << "" << meridiem << 'm' << "\n";}
  }
 
 void meridiemSwap(){ // changing from am to pm and vise-versa
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
  if (hours == 0){ // don't want to display 0 o'clock!
  	hours += 12;
  }	
 
  } // done with the subtract time function
  
  
}; // done with the class definitions

 int main()
 {
 int hours, // amount of hours the user inputted
     minutes, // amount of minutes the user inputted
     hrInp[20],
     minInp[20];
     
 char timer[7], // this will store the finish time
      meridiem; // this is the meridiem the user inputted
 cout << "Enter the time that all of the tasks must be done by (ex: 11:32pm): "; // time that everything must be done by
 cin >> timer; // storing input
 //cout << "You entered " << timer << "\n"; // confirming to the user that their input was received
 cout << "\nBelow, enter how long each task will take (ex: 3 27 for 3 hrs 27 mins)\n\n"; // telling user how to exit
 

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
 
 int counter = 0; // counter for our loop to indicate which activity we are on
 
 
 
 while (true){ // adding in time for each activity
 
  cout << "Enter how long task " << counter+1 << " will take (type 0 0 to exit): "; // asking for input
  cin >> hrInp[counter] >> minInp[counter]; // storing the hours and minutes input
 
  if (hrInp[counter] == 0 and minInp[counter] == 0) // if activity takes 0 time, then assume the user wants to quit
  {break;} // exiting our while loop
 
  counter+=1; // adding to our counter to store the activity number
}

cout << "\nYou requested to exit on task " << counter+1 << ". Thus there are " << counter << " tasks. \nCalculating time each task must be started in order to finish by " << timer;
cout << "...\n\n";
 
 
 for (int i = 0; i <= counter-1; i++) // calculating the time the first task needs to start by
 {
  time1.subtractTime(hrInp[i], minInp[i]); // subtracting off the time for each task from the finish time
  
 }
 
 for (int i = 0; i <= counter-1; i++) // now going to output each start time
 {
  cout << "Task " << i+1 << " must be started at ";
  time1.printTime(); // printing the time
  time1.addTime(hrInp[i], minInp[i]); // adding the time for the 1st - nth task (one at a time)
 }

 return 0;
 }
