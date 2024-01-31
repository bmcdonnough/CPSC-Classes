/* Lab Exam 1 for CPSC2150 - Fall23.
 * 
 * This exam is to be completed INDIVIDUALLY.
 * 
 * Put your name (and anything else worth putting at the top of your .java files) below.
 * 
 * @Author Benjamin McDonnough
 * I read the cheat-sheet
 */



import java.lang.Math;
/*
 * Directions: Write the contracts. for the functions based on their implementation.
 * Hint: You're only working with 3 different potential shapes. This is something that
 * perhaps the class contract would be interested in knowing...
 */



/**
 * This is a class for a shape object. Shapes have lenghts, widths, areas, and number of sides. Can calculate the area
 * and/or the perimeter of a Shape if the shape has 4 equal sides, 4 unequal sides, or zero sides.
 * 
 * @invariant length = aLength AND width = aWidth AND numOfSides = ANS AND area = calculateArea()
 */
public class Shape {

    private double length;
    private double width;
    private double area;
    private int numOfSides;

    /**
     * constructor for the shape object
     * 
     * @param aLength a double to be set to the shape's length
     * @param aWidth a double to be set to the shape's width
     * @param ANS an int to be set to the number of sides of the shape
     * 
     * @pre aLength > 0 AND aWidth > 0 AND ANS >= 0
     *
     * @post length = aLength AND width = aWidth AND numOfSides = ANS  AND area = calculateArea()
     */
    public Shape(double aLength, double aWidth, int ANS)
    {
        this.length = aLength;
        this.width = aWidth;
        this.numOfSides = ANS;
        calculateArea();     
    }


    /**
     * sets the values for the length and height
     * 
     * @pre [aLength is equal to -1 and/or aWidth is equal to -1]
     *
     * @post IFF aLength = -1 THEN width = aWidth
     * @post IFF aWidth = -1 THEN length = aLength
     * @post IFF aLength = -1 AND aWidth = -1 THEN length = #length and width = #width
     */
    public void setDimensions(double aLength, double aWidth)
    {
        if(aLength == -1)
        {
            this.width = aWidth;
            calculateArea();
        }
        if(aWidth == -1)
        {
            this.length = aLength;
            calculateArea();
        }
        if(aLength == -1 && aWidth == -1)
        {
            return;
        }
    }

    /**
     * used to calculate the area of this instance of a shape
     * 
     * @pre None
     * 
     * @post area = length * width IFF numOfSides = 4 ELSE area = Pi * length/2 * width/2 IFF numOfSides = 0 ELSE
     * area = #area 
     * @post length = #length AND width = #width AND numOfSides = #numOfSides
     */
    public void calculateArea()
    {
        if(this.numOfSides == 4)//a shape of 4 sides...
        {
            this.area = (this.length * this.width);
        }
        else if(this.numOfSides == 0)//an Ellipse
        {
            this.area = (Math.PI * (this.length/2.0) * (this.width/2.0));
        }
        else
        {
            System.out.println("Unable to calculate the area of this shape in the current version...");
            /*note: in the future, we'll talk about when it's appropriate to throw exceptions. For now,
            just know that the point of this print statement is to tell the user that the system isn't
            built to recognize any other shapes based on the number of sides.*/
        }

    }

    /**
     * used to calculate the perimeter of this instance of a shape
     *
     * @return a double that is "equal"(as much as possible) to the perimeter of the shape
     *
     * @pre None
     *
     * @post length = #length AND width = #width AND area = #area AND numOfSides = #numOfSides
     * @post returns (length * 2) + (width * 2) IFF numOfSides = 4 AND length != width ELSE
     *       returns length * 4 IFF numOfSides = 4 AND length = width ELSE
     *       returns Pi * (length * width) IFF numOfSides = 0 ELSE
     *       returns -200
     */
    public double calcPerimeter()
    {
        if(this.numOfSides == 4 && (this.length != this.width))//a shape of 4 sides, but they aren't equal...
        {
            return ((this.length * 2.0) + (this.width * 2.0));
        }
        else if (this.numOfSides == 4 && this.length == this.width)//a shape of 4 sides, but they are equal...
        {
            return (this.length * 4.0);
        }
        else if(this.numOfSides == 0)//an Ellipse
        {
            //did you know it's near impossible to get the exact perimeter of an ellipse?
            //this will give an "accurate enough" approximation.
            return (Math.PI * (this.length * this.width));
        }
        else
        {
            return -200; 
            /*Similar idea as the area function. We'll talk about appropriate times 
            to use an "error code" closer to the front-end unit. For now just know the idea
            is to return code -200 to tell the user that the system isn't
            built to recognize any other shapes based on the current number of sides*/
        }
    }



}