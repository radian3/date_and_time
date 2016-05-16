import java.util.Scanner;

class DateandTime{
	int month;
	int day;
	int year;
	int hours;
	int minutes;
	String mer;
	String dayOfWeek;
	
	void daysOfWeek(){ // calculatse the day of week
		int q = day;
		int m;
		String days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
		if (month <= 2){
			m = month + 12;
		}
		else{
			m = month;
		}
		int K = year%100;
		int J = year/100;
		
		int h = (q + (13*(m+1)/5) + K + K/4 + J/4 - 2*J)%7;
		dayOfWeek = days[h];
	}
	

	
	DateandTime(int mo, int d, int y, int h, int mi, String me){ // constructor
		month = mo;
		day = d;
		year = y;
		hours = h;
		minutes = mi;
		mer = me;
		daysOfWeek();
	}
	
	String StringOfDayAndTime(){
		 String str = dayOfWeek + " ";
		  str += String.valueOf(hours);
		  str += ":";
		  if (minutes < 10){
			  str += "0" + String.valueOf(minutes);
		  }
		  else{
			  str += String.valueOf(minutes);
		  }
		  str += mer;
		  
		  str += " ";
			if (month < 10){
				str += "0" + String.valueOf(month);	
			}
			else{
				str += String.valueOf(month);
			}
			str += "/";
			if (day < 10){
				str += "0" + String.valueOf(day);
			}
			else{
				str += String.valueOf(day);
			}
			str += "/";
			str += String.valueOf(year);
			return str;
	}
	void printDayandTime(){
		  String str = dayOfWeek + " ";
		  str += String.valueOf(hours);
		  str += ":";
		  if (minutes < 10){
			  str += "0" + String.valueOf(minutes);
		  }
		  else{
			  str += String.valueOf(minutes);
		  }
		  str += mer;
		  
		  str += " ";
			if (month < 10){
				str += "0" + String.valueOf(month);	
			}
			else{
				str += String.valueOf(month);
			}
			str += "/";
			if (day < 10){
				str += "0" + String.valueOf(day);
			}
			else{
				str += String.valueOf(day);
			}
			str += "/";
			str += String.valueOf(year);
			System.out.println(str);
	}
	
	void meridiemSwap(){
		 if (mer == "am"){
			 mer = "pm";
		 }
		 else{
			 mer = "am";
		 }
		 
	 }
	
