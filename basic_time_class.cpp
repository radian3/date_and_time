// This program uses a class to represent time.
 #include <iostream>
 #include <cmath>
 #include <string>
 #include <cstdlib>
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
 	minutes = 0;
 	hours = 0;
 	meridiem = 'a';
 }
 
 void setTime(int hr, int min, char mer)
 { minutes = min; 
   hours = hr;
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
 int hours;
 int minutes;
 char timer[6];
 char meridiem;
 cout << "Enter the time (ex: 11:32pm): ";

 cin >> timer;
 string stuff = "12:34am";
 

 if (timer[1]==':'){
 
    hours = timer[0]-'0';
    minutes = (timer[2]-'0')*10+(timer[3]-'0');
    meridiem = timer[4];
}
    
else{
 hours = (timer[0]-'0')*10+(timer[1]-'0');
 minutes = (timer[3]-'0')*10+(timer[4]-'0');
 meridiem = timer[5];	
}

 Time time1;
 time1.setTime(hours, minutes, meridiem);
 time1.printTime();


 return 0;
 }
