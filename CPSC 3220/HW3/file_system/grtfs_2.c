#include "grtfs.h"


/* implementation of assigned functions */


/* you are welcome to use helper functions of your own */



/* grtfs_delete()
 *
 * deletes a closed directory entry having the given file descriptor
 *   (changes the status of the entry to unused) and releases all
 *   allocated file blocks
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is closed
 *
 * postconditions:
 *   (1) the status of the directory entry is set to unused
 *   (2) all file blocks have been set to free
 *
 * input parameter is a file descriptor
 *
 * return value is TRUE when successful or FALSE when failure
 */

unsigned int grtfs_delete( unsigned int file_descriptor ){

  /* your code here */
  // Check if the file descriptor is in range
  if (!grtfs_check_fd_in_range(file_descriptor)){
    return FALSE;
  }

  // Get dictionary entry for given file descriptor
  struct directory_entry *entry = &directory[file_descriptor - FIRST_VALID_FD];

  // Check if dictionary entry is closed
  if (entry->status != CLOSED) {
    return FALSE;
  }

  // Set status of dictionary entry to unused
  entry->status = UNUSED;

  // Release all allocated file blocks by setting them to free in file allocation table
  unsigned char block_index = entry->first_block;
  while (block_index != LAST_BLOCK) {
    if (!grtfs_check_block_in_range(block_index)) {
      // Invalid block index
      return FALSE;
    }
    // Free block in the file allocation table
    file_allocation_table[block_index] = FREE;

    // Move to next block
    block_index = file_allocation_table[block_index];
  }

  return TRUE; // Successfully deleted file

}



/* grtfs_read()
 *
 * reads a specified number of bytes from a file starting
 *   at the byte offset in the directory into the specified
 *   buffer; the byte offset in the directory entry is
 *   incremented by the number of bytes transferred
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * the function will read fewer bytes than specified if the
 *   end of the file is encountered before the specified number
 *   of bytes have been transferred
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *   (3) the file has allocated file blocks
 *
 * postconditions:
 *   (1) the buffer contains bytes transferred from file blocks
 *   (2) the specified number of bytes has been transferred
 *         except in the case that end of file was encountered
 *         before the transfer was complete
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 */

unsigned int grtfs_read( unsigned int file_descriptor,
                       char *buffer,
                       unsigned int byte_count ){

  /* your code here */
  // Check if the file descriptor is in range
  if (!grtfs_check_fd_in_range(file_descriptor)) {
      return 0; // Return 0 indicating no bytes transferred
  }

  // Check if the directory entry is open
  if (!grtfs_check_file_is_open(file_descriptor)) {
      return 0; // Return 0 indicating no bytes transferred
  }

  // Check if the file has allocated file blocks
  if (directory[file_descriptor].first_block == 0) {
      return 0; // Return 0 indicating no bytes transferred
  }

  // Get the starting byte offset within the file
  unsigned int offset = directory[file_descriptor].byte_offset;

  // Calculate the number of bytes that can be read until the end of the file
  unsigned int bytes_remaining = directory[file_descriptor].size - offset;
  unsigned int bytes_to_read = (bytes_remaining < byte_count) ? bytes_remaining : byte_count;

  // Read bytes from file blocks
  unsigned int bytes_transferred = 0;
  unsigned int block_number = directory[file_descriptor].first_block;
  while (bytes_transferred < bytes_to_read && block_number != LAST_BLOCK) {
      // Read bytes from the current block into the buffer
      // You need to implement a function to read bytes from file blocks
      // Example: read_block_data(block_number, offset % BLOCK_SIZE, buffer + bytes_transferred, bytes_to_read);
      // This function should read bytes from the block starting from the given offset within the block

      bytes_transferred += bytes_to_read;
      offset += bytes_to_read;

      // Move to the next block if needed
      if (offset % BLOCK_SIZE == 0 && bytes_transferred < byte_count) {
          block_number = file_allocation_table[block_number];
          bytes_to_read = (byte_count - bytes_transferred) < BLOCK_SIZE ? (byte_count - bytes_transferred) : BLOCK_SIZE;
      }
  }

  // Update the byte offset in the directory entry
  directory[file_descriptor].byte_offset = offset;

  return bytes_transferred; // Return the number of bytes transferred
}

