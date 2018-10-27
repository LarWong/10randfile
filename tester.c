#include "rand.h"

int main() {
      printf("Generating random numbers:\n");
      int output[10];
      for (int i = 0; i < 10; i++) {
        output[i] = gen_rand();
        printf("\trandom %d: %d\n", i, output[i]);
      }

      printf("Writing numbers to file...\n\n");
      int fd = open("stuff.txt", O_WRONLY | O_CREAT, 0777);
      if (fd < 0) {
        printf("\topen error: %s\n", strerror(errno));
        return 0;
      }

      printf("\tDONE!\n\n");

      int w = write(fd, output, sizeof(int) * 10);
      if (w < 0) {
        printf("\twrite error: %s\n", strerror(errno));
        return 0;
      }

      printf("Reading numbers from file...\n\n");
      fd = open("stuff.txt", O_RDONLY);

      if (fd < 0) {
        printf("\topen error: %s\n", strerror(errno));
        return 0;
      }
      
      printf("\tDONE!\n\n");

      int input[10];
      int r = read(fd, input, sizeof(int) * 10);
      if (r < 0) {
        printf("read error: %s\n", strerror(errno));
        return 0;
      }

      printf("Verification that written values are the same:\n");
      for (int i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, input[i]);
      }
}
