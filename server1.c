/*

* server.c - реализация сервера

*

* чтобы запустить пример необходимо:

* 1. запустить программу server на одной консоли;

* 2. запустить программу client на другой консоли.

*/

#include "common.h"

int main()
{

my_message_t message;
my_message_t message1;
my_message_t name;
my_message_t name1;

key_t key;


int msqid; 
int length; 
int msqid1; 
int length1;
int n;
int n1;
int m;
int m1;

printf("Message Queue Server...\n");

if((key = ftok("server", '1253')) < 0) {

fprintf(stderr, "%s: Невозможно получить ключ (%s)\n", stderr ); exit(-1); 
}
if((msqid = msgget(key, PERM | IPC_CREAT)) < 0) {

fprintf(stderr, "%s: Невозможно создать очередь (%s)\n") ; exit(-1);

}

if((msqid1 = msgget(key, PERM | IPC_CREAT)) < 0)

{

fprintf(stderr, "%s: Невозможно создать очередь (%s)\n") ; exit(-1);

}


/* прочитать сообщение */

message.mtype = 1L;
message1.mtype = 1L;
name.mtype = 1L;
name1.mtype = 1L;

n = msgrcv(msqid, &message, sizeof(message), message.mtype, 0);
m = msgrcv(msqid, &name, sizeof(name), name.mtype, 0);
n1 = msgrcv(msqid1, &message1, sizeof(message1), message1.mtype, 0);
m1 = msgrcv(msqid, &name1, sizeof(name1), name1.mtype, 0);

/* если сообщение поступило, напечатать содержимое */

if(n <= 0)
{

fprintf(stderr, "%s: Ошибка чтения сообщения (%s)\n"); exit(-1);

}
else
{

if(write(1, message.buff, n) != n)
{
fprintf(stderr, "%s: Ошибка вывода (%s)\n"); exit(-2);
}
}
write(1, name.buff, m);


if(n1 <= 0)
{

fprintf(stderr, "%s: Ошибка чтения сообщения (%s)\n"); exit(-1);

}
else
{

if(write(1, message1.buff, n1) != n1)
{
fprintf(stderr, "%s: Ошибка вывода (%s)\n"); exit(-2);
}
}

write(1, name1.buff, m1);
/* удалить очередь сообщений */
if(msgctl(msqid, IPC_RMID, 0) < 0)
{
fprintf(stderr, "%s: Ошибка удаления очереди (%s)\n"); exit(-3);
}

exit(0);
}
