#define UZH_RL_BUFSIZE 1024
int main(int argc, char **argv)

{
// the main loop of the Uzh shell.

void Uzh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = Uzh_read_line();
    args = Uzh_split_line(line);
    status = Uzh_execute(args);

    free(line);
    free(args);
  } while (status);
} 

// the Uzh_read_line for reading the input in the shell which will be dynamic in nature

char *Uzh_read_line(void)
{
  int bufsize = UZH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  // for failing to allocate any memory for input by user.

    if (!buffer) {
    fprintf(stderr, "Uzh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Reads a character using getchar stdin

    c = getchar();

    // If we hit EOF, replace it with a null character and return.

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, 
    // reallocate more to the bufsize according to the 
    // position increase of the stdin getting from the user.

    if (position >= bufsize) {
      bufsize += UZH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "Uzh: allocation error\n");
        exit(EXIT_FAILURE);
        // yeah yeah i could have used the getline of stdin and got all this in few lines 
        // but this looks more exaplaning.
      }
    }
  }
}
  
  

















 




































return EXIT_SUCCESS;
}









