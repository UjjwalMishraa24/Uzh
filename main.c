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


return EXIT_SUCCESS;
}









