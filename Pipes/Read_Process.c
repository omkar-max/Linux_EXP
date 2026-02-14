 #include<stdio.h>
 #include <fcntl.h>
 #include<unistd.h>
 #include<assert.h>
 #define BUFFER_SIZE 100


 int main(int argc, char* argv[])
 {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open("../pipe",O_RDONLY);
    assert(fd >= 0);
    printf("Process is waiting for the data...\n");
    
    int n = read(fd, buffer,10);

    printf("The number of bytes write was %d\n",n);

    
      // if(ret < 0){
      //    printf("Error occured while reading from the pipe\n");
      //    exit(1);
      // }
      
   printf("%s\n", buffer);

      

    

    
    return 0;
 }