	void addDays(int addDays){ // adds days to a date

		  int daylist[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		  int daysLeft = daylist[month] - day;
		  
		  while (daysLeft < addDays){
			  addDays -= daysLeft;
			  day = 0;
			  month++;
			  if (month > 12){
				  month = 1;
				  year += 1;	 
			  }
			  if (month == 2 && ((year%4 == 0 && year%100 != 0) || year%400 == 0)){
				  daysLeft = 29 - day;
			  }
			  else{
				  daysLeft = daylist[month];
			  }  
		  } // while
		  day += addDays;
		  daysOfWeek();
	}
	
	 void subDays(int subDays){ // subtracting days from the current day (used to compute the start date)
		
		  int daylist[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  
		  while (true){
			if (day >= subDays){  
			  day -= subDays;
			  break;}
			else{
			  subDays -= day;
			  month--;
			  if (month < 1){
				  month = 12;
				  year--;
			  }
			  if (month == 2 && ((year%4 == 0 && year%100 != 0) || year%400 == 0)){
				  day = 29;
			  }
			  else{
				  day = daylist[month];}
			  }
			  
		  } // while
		 
		  if (day == 0) {
		    month -= 1;
		  	if (month < 1){
		  		month = 12;
		  		year -= 1;
		  		if (year < 0){
		  			year = 99;
				  }
			  }
			day = daylist[month];
		 }
		 daysOfWeek();
	 } // done with subDays
	 void toMilitary(){ // converts to military time
	  if (hours == 12 && mer == "am"){
		  hours = 0;
	  }
	  else if (mer == "pm" && hours != 12){
		  hours += 12;
	  }
	 }
	 void fromMilitary(){ // converts from military time back to normal
		 if (hours < 12){
			 mer = "am";
		 }
		 else{
			 mer = "pm";
		 }
		 if (hours == 0){
			 hours += 12;
		 }
		 if (hours > 12){
			 hours -= 12;
		 }
	 }
	 void addTime(int hrs, int mins, int daysToAdd){ // adds time to a date
		int extraDays = 0;
		toMilitary();
		minutes += mins;
		while(minutes >= 60){
			hours++;
			minutes -= 60;
		}
		hours += hrs;
		while (hours > 23){
			hours -= 24;
			extraDays++;
		}
		fromMilitary();
		addDays(daysToAdd + extraDays); 
		 }
	 
	 void subtractTime(int hrs, int mins, int daysToSub){ // subtracts time from a date
		int extraDays = 0;
		toMilitary();
		minutes -= mins;
		while (minutes < 0){
			minutes += 60;
			hours--;
		}
		hours -= hrs;
		while (hours < 0){
			hours += 24;
			extraDays++;
		}
		fromMilitary();
		subDays(daysToSub + extraDays);
	 } // subtractTime
	 
	 void timeBetween(DateandTime t1){ // prints out the time between two dateandtimes
		 int numDays = 0;
		 int hoursToAdd = 0;
		 int minutesToAdd = 0;
		 int daylist[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		 String timesBetween = "";
		 int tempDay = day;
		 int tempMonth = month;
		 int tempYear = year;
		 int tempHours = hours;
		 int tempMinutes = minutes;
		 String tempDayOfWeek = dayOfWeek;
		 toMilitary();
		 t1.toMilitary();
		 
		 if (day != t1.day || month != t1.month || year != t1.year){
		 hoursToAdd += 23 - hours;
		 minutesToAdd += 60 - minutes;
		 addDays(1);
		 hours = 0;
		 minutes = 0; }
		 while (month != t1.month || year != t1.year){
			 if (month == 2 && ((year%4 == 0 && year%100 != 0) || year%400 == 0)){
                 numDays += 29-day;
             }
             else{
                 numDays += daylist[month] - day;
             }
			 day = 0;
			 month++;
			 if (month > 12){
				 month = 1;
				 year++;
			 }
		 } // while
   
         numDays += t1.day - day;
         hoursToAdd += t1.hours - hours;
         minutesToAdd += t1.minutes - minutes;
         hoursToAdd += minutesToAdd/60;
         minutesToAdd = minutesToAdd%60;
         numDays += hoursToAdd/24;
         hoursToAdd = hoursToAdd%24;
		 
		 timesBetween = String.valueOf(numDays);
		 timesBetween += " days, ";
		 timesBetween += String.valueOf(hoursToAdd);
		 timesBetween += " hours, ";
		 timesBetween += String.valueOf(minutesToAdd);
		 timesBetween += " minutes";
		 System.out.println(timesBetween);
		 
		 month = tempMonth;
		 day = tempDay;
		 year = tempYear;
		 hours = tempHours;
		 minutes = tempMinutes;
		 dayOfWeek = tempDayOfWeek;
		 t1.fromMilitary();
		 
	 } // timeBetween
} // DateandTime class


public class main {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		 int hr1, min1, mon1, day1, year1;
		 int hr2, min2, mon2, day2, year2;
		 String mer1, mer2;
		 System.out.print("Please enter a date (mm/dd/yyyy): ");
		 String date1 = input.nextLine();
		 System.out.print("Please enter a time (ex: 2:32pm): ");
    	 String time1 = input.nextLine(); // length = 6 or 7
		 mon1 = Integer.parseInt(date1.substring(0, date1.indexOf('/')));
		 day1 = Integer.parseInt(date1.substring(date1.indexOf('/')+1, date1.indexOf('/')+3));
		 year1 = Integer.parseInt(date1.substring(date1.indexOf('/')+4, date1.indexOf('/')+8));
		 hr1 = Integer.parseInt(time1.substring(0, time1.indexOf(':')));	 
		 min1 = Integer.parseInt(time1.substring(time1.indexOf(':')+1, time1.indexOf(':')+3));
		 mer1 = (time1.substring(time1.indexOf(':')+3, time1.indexOf(':')+5));
	
		 DateandTime t1;
		 if (mer1.equals("pm")) { t1 = new DateandTime(mon1, day1, year1, hr1, min1, "pm");}
		 else{ t1 = new DateandTime(mon1, day1, year1, hr1, min1, "am");}
		 System.out.print("A single Date & Time object 1 has been created for: ");
		 t1.printDayandTime();
		 
		 System.out.print("Please enter a date (mm/dd/yyyy): ");
		 String date2 = input.nextLine();
		 System.out.print("Please enter a time (ex: 2:32pm): ");
    	 String time2 = input.nextLine(); // length = 6 or 7
		 mon2 = Integer.parseInt(date2.substring(0, date2.indexOf('/')));
		 day2 = Integer.parseInt(date2.substring(date2.indexOf('/')+1, date2.indexOf('/')+3));
		 year2 = Integer.parseInt(date2.substring(date2.indexOf('/')+4, date2.indexOf('/')+8));
		 hr2 = Integer.parseInt(time2.substring(0, time2.indexOf(':')));	 
		 min2 = Integer.parseInt(time2.substring(time2.indexOf(':')+1, time2.indexOf(':')+3));
		 mer2 = (time2.substring(time2.indexOf(':')+3, time2.indexOf(':')+5));
	
		 DateandTime t2;
		 if (mer2.equals("pm")) { t2 = new DateandTime(mon2, day2, year2, hr2, min2, "pm");}
		 else{ t2 = new DateandTime(mon2, day2, year2, hr2, min2, "am");}
		 System.out.print("A single Date & Time object 2 has been created for: ");
		 t2.printDayandTime();
		 System.out.println("Time to try out some functions!");
		 System.out.print("The time between the two Date & Times is ");
		 t1.timeBetween(t2);
		 System.out.print("Enter how many days to add to object 1: ");
		 int daysToAdd = input.nextInt();
		 System.out.print("Enter how many hours to add to object 1: ");
		 int hrsToAdd = input.nextInt();
		 System.out.print("Enter how many minutes to add to object 1: ");
		 int minsToAdd = input.nextInt();
		 String str1 = t1.StringOfDayAndTime();
		 t1.addTime(hrsToAdd, minsToAdd, daysToAdd);
		 String str2 = t1.StringOfDayAndTime();
		 System.out.print("Object has changed from " + str1 + " to " + str2 + "\n");
		 System.out.print("Enter how many days to subtract from object 1: ");
		 int daysToSub = input.nextInt();
		 System.out.print("Enter how many hours to subtract from object 1: ");
		 int hrsToSub = input.nextInt();
		 System.out.print("Enter how many minutes to subtract from object 1: ");
		 int minsToSub = input.nextInt();
		 input.close();
		 String str3 = t1.StringOfDayAndTime();
		 t1.subtractTime(hrsToSub, minsToSub, daysToSub);
		 String str4 = t1.StringOfDayAndTime();
		 System.out.print("Object has changed from " + str3 + " to " + str4 + "\n"); 
		}
}
