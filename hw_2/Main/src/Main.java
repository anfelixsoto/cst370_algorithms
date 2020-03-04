/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/time-difference-2/submissions/code/1320363075
 * Title: hw2_2.java
 * Abstract: Reads two timestamps of two events from a user and displays the difference between the two timestamps.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/3/2020
 * https://mkyong.com/java/how-to-calculate-date-time-difference-in-java/ help with the convert and using
 * using long and the simple date format.
 */

import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String timestamp1 = sc.nextLine();
        String timestamp2 = sc.nextLine();

        sc.close();
        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");
        
        Date t1 = null;
        Date t2 = null;
        
        try{
            t1 = dateFormat.parse(timestamp1);
            t2 = dateFormat.parse(timestamp2);
            
            long difference = t2.getTime() - t1.getTime();
            
            long seconds = difference / 1000 % 60;
            long minutes = difference / (60 * 1000) % 60;
            long hours = difference / (60 * 60 * 1000) % 24;
            
            System.out.println(timeCheck(hours, minutes, seconds));
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static String timeCheck(long hour, long minute, long second){
        //System.out.println(hour + ":" + minute + ":" + second);
        String hr, min, sec;
        if(hour < 0){
            hour += 23;
        }
        
        if(minute < 0){
            minute += 59;
        }
        
        if(second < 0){
            second += 60;
        }
        
        if(hour < 10){
            hr = "0" + hour;
        }else{
            hr = Long.toString(hour);
        }
        
        if(minute < 10){
            min = "0" + minute;
        }else{
            min = Long.toString(minute);
        }
        
        if(second < 10){
            sec = "0" + second;
        }else{
            sec = Long.toString(second);
        }
        return hr + ":" + min + ":" + sec;
    }
}