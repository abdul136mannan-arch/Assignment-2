#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct Employee
{
    int id;
    char name[20];
};

int main()
{
    int fd=open("employees.dat",O_RDWR|O_CREAT,0644);

    struct Employee e1={1,"Alice"};
    struct Employee e2={2,"Bob"};

    write(fd,&e1,sizeof(e1));
    write(fd,&e2,sizeof(e2));

    struct Employee update={2,"Robert"};

    lseek(fd,sizeof(struct Employee),SEEK_SET);

    write(fd,&update,sizeof(update));

    lseek(fd,0,SEEK_SET);

    struct Employee temp;

    while(read(fd,&temp,sizeof(temp))>0)
    {
        printf("%d %s\n",temp.id,temp.name);
    }

    close(fd);

    return 0;
}
