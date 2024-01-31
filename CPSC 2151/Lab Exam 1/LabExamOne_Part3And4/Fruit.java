/* Lab Exam 1 for CPSC2150 - Fall23.
 * 
 * This exam is to be completed INDIVIDUALLY.
 * 
 * Put your name (and anything else worth putting at the top of your .java files) below.
 * 
 * @Author
 * Benjamin McDonnough
 * I read the cheat-sheet
 */

 

import java.util.Calendar; //https://docs.oracle.com/javase/8/docs/api/java/util/Calendar.html
/**
 * This is a class for a fruit object. Fruits have names, expiration dates, ripeness, and prices.
 * Fruit is considered "expired" if it is passed its expiration date. To quickly sell the fruit
 * that are about to expire, fruit that is a week from its expiration date is marked 50% off.
 * 
 * @invariant name != "" AND price > 0 
 */
public class Fruit
{
    public static final Date SHIPMENT_DATE = new Date(2023, 10, 3); //the day which we received a shipment of this fruit
    private String name;
    private Date expirationDate;
    private Boolean isRipe;
    private double price;
    
    
    /**
     * constructor for the fruit object.
     * 
     * @param aName name to be set to the fruit's name instance variable
     * @param aPrice a double to be set to the fruit's price instance variable
     * 
     * @pre aName != "" AND aPrice > 0
     * 
     * @post name = aName AND [expirationDate is set to a new Fruit.Date with a year, month, and day equal to the SHIPMENT_DATE plus a week] AND
     * price = aPrice AND isRipe = setRipe().
     */
    public Fruit(String aName, double aPrice)
    {
        /*NOTE: You don't need to account for the month and year shifting forward after the day increases past 28/30/31. Just add a week to the
        shipment date's day. Unless you want to... Maybe I'd offer a few bonus points for that but you'd need to make sure you follow Date's 
        contracts at the bottom of this file.*/

        name = aName;
        price = aPrice;

        //Check if the shipment date is less than a week from the end of a month with 31 days
        if(SHIPMENT_DATE.getMonth() == 1 ||
                SHIPMENT_DATE.getMonth() == 3 ||
                SHIPMENT_DATE.getMonth() == 5 ||
                SHIPMENT_DATE.getMonth() == 7 ||
                SHIPMENT_DATE.getMonth() == 8 ||
                SHIPMENT_DATE.getMonth() == 10 ||
                SHIPMENT_DATE.getMonth() == 12 && (SHIPMENT_DATE.getDay() + 7 > Date.MAX_DAY_31))
        {
            //If the SHIPMENT_DATE month is December, than set the month to January and increase the year by one
            if(SHIPMENT_DATE.getMonth() == 12){
                expirationDate = new Date(SHIPMENT_DATE.getYear()+1, 1, ((SHIPMENT_DATE.getDay() + 7) - Date.MAX_DAY_31));
            }
            else{
                //If the month is not December, than increase the month by 1 and set the year to be the same as the
                //shipment date
                expirationDate = new Date(SHIPMENT_DATE.getYear(), SHIPMENT_DATE.getMonth()+1, ((SHIPMENT_DATE.getDay() + 7) - Date.MAX_DAY_31));
            }
        }
        //Check if the shipment date is less than a week from the end of a month with 30 days
        else if (SHIPMENT_DATE.getMonth() == 4 ||
                SHIPMENT_DATE.getMonth() == 6 ||
                SHIPMENT_DATE.getMonth() == 9 ||
                SHIPMENT_DATE.getMonth() == 11 && (SHIPMENT_DATE.getDay() + 7 > Date.MAX_DAY_30))
        {
            //If it is, then set the expiration date to be a week from the shipment date - the max days for that month
            //And increase the month by 1
            expirationDate = new Date(SHIPMENT_DATE.getYear(), SHIPMENT_DATE.getMonth()+1, ((SHIPMENT_DATE.getDay() + 7) - Date.MAX_DAY_30));
        }
        //Check if the shipment date is less than a week from the end of February 
        else if (SHIPMENT_DATE.getMonth() == 2 && (SHIPMENT_DATE.getDay() + 7 > Date.MAX_DAY_FEBRUARY))
        {
            //If it is, then set the expiration date to be a week from the shipment date - the max days for that month,
            //increase the month by one, and set the year equal to the shipment
            expirationDate = new Date(SHIPMENT_DATE.getYear(), SHIPMENT_DATE.getMonth()+1, ((SHIPMENT_DATE.getDay() + 7) - Date.MAX_DAY_FEBRUARY));
        }
        else {
            //If the shipment is more than a week from the end of the month, then set the eexpiration date to 
            //be a week later, set the month equal to the shipment date, and set the year equal to the shipment date
            expirationDate = new Date(SHIPMENT_DATE.getYear(), SHIPMENT_DATE.getMonth()+1, SHIPMENT_DATE.getDay());
        }
    }

    /**
     * used to determine if this instance of a fruit is still ripe.
     * 
     * @return a Boolean for whether the fruit is ripe or not.
     * 
     * @pre None
     * 
     * @post setRipe = [true IFF the current date is before expirationDate, false OW] AND name = #name AND expirationDate = #expirationDate
     * AND price = #price.
     */
    public Boolean setRipe()
    {
        if(Date.isBefore(Date.getCurrentDate(), expirationDate)){
            return true;
        }
        return false;
    }


    /**
     * Set's the fruit at the discounted rate of 50% off if it's expired.
     * 
     * @pre None
     * 
     * @post price = (#price * 0.5) IFF [the current date is on or after the expirationDate] ELSE price = #price AND name = #name AND
     * expirationDate = #expirationDate AND isRipe = #isRipe
     */
    public void updatePrice()
    {
        if(!(Date.isBefore(Date.getCurrentDate(), expirationDate))){
            price = price * 0.5;
        }
    }

