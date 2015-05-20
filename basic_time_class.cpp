// This program demonstrates a simple class.
 #include <iostream>
 #include <cmath>
 using namespace std;

 // Circle class declaration
 class Time
 { 
 private:
 int minutes;
 int hours;
 string meridiem;


 public:
 
 Time()
 {
 	minutes = 0;
 	hours = 0;
 	meridiem = "am";
 }
 
 void setTime(int hr, int min, string mer)
 { minutes = min; 
   hours = hr;
   meridiem = mer;
   
 }
 int getMinutes()
 {
 	return minutes;
 }
 int getHours()
 {
 	return hours;
 }
 string getMeridiem()
 {
 	return meridiem;
 }
};
 int main()
 {
 int hours;
 int minutes;
 string meridiem;
 cout << "Enter the time in hours, minutes, meridiem separated by a space (ex: 7 35 pm):\n";
 cin >> hours >> minutes >> meridiem;
 Time time1;
 time1.setTime(hours, minutes, meridiem);
 cout << "\nYou entered: \n\n" << time1.getHours() << ":" << time1.getMinutes() << "" << time1.getMeridiem();
 


 return 0;
 }
