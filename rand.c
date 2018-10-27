#include "rand.h"
int gen_rand(){
      int fd = open("/dev/random", O_RDONLY);
      if (fd < 0) {
        printf("open error: %s\n", strerror(errno));
        return -1;
      }
      
      int holder;
      unsigned int r = read(fd, &holder, sizeof(holder));
      if (r < sizeof(holder)) {
        printf("read error: %s\n", strerror(errno));
        return -1;
      }

      return holder;
  }

