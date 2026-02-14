 #include<stdio.h>
 #include <fcntl.h>
 #include<unistd.h>
 #include<assert.h>
 #include<string.h>
 #include<stdlib.h>
 #define BUFFER_SIZE 10


 int main(int argc, char* argv[])
 {
    int fd;
    char buffer[BUFFER_SIZE];

    if(argc >= 2){
        strncpy(buffer, argv[1], sizeof(buffer)-1);
        buffer[sizeof(buffer) -1] = '\0';

    }
    else{
        printf("you have to pass the argument or data to the buffer\n");
        exit(1);
    }
    
    

    fd = open("../pipe",O_RDWR);
    printf("%d\n", fd);
    assert(fd >= 0);

    if(write(fd, buffer, sizeof(buffer)) < 0)
    {
        printf("Write failed\n");
    }

    

    
    return 0;
 }