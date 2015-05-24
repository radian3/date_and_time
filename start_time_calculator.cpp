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

  {cout << "\nYou must start at " << hours << ":" << "00" << meridiem << 'm' << "\n";}
  
  else if (minutes < 10)
  {cout << "\nYou must start at " << hours << ":" << "0" << minutes << meridiem << 'm' << "\n";}	
  
 else
 	{cout << "\nYou must start at " << hours << ":" << minutes << "" << meridiem << 'm' << "\n";}
  }
 
 void meridiemSwap(){
  if (meridiem == 'a')
  	{meridiem = 'p';}
  
  else
  {meridiem = 'a';}
  	
 }
 
 void subtractTime(int hrs, int mins){
 
  if (hours == 12)
  { meridiemSwap();}
  hours -= hrs;
  minutes -= mins;
  if (minutes < 0){
   hours -= (-minutes/60)+1;
   minutes = (minutes%60)+60;}
  if (hours < 0){
  hours += 12;
  meridiemSwap();}
  if (hours == 12)
  	{meridiemSwap();}
  } 
  
  
};
 int main()
 {
 int hours;
 int minutes;
 char timer[6];
 char meridiem;
 cout << "Enter the desired finish time (ex: 11:32pm): ";
 cin >> timer;
 cout << "You entered " << timer << "\n"; 
 cout << "Type '0 0' without the quotes to exit at any time\n\n";
 

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
 int counter = 1;
 while (true){
 
  cout << "Enter amount of time for activity " << counter << " (ex: 1 23 for 1 hr 23 mins): ";
  cin >> hours >> minutes;
  if (hours == 0 and minutes == 0)
  {break;}
  time1.subtractTime(hours, minutes);
  counter+=1;
}
 
 time1.printTime();


 return 0;
 }
