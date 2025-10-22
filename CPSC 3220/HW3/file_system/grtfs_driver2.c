/* test driver */

#include "grtfs.h"

int main(){
  unsigned int fd[40];
  char buffer1[1024], buffer2[1024], buffer3[1024];
  unsigned int length1, length2, count1, count2, count3;

  sprintf( buffer1, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 64, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 128, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 192, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 256, "%s",
    "This is a simple-minded test for the trivial file system code.  " );

  sprintf( buffer2, "%s",
    "And now for something completely different." );

  length1 = strlen( buffer1 );
  length2 = strlen( buffer2 );
  printf( "length of buffer1 is %d\n", length1 );
  printf( "length of buffer2 is %d\n", length2 );

  grtfs_init();

  grtfs_list_directory();

  fd[0] = grtfs_create( "file.txt" );
  if( fd[0] == 0 ) printf( "first create failed\n" );

  fd[1] = grtfs_create( "my_file" );
  if( fd[1] == 0 ) printf( "second create failed\n" );

  grtfs_list_directory();

  count1 = grtfs_write( fd[0], buffer1, length1 );
  printf( "%d bytes written to first file\n", count1 );

  count2 = grtfs_write( fd[1], buffer2, length2 );
  printf( "%d bytes written to second file\n", count2 );

  count1 = grtfs_write( fd[0], buffer1, length1 );
  printf( "%d bytes written to first file\n", count1 );

  grtfs_close( fd[1] );

  grtfs_list_directory();
  grtfs_list_blocks();

  grtfs_seek( fd[0], 600 );
  count3 = grtfs_read( fd[0], buffer3, 640 );
  printf( "%d bytes read from first file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_seek( fd[0], 250 );
  count3 = grtfs_read( fd[0], buffer3, 20 );
  printf( "%d bytes read from first file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  fd[2] = grtfs_create( "file.txt" );
  printf( "fd for creating a file with identical name" );
  printf( " as existing file - %d\n", fd[2] );
  fd[2] = grtfs_create( "file3" );
  fd[3] = grtfs_create( "file4" );
  fd[4] = grtfs_create( "file5" );
  fd[5] = grtfs_create( "file6" );
  fd[6] = grtfs_create( "file7" );
  fd[7] = grtfs_create( "file8" );
  fd[8] = grtfs_create( "file9" );
  fd[9] = grtfs_create( "file10" );
  fd[10] = grtfs_create( "file11" );
  fd[11] = grtfs_create( "file12" );
  fd[12] = grtfs_create( "file13" );
  fd[13] = grtfs_create( "file14" );
  fd[14] = grtfs_create( "file15" );
  fd[15] = grtfs_create( "file16" );
  fd[16] = grtfs_create( "file17" );
  fd[17] = grtfs_create( "file18" );
  fd[18] = grtfs_create( "file19" );
  fd[19] = grtfs_create( "file20" );
  fd[20] = grtfs_create( "file21" );
  fd[21] = grtfs_create( "file22" );
  fd[22] = grtfs_create( "file23" );
  fd[23] = grtfs_create( "file24" );
  fd[24] = grtfs_create( "file25" );
  fd[25] = grtfs_create( "file26" );
  fd[26] = grtfs_create( "file27" );
  fd[27] = grtfs_create( "file28" );
  fd[28] = grtfs_create( "file29" );
  fd[29] = grtfs_create( "file30" );
  fd[30] = grtfs_create( "file31" );
  fd[31] = grtfs_create( "file32" );
  printf( "fd for creating a 32nd file - %d\n", fd[32] );

  grtfs_list_directory();

  grtfs_close( fd[0] );
  grtfs_delete( fd[0] );

  grtfs_list_directory();

  grtfs_close( fd[3] );
  grtfs_close( fd[4] );
  grtfs_close( fd[5] );
  grtfs_close( fd[6] );
  grtfs_close( fd[7] );

  grtfs_delete( fd[6] );
  grtfs_delete( fd[7] );

  grtfs_list_directory();

  fd[32] = grtfs_create( "added_1" );
  fd[33] = grtfs_create( "added_2" );

  grtfs_list_directory();
  grtfs_list_blocks();

  return 0;
}

/* this test driver should print

length of buffer1 is 320
length of buffer2 is 43
-- directory listing --
  fd =  1: unused
  fd =  2: unused
  fd =  3: unused
  fd =  4: unused
  fd =  5: unused
  fd =  6: unused
  fd =  7: unused
  fd =  8: unused
  fd =  9: unused
  fd = 10: unused
  fd = 11: unused
  fd = 12: unused
  fd = 13: unused
  fd = 14: unused
  fd = 15: unused
  fd = 16: unused
  fd = 17: unused
  fd = 18: unused
  fd = 19: unused
  fd = 20: unused
  fd = 21: unused
  fd = 22: unused
  fd = 23: unused
  fd = 24: unused
  fd = 25: unused
  fd = 26: unused
  fd = 27: unused
  fd = 28: unused
  fd = 29: unused
  fd = 30: unused
  fd = 31: unused
-- end --
-- directory listing --
  fd =  1: file.txt, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  2: my_file, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  3: unused
  fd =  4: unused
  fd =  5: unused
  fd =  6: unused
  fd =  7: unused
  fd =  8: unused
  fd =  9: unused
  fd = 10: unused
  fd = 11: unused
  fd = 12: unused
  fd = 13: unused
  fd = 14: unused
  fd = 15: unused
  fd = 16: unused
  fd = 17: unused
  fd = 18: unused
  fd = 19: unused
  fd = 20: unused
  fd = 21: unused
  fd = 22: unused
  fd = 23: unused
  fd = 24: unused
  fd = 25: unused
  fd = 26: unused
  fd = 27: unused
  fd = 28: unused
  fd = 29: unused
  fd = 30: unused
  fd = 31: unused
-- end --
320 bytes written to first file
43 bytes written to second file
320 bytes written to first file
-- directory listing --
  fd =  1: file.txt, currently open, 640 bytes in size
           FAT: 4 5 6 8 9
  fd =  2: my_file, currently closed, 43 bytes in size
           FAT: 7
  fd =  3: unused
  fd =  4: unused
  fd =  5: unused
  fd =  6: unused
  fd =  7: unused
  fd =  8: unused
  fd =  9: unused
  fd = 10: unused
  fd = 11: unused
  fd = 12: unused
  fd = 13: unused
  fd = 14: unused
  fd = 15: unused
  fd = 16: unused
  fd = 17: unused
  fd = 18: unused
  fd = 19: unused
  fd = 20: unused
  fd = 21: unused
  fd = 22: unused
  fd = 23: unused
  fd = 24: unused
  fd = 25: unused
  fd = 26: unused
  fd = 27: unused
  fd = 28: unused
  fd = 29: unused
  fd = 30: unused
  fd = 31: unused
-- end --
-- file alllocation table listing of used blocks --
  block   4 is used and points to   5
  block   5 is used and points to   6
  block   6 is used and points to   8
  block   7 is used and points to   1
  block   8 is used and points to   9
  block   9 is used and points to   1
-- end --
40 bytes read from first file
[test for the trivial file system code.  ]
20 bytes read from first file
[ode.  This is a simp]
fd for creating a file with identical name as existing file - 0
fd for creating a sixteenth file - 0
-- directory listing --
  fd =  1: file.txt, currently open, 640 bytes in size
           FAT: 4 5 6 8 9
  fd =  2: my_file, currently closed, 43 bytes in size
           FAT: 7
  fd =  3: file3, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  4: file4, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  5: file5, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  6: file6, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  7: file7, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  8: file8, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  9: file9, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 10: file10, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 11: file11, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 12: file12, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 13: file13, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 14: file14, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 15: file15, currently open, 0 bytes in size
           FAT: no blocks in use
-- end --
-- directory listing --
  fd =  1: unused
  fd =  2: my_file, currently closed, 43 bytes in size
           FAT: 7
  fd =  3: file3, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  4: file4, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  5: file5, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  6: file6, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  7: file7, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  8: file8, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  9: file9, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 10: file10, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 11: file11, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 12: file12, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 13: file13, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 14: file14, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 15: file15, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 16: file16, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 17: file17, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 18: file18, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 19: file19, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 20: file20, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 21: file21, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 22: file22, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 23: file23, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 24: file24, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 25: file25, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 26: file26, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 27: file27, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 28: file28, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 29: file29, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 30: file30, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 31: file31, currently open, 0 bytes in size
           FAT: no blocks in use
-- end --
-- directory listing --
  fd =  1: unused
  fd =  2: my_file, currently closed, 43 bytes in size
           FAT: 7
  fd =  3: file3, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  4: file4, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  5: file5, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  6: file6, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  7: unused
  fd =  8: unused
  fd =  9: file9, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 10: file10, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 11: file11, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 12: file12, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 13: file13, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 14: file14, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 15: file15, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 16: file16, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 17: file17, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 18: file18, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 19: file19, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 20: file20, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 21: file21, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 22: file22, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 23: file23, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 24: file24, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 25: file25, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 26: file26, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 27: file27, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 28: file28, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 29: file29, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 30: file30, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 31: file31, currently open, 0 bytes in size
           FAT: no blocks in use
-- end --
-- directory listing --
  fd =  1: added_1, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  2: my_file, currently closed, 43 bytes in size
           FAT: 7
  fd =  3: file3, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  4: file4, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  5: file5, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  6: file6, currently closed, 0 bytes in size
           FAT: no blocks in use
  fd =  7: added_2, currently open, 0 bytes in size
           FAT: no blocks in use
  fd =  8: unused
  fd =  9: file9, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 10: file10, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 11: file11, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 12: file12, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 13: file13, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 14: file14, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 15: file15, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 16: file16, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 17: file17, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 18: file18, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 19: file19, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 20: file20, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 21: file21, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 22: file22, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 23: file23, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 24: file24, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 25: file25, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 26: file26, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 27: file27, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 28: file28, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 29: file29, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 30: file30, currently open, 0 bytes in size
           FAT: no blocks in use
  fd = 31: file31, currently open, 0 bytes in size
           FAT: no blocks in use
-- end --
-- file alllocation table listing of used blocks --
  block   7 is used and points to   1
-- end --

*/
