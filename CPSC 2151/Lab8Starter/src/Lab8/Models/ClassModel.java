package Lab8.Models;


/**
 * This class servers as the Model for my Class.
 * For this particular model, the model is a component of my Model layer that holds encapsulated data that pertains to a class.
 * 
 * @author Matthew Re
 * 
 * @invariant ClassName.length() > 0 AND 0 < ClassNumber < 9999 AND ClassDPT.length() == 4
 *
 */
public class ClassModel 
{
	private String ClassName; //the name of my class
	private int ClassNumber; //the class number
	private String ClassDPT; //the class department, a 4 letter abbreviation (like "CPSC")
	

	/*Notice thatthere's no constructor... One isn't needed since java will provide a default one for us. Since we're not using a
	* parameterized constructor using Java's given default one is fine. 
	*/

	//TODO: Implement all of ClassModel's functions.
	
	/**
	 * A standard getter for the name of the class.
	 * 
	 * @return the className
	 * 
	 * @pre None
	 * 
	 * @post getClassName = ClassName AND ClassName = #ClassName AND ClassNumber = #ClassNumber AND ClassDPT = #ClassDPT
	 */
	public String getClassName() {
		return ClassName;
	}
	
	
	/**
	 * A standard setter for the name of the class.
	 * 
	 * @param aClassName the className to set
	 * 
	 * @pre |aClassName| > 0
	 * 
	 * @post className = aClassName AND ClassNumber = #ClassNumber AND ClassDPT = #ClassDPT
	 */
	public void setClassName(String aClassName) {
		ClassName = aClassName;
	}
	
	
	/**
	 * A standard getter for the Number associated with the class.
	 * 
	 * @return the ClassNumber field, an int.
	 * 
	 * @pre None
	 * 
	 * @post getClassNumber = ClassNumber AND ClassName = #ClassName AND ClassNumber = #ClassNumber AND ClassDPT = #ClassDPT
	 */
	public int getClassNumber() {
		return ClassNumber;
	}
	
	
	/**
	 * A standard setter for ClassNumber.
	 * 
	 * @param aClassNumber the classNumber to set
	 * 
	 * @pre 0 < aClassNumber < 9999
	 * 
	 * @post ClassNumber = aClassNumber AND ClassDPT = #ClassDPT AND ClassName = #ClassName
	 */
	public void setClassNumber(int aClassNumber) {
		ClassNumber = aClassNumber;
	}
	
	
	/**
	 * A standard getter for the class department.
	 * 
	 * @return the classDPT
	 * 
	 * @pre None.
	 * 
	 * @post getClassDPT = ClassDPT AND ClassName = #ClassName AND ClassNumber = #ClassNumber AND ClassDPT = #ClassDPT
	 */
	public String getClassDPT() {
		return ClassDPT;
	}
	
	
	/**
	 * A standard setter for the class department. 
	 * 
	 * @param aClassDPT the classDPT to set
	 * 
	 * @pre |aClassDPT| = 4
	 * 
	 * @post ClassDPT = aClassDPT AND ClassName = #ClassName AND ClassNumber = #ClassNumber
	 */
	public void setClassDPT(String aClassDPT) {
		ClassDPT = aClassDPT;
	}
}
