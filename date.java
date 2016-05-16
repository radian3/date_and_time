package main;

class Date{
	
	int month;
	int day;
	int year;
	
	Date(int m, int d, int y){
		month = m;
		day = d;
		year = y;
	}
	
	void printDate(){
		String str;
		if (month < 10){
			str = "0" + String.valueOf(month);	
		}
		else{
			str = String.valueOf(month);
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
	
	void addDays(int addDays){

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
	 } // done with subDays
} // Date


public class main {

	public static void main(String[] args){
	
	Date date1 = new Date(4, 27, 1993);
	date1.printDate();

	}
}
