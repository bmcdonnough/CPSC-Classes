
public class songManager 
{
	public static final int MAX_SONGS = 10;
	private song[] songList;
	
	public songManager()
	{
		songList = new song[MAX_SONGS];
	}
	
	public songManager(int aSize)
	{
		songList = new song[aSize];
	}
	
	public void addSong(song aSong)
	{
		if(songList[songList.length-1] != null)
		{
			return;
		}
		else
		{
			for(int i = 0; i < songList.length; i++)
			{
				if(songList[i] == null)
				{
					songList[i] = aSong;
					break;
				}
			}
		}
	}
	
	public void remove(song aSong)
	{
		int songIndex = 0;
		
		if(songList[0] == null)
			return;

		//look for the song in the array
		for(int i = 0; i < songList.length; i++)
		{
			if(songList[i] == null)
			{
				//DO NOTHING
			}
			else if(songList[i].equals(aSong))
			{
				songIndex = i;
				break;
			}

		}

		//if the song was never found, exit the method
		if(songIndex == -1)
			return;

		//set the last item at the song index to null if that is the song we want to remove
		if(songIndex == songList.length-1)
		{
			songList[songIndex] = null;
			return;
		}

		//move all the other songs to the left-most position
		for(int i = songIndex; i < songList.length-1; i++)
		{
			songList[i] = songList[i+1];
			songList[i+1] = null;
		}
	}

	public void print()
	{
		for(int i = 0; i < songList.length; i++)
		{
			if(songList[i] != null)
				System.out.println(songList[i].toString());
		}
	}
	
	
}
