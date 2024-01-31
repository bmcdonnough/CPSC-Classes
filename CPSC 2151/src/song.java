
public class song 
{
	private String name;
	private double startTime, endTime;
	
	public song()
	{
		this.name = "NoName";
		this.startTime = 0.00;
		this.endTime = 5.00;
	}
	
	public song(String aName, double aStart, double anEnd)
	{
		this.setName(aName);
		this.setStart(aStart);
		this.setEnd(anEnd);
	}
	
	//accessors
	public String getName()
	{
		return this.name;
	}
	
	public double getStart()
	{
		return this.startTime;
	}
	
	public double getEnd()
	{
		return this.endTime;
	}
	
	//mutators
	public void setName(String aName)
	{
		this.name = aName;
	}
	
	public void setStart(double aStart)
	{
		if(aStart > 0)
			this.startTime = aStart;
	}
	
	public void setEnd(double anEnd)
	{
		if(anEnd < 10 && anEnd > 0)
			this.endTime = anEnd;
	}
	
	public String toString()
	{
		String ret;
		
		ret = "Name: " + this.name + " Start time: " + this.startTime + " End time: " + this.endTime;
		
		return ret;
	}
	
	public boolean equals(song aSong)
	{
		boolean ret = false;
		
		if(this.name.equals(aSong.getName()) && this.startTime == aSong.getStart() && this.endTime == aSong.getEnd())
			ret = true;
		
		return ret;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
