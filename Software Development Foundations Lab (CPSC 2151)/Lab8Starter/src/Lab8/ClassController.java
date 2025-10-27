package Lab8;
import Lab8.Models.*;
import Lab8.Views.*;


/**
 * This class serves as the controller between my class model and view.
 * It's the mediator between my model and view, so it has access to both of them.
 * 
 * HINT: Remember, we don't want to do error checking in the view since that's our true frontend, which will be slowed down if
 * it also has to do the error checking. We also don't do the error checking in the Models since we don't do in-method error checking
 * with true backend code when using design by contract. SO, if the error checking isn't done in the view, and it's not done in my 
 * model, where would I do my in-method error checking...?
 * 
 * @author Matthew Re
 *
 */
public class ClassController 
{
	private ClassModel myModel;
	private ClassView myView;

	private final int MIN_COURSE_NUM = 1000;
	private final int MAX_COURSE_NUM = 9999;
	private final int COURSE_NUM_LENGTH = 4;
	private final int COURSE_DPT_LENGTH = 4;

	
	public ClassController(ClassModel model, ClassView view)
	{
		this.myModel = model;
		this.myView = view;
	}
	
	/**
	 * this function gets the name of the class from myModel's getter
	 * 
	 * @pre None
	 * 
	 * @post getClassName = [myModel's className]
	 * 
	 * @return [the name associated with MyModel's class]
	 */
	//TODO implement
	public String getClassName()
	{
		return this.myModel.getClassName();
	}
	
	
	/**
	 * this function updates myModel's Name using myModel's setter
	 * 
	 * @param aName the name we want to set as the class's name
	 * 
	 * @pre |aName| > 0
	 * 
	 * @post myModel.ClassName = aName IFF |aName| > 0 ELSE myModel.ClassName = "NoValidNameSet" AND myView = #myView
	 * 
	 */
	//TODO implement
	public void setClassName(String aName)
	{
		if(!aName.isEmpty()){
			this.myModel.setClassName(aName);
		}
		else{
			this.myModel.setClassName("NoValidNameSet");
		}
	}
	
	
	/**
	 * this function gets the class number from myModel's getter
	 * 
	 * @pre None
	 * 
	 * @post getClassNumber = [myModel's classNumber]
	 * 
	 * @return [the class number associated with MyModel's class]
	 */
	//TODO implement
	public int getClassNumber()
	{
		return this.myModel.getClassNumber();
	}
	
	
	/**
	 * this function updates myModel's class number using myModel's setter
	 * 
	 * @param aNumber the number we want to set as the class's number
	 * 
	 * @pre MIN_COURSE_NUM < aNumber < MAX_COURSE_NUM AND |aNumber| == COURSE_NUM_LENGTH
	 * 
	 * @post myModel.ClassNumber = aNumber IFF MIN_COURSE_NUM < aNumber < MAX_COURSE_NUM && |aNumber| == COURSE_NUM_LENGTH, 
	 * ELSE myModel.ClassNumber = 0000 AND myView = #myView
	 * 
	 */
	//TODO implement
	public void setClassNumber(int aNumber)
	{
		if(aNumber > MIN_COURSE_NUM && aNumber < MAX_COURSE_NUM){
			this.myModel.setClassNumber(aNumber);
		}
		else {
			this.myModel.setClassNumber(0);
		}
	}
	
	
	/**
	 * this function gets the department from myModel's getter
	 * 
	 * @pre None
	 * 
	 * @post getClassDPT = [myModel's ClassDPT]
	 * 
	 * @return [the department associated with myModel's class]
	 */
	//TODO implement
	public String getClassDPT()
	{
		return this.myModel.getClassDPT();
	}
	
	
	/**
	 * this function updates myModel's class department using myModel's setter
	 * 
	 * @param aClassDPT the department we want to set as the class's department
	 * 
	 * @pre |aClassDPT| = COURSE_DPT_LENGTH
	 * 
	 * @post myModel.ClassDPT = aClassDPT IFF |aClassDPT| = COURSE_DPT_LENGTH, ELSE myModel.ClassDPT = "XXXX" AND myView = #myView
	 * 
	 */
	//TODO implement
	public void setClassDPT(String aClassDPT)
	{
		if(aClassDPT.length() == COURSE_DPT_LENGTH){
			this.myModel.setClassDPT(aClassDPT);
		}
		else{
			this.myModel.setClassDPT("XXXX");
		}
	}
	
	
	/**
	 * this function updates my view to accurately display the Model's information. Since my View is the console of an IDE and not a GUI, we display the Model's information by neatly printing it to the console.
	 * (note that this means the state of my view isn't 'technically' changing, since we're just printing)
	 *  
	 * @pre none
	 * 
	 * @post myModel = #myModel AND myView = #myView
	 * 
	 * IMPORTANT
	 *  
	 * Do NOT edit this function in any way. Doing so will result in a 0 for this lab.
	 */
	public void updateView()
	{
		myView.printClassInformation(myModel.getClassName(), myModel.getClassNumber(), myModel.getClassDPT());
	}
}