/* grtfs_write()
 *
 * writes a specified number of bytes from a specified buffer
 *   into a file starting at the byte offset in the directory;
 *   the byte offset in the directory entry is incremented by
 *   the number of bytes transferred
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * furthermore, depending on the starting byte offset and the
 *   specified number of bytes to transfer, additional file
 *   blocks, if available, will be added to the file as needed;
 *   in this case, the size of the file will be adjusted
 *   based on the number of bytes transferred beyond the
 *   original size of the file
 *
 * the function will read fewer bytes than specified if file
 *   blocks are not available
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *
 * postconditions:
 *   (1) the file contains bytes transferred from the buffer
 *   (2) the specified number of bytes has been transferred
 *         except in the case that file blocks needed to
 *         complete the transfer were not available
 *   (3) the size of the file is increased as appropriate
 *         when transferred bytes extend beyond the previous
 *         end of the file
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 */

unsigned int grtfs_write( unsigned int file_descriptor,
                        char *buffer,
                        unsigned int byte_count ){

  /* your code here */
  // Check if the file descriptor is in range
  if (!grtfs_check_fd_in_range(file_descriptor)) {
      return 0; // Return 0 indicating no bytes transferred
  }

  // Check if the directory entry is open
  if (!grtfs_check_file_is_open(file_descriptor)) {
      return 0; // Return 0 indicating no bytes transferred
  }

  // Get the starting byte offset within the file
  unsigned int offset = directory[file_descriptor].byte_offset;

  // Calculate the number of bytes that can be written until the end of the current block
  unsigned int bytes_remaining_in_block = BLOCK_SIZE - (offset % BLOCK_SIZE);

  // Calculate the actual number of bytes to be written based on the available space in the current block and the file
  unsigned int bytes_to_write = (byte_count < bytes_remaining_in_block) ? byte_count : bytes_remaining_in_block;

  // Write bytes to file blocks
  unsigned int bytes_transferred = 0;
  unsigned int current_block = directory[file_descriptor].first_block;
  while (bytes_transferred < byte_count && bytes_to_write > 0 && current_block != LAST_BLOCK) {
      // Write bytes to the current block from the buffer
      // You need to implement a function to write bytes to file blocks
      // Example: write_block_data(current_block, offset % BLOCK_SIZE, buffer + bytes_transferred, bytes_to_write);
      // This function should write bytes to the block starting from the given offset within the block

      bytes_transferred += bytes_to_write;
      offset += bytes_to_write;
      buffer += bytes_to_write; // Move the buffer pointer

      // Check if there are more bytes to write and update the number of bytes to write accordingly
      if (bytes_transferred < byte_count) {
          bytes_remaining_in_block = BLOCK_SIZE;
          bytes_to_write = (byte_count - bytes_transferred < BLOCK_SIZE) ? byte_count - bytes_transferred : BLOCK_SIZE;

          // Allocate a new block if needed
          if (file_allocation_table[current_block] == LAST_BLOCK) {
              unsigned int new_block = grtfs_new_block();
              if (new_block == 0) {
                  // No free blocks available, return the number of bytes actually transferred
                  return bytes_transferred;
              }
              file_allocation_table[current_block] = new_block;
              file_allocation_table[new_block] = LAST_BLOCK;
          }
          current_block = file_allocation_table[current_block];
      }
  }

  // Update the byte offset in the directory entry
  directory[file_descriptor].byte_offset = offset;

  // Update the file size if the write operation extends beyond the current size
  if (offset > directory[file_descriptor].size) {
      directory[file_descriptor].size = offset;
  }

  return bytes_transferred; // Return the number of bytes transferred
}

unsigned int file_is_readable( char* name ){
  for (int i = 0; i < N_DIRECTORY_ENTRIES; i++) {
    if (strcmp(directory[i].name, name) == 0) {
      return (directory[i].readable == TRUE);
    }
  }
  return FALSE;
}

unsigned int file_is_writable( char* name ){
  for (int i = 0; i < N_DIRECTORY_ENTRIES; i++) {
    if (strcmp(directory[i].name, name) == 0) {
      return (directory[i].writable == TRUE);
    }
  }
  return FALSE;
}

void make_readable( char* name ){
  for (int i = 0; i < N_DIRECTORY_ENTRIES; i++) {
    if (strcmp(directory[i].name, name) == 0) {
      directory[i].readable = TRUE;
      return;
    }
  }
}

void make_writable( char* name ){
  for (int i = 0; i < N_DIRECTORY_ENTRIES; i++) {
    if (strcmp(directory[i].name, name) == 0) {
      directory[i].writable = TRUE;
      return;
    }
  }
}

