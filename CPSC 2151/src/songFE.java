
public class songFE 
{
	
	public static void main(String[] args) 
	{
		songManager songList = new songManager();
	
		song song01 = new song("Breathe", 0, 3.2);
		song song02 = new song("Castles", 0, 2);
		song song03 = new song("Fingerprints (ft. Grace Grundy)", 0, 3.5);
		song song04 = new song("Anchor", 0, 6);
		song song05 = new song("Now or Never (Radio Edit)", 0, 2.1);


		songList.addSong(song01);
		songList.addSong(song02);
		songList.addSong(song03);
		songList.addSong(song04);
		songList.addSong(song05);

				
		songList.print();
		
		songList.remove(song05);
		
		System.out.println("\nDeleted song 5, \"Now or Never (Radio Edit)\" from the song list, reprinting\n");
		songList.print();


		
	
	}
}
