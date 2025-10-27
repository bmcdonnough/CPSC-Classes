package Lab8;
import Lab8.Models.*;
import Lab8.Views.*;


public class MVCMain {

	public static void main(String[] args) 
	{
		
		/*
		 * IMPORTANT 
		 * you are NOT allowed to edit this file in ANY way. Any modifications to this file will result in an automatic 0 to this Lab.
		 */
		
		ClassModel model = getClassFromDB();
		
		ClassView view = new ClassView();
		
		ClassController controller = new ClassController(model, view);
		
		controller.updateView();
		
		System.out.println("\nUpdating view...\n");
		controller.setClassName("From Coder to Craftsman");
		controller.setClassNumber(2180);
		
		controller.updateView();
	}
	
	private static ClassModel getClassFromDB() 
	{
		ClassModel myClass = new ClassModel();
		myClass.setClassName("Software Dev Foundations");
		myClass.setClassNumber(2150);
		myClass.setClassDPT("CPSC");
		return myClass;
	}

}
