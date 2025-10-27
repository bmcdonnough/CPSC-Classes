package Lab8.Views;


/**
 * This class servers as the View for my Class.
 * The view is how we would normally display information via a GUI. Since there's no GUI for this project, the View simply treats the console as the GUI and presents information by printing the info to the console.
 * The goal is to be able to use the console as a GUI for my Class model, which means I should see the information associated with my view printed to the GUI (console).
 * 
 * @author Matthew Re
 * 
 * Tip: Remember that Views and Models NEVER interact directly
 *
 */
public class ClassView 
{
	//TODO implement the printClassInformation function
	/**
	 * This functions "updates" my GUI by printing the information to the console. It should begin with the println statement: "Class Details:"
	 * 
	 * @param aClassName a class name to be printed in the format: "Name: <aClassName>"
	 * @param aClassNumber a class number to be printed in the format: "Class Number: <aClassNumber>"
	 * @param aClassDPT a class department to be printed in the format: "Class Department: <aClassDPT>"
	 * 
	 * @pre None
	 * 
	 * @post self = #self
	 * (remember, since this isn't a real GUI and we're using the console, the state of my view (the console) never technically changes)
	 */
	public void printClassInformation(String aClassName, int aClassNumber, String aClassDPT)
	{
		System.out.println("Class Details:");
		System.out.println("Name: " + aClassName);
		System.out.println("Class Number: " + aClassNumber);
		System.out.println("Class Department: " + aClassDPT);
	}
	
}