    //------------DON'T EDIT ANYTHING BELOW THIS LINE-------BUT IT MIGHT BE HELPFUL TO AT LEAST LOOK...---------------------------------------------

    @Override
    public String toString() 
    {
        return "Fruit [name=" + name + ", expirationDate=" + expirationDate + ", isRipe=" + isRipe + ", price=" + price
                + "]";
    }

    /**
     * A private class for creating a date object since Java's calendar object is a pain in the rear to deal with.
     * 
     * @invariant aYear >= 0 
    * AND MIN_MONTH_AND_DAY <= aMonth <= MAX_MONTH 
    * AND aDay >= MIN_MONTH_AND_DAY
    * AND aDay <= MAX_DAY_31 IFF [Month equals the numeric equivalent of January, March, May, July,
    * August, October, or December] ELSE aDay <= MAX_DAY_30 IFF [Month equals the numeric 
    * equivalent of April, June, September, or November], aDay <= MAX_DAY_FEBRUARY ow.
     */
    private static class Date 
    {
        public static final int MAX_MONTH = 12;
        public static final int MIN_MONTH_AND_DAY = 1;
        public static final int MAX_DAY_31 = 31;
        public static final int MAX_DAY_30 = 30;
        public static final int MAX_DAY_FEBRUARY = 28;//CBA dealing with leap years...

        private int year;
        private int month;
        private int day;

        /**
         * constructor for the Date object.
         * 
         * @param aYear value to be set to the year component
         * @param aMonth value to be set to the month component
         * @param aDay value to be set to the year component
         * 
         * @pre aYear >= 0 
         * AND MIN_MONTH_AND_DAY <= aMonth <= MAX_MONTH 
         * AND aDay >= MIN_MONTH_AND_DAY
         * AND aDay <= MAX_DAY_31 IFF [Month equals the numeric equivalent of January, March, May, July,
         * August, October, or December] ELSE aDay <= MAX_DAY_30 IFF [Month equals the numeric 
         * equivalent of April, June, September, or November], aDay <= MAX_DAY_FEBRUARY ow.
         * 
         * @post year = aYear AND month = aMonth AND day = aDay
         */
        public Date(int aYear, int aMonth, int aDay)
        {
            year = aYear;
            month = aMonth;
            day = aDay;
        }

        /**
         * gets the year component of the date
         * @return the year
         * 
         * @pre None
         * 
         * @post getYear = year AND year = #year AND month = #month AND day = #day
         */
        public int getYear() {
            return year;
        }

        /**
         * sets the year component of the date
         * 
         * @param year value to be set as the year
         * 
         * @pre year > 0
         * 
         * @post year = aYear AND month = #month AND day = #day
         */
        public void setYear(int aYear) {
            this.year = aYear;
        }

        /**
         * gets the Month component of the date
         * @return the Month
         * 
         * @pre None
         * 
         * @post getMonth = Month AND year = #year AND month = #month AND day = #day
         */
        public int getMonth() {
            return month;
        }

        /**
         * sets the value for the month component of the Date
         * 
         * @param aMonth value to be set as the month
         * 
         * @pre MIN_MONTH_AND_DAY <= aMonth <= MAX_MONTH
         * 
         * @post month = aMonth
         */
        public void setMonth(int aMonth) {
            this.month = aMonth;
        }

        /**
         * gets the Day component of the date
         * @return the day
         * 
         * @pre None
         * 
         * @post getDay = day AND year = #year AND month = #month AND day = #day
         */
        public int getDay() {
            return day;
        }

        /**
         * sets the value for the day component of the date
         * 
         * @param aDay the value to be set as the Day
         * 
         * @pre aDay >= MIN_MONTH_AND_DAY AND aDay <= MAX_DAY_31 IFF [Month equals the numeric equivalent
         * of January, March, May, July, August, October, or December] ELSE aDay <= MAX_DAY_30 IFF [Month 
         * equals the numeric equivalent of April, June, September, or November], aDay <= MAX_DAY_FEBRUARY ow.
         * 
         * @post day = aDay
         */
        public void setDay(int aDay) {
            this.day = aDay;
        }

        /**
         * gets the current IRL date.
         * 
         * @return a Date object with the IRL date set to year, month, and day.
         * 
         * @pre None
         * 
         * @post getCurrentDate = [the current IRL date obtained from the instance of a java.util.Calendar getInstance function as a Date object]
         */
        public static Date getCurrentDate()
        {
            Calendar cal = Calendar.getInstance();
            Date ret = new Date(cal.get(Calendar.YEAR), cal.get(Calendar.MONTH)+1, cal.get(Calendar.DAY_OF_MONTH));
            return ret;
        }

        /**
         * returns true based on if Date x comes before Date y, ignoring leap years.
         * 
         * @param x Date to see if it comes before Date y.
         * @param y Date being compared with Date x.
         * @return Boolean true if Date x comes before Date y, false ow.
         * 
         * @pre None
         * 
         * @post isBefore = [true IFF Date x comes before Date y, false ow]. (Note: there's no "state of the object" because this
         * function is static; it's not called on an object).
         */
        public static Boolean isBefore(Date x, Date y)
        {
            if(x.getYear() > y.getYear())
                return false;
            else if (x.getYear() < y.getYear())
                return true;
            else
            {
                if(x.getMonth() > y.getMonth())
                    return false;
                else if (x.getMonth() < y.getMonth())
                    return true;
                else
                {
                    if(x.getDay() < y.getDay())
                        return true;
                    else
                        return false;
                }
            }
        }

        @Override
        public String toString() {
            return "[year=" + year + ", month=" + month + ", day=" + day + "]";
        }
    }

    

}
