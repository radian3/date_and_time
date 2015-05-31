// This program uses a class to represent time.
 #include <iostream>
 #include <cmath>
 #include <string>
 #include <cstdlib>
 using namespace std;

 class Time // starting our class
 { 
 private: 
 int hours,
     minutes;
 char meridiem;


 public:
 
 Time() // constructor
 {
 	hours = 0;
  	minutes = 0;
 	meridiem = 'a';
 }
 
 void setTime(int hr, int min, char mer)
 {  
   hours = hr;
   minutes = min; 
   meridiem = mer;
   
 }
 int getMinutes()
  {return minutes;}

 int getHours()
  {return hours;}
  
 char getMeridiem()
  {return meridiem;}
 
 
   void printTime()
  {
  if (minutes == 0)

  {cout << "\nYou entered: " << hours << ":" << "00" << meridiem << 'm' << "\n";}
  
  else if (minutes < 10)
  {cout << "\nYou entered:  " << hours << ":" << "0" << minutes << meridiem << 'm' << "\n";}	
  
 else
 	{cout << "\nYou entered: " << hours << ":" << minutes << "" << meridiem << 'm' << "\n";}
  }
};
 
int main()
{
 int hours,
     minutes;
 
 char timer[7],
      meridiem;
 
 cout << "Enter the time (ex: 11:32pm): ";
 cin >> timer; 

 if (timer[1]==':') // checking if the hours the user entered was 1-9
 {
 
    hours = timer[0]-'0'; // computing the hours from the input
    minutes = (timer[2]-'0')*10+(timer[3]-'0'); // computing the minutes from the input
    meridiem = timer[4]; // exctracting the meridiem
 }
    
else // user entered 10, 11, or 12 as the hours
 {
 hours = (timer[0]-'0')*10+(timer[1]-'0');
 minutes = (timer[3]-'0')*10+(timer[4]-'0');
 meridiem = timer[5];	
 }

 Time time1; // making an object named time1 out of the Time class
 time1.setTime(hours, minutes, meridiem); // setting the time to the user input
 time1.printTime(); // printing the time


 return 0;
}
