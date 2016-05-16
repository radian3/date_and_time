package timeOperations;

class Time{ 
	
	 int hours; // 1-12
	 int minutes; // 0-59
	 String mer; // am or pm 
	 	 
	 Time (int hrs, int mins, String me){
		 hours = hrs;
		 minutes = mins;
		 mer = me;
	 }
	 
	 void meridiemSwap(){
		 if (mer == "am"){
			 mer = "pm";
		 }
		 else{
			 mer = "am";
		 }
		 
	 }
	 void printTime() {
	  String str = String.valueOf(hours);
	  str += ":";
	  if (minutes < 10){
		  str += "0" + String.valueOf(minutes);
	  }
	  else{
		  str += String.valueOf(minutes);
	  }
	  str += mer;
	  System.out.println(str);
	 }
	 
	 void addTime(int hrs, int mins){
		 if (hours == 12){
			 meridiemSwap();}
		 minutes += mins;
		 if (minutes >= 60){
			 hours += minutes/60;
			 minutes = minutes%60;
		 }	 
		 hours += hrs;
		 while (hours > 12){
			 hours -= 12;
			 meridiemSwap();
		 }		 
		 if (hours == 12){
			 meridiemSwap();
		 }
	 }
	 void subtractTime(int hrs, int mins){
		 if (hours == 12){
			 meridiemSwap();
		 }
		 minutes -= mins;
		 if (minutes < 0){
			 hours -= (-minutes/60)+1;
			 minutes = (minutes%60) + 60;
		 }
		 hours -= hrs;
		 while (hours < 0){
			 hours += 12;
			 meridiemSwap();
		 }
		 if (hours == 12){
			 meridiemSwap();
		 }
		 if (hours == 0){
			 hours += 12;
		 }
		 
	 } // subtractTime
} // class

public class main {
	
public static void main(String[] args){

	Time time1 = new Time(12, 14, "pm");
    time1.printTime();
}
}


