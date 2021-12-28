/*

* client.c - реализация сервера

*

* чтобы запустить пример необходимо:

* 1. запустить программу server на одной консоли;

* 2. запустить программу client на другой консоли.

*/

#include "common.h"

#define MESSAGE "Hello teacher!!!\n"
#define NAME "client1\n"

int main()

{

my_message_t message1;
my_message_t name1;

long mtype;
key_t key; 
int msqid1; 
int length1;
int length_name1; 
int n1;

/* баннер */

printf("Message Queue Client...\n");

/* получить ключ */

if((key = ftok("server", '1253')) < 0)

{

fprintf(stderr, "%s: Невозможно получить ключ (%s)\n" ); exit(-1);

}

/* получить доступ к очереди сообщений, очередь уже должна

* быть создана сервером

*/

if((msqid1 = msgget(key, 0)) < 0)

{

fprintf(stderr, "%s: Невозможно получить доступ к очереди (%s)\n" ); exit(-2);

}
/* подготовка сообщения */

message1.mtype = 1L;

if((length1 = sprintf(message1.buff, MESSAGE)) < 0)

{

fprintf(stderr, "%s: Ошибка копирования в буфер (%s)\n" ); exit(-3);

}
/* передача сообщения */

if(msgsnd(msqid1, (void*)&message1, length1, 0) < 0)

{

fprintf(stderr, "%s: Ошибка записи сообщения в очередь (%s)\n" ); exit(-4);

}



name1.mtype = 1L;

if((length_name1 = sprintf(name1.buff, NAME)) < 0)

{

fprintf(stderr, "%s: Ошибка копирования в буфер (%s)\n" ); exit(-3);

}
/* передача сообщения */

if(msgsnd(msqid1, (void*)&name1, length_name1, 0) < 0)

{

fprintf(stderr, "%s: Ошибка записи сообщения в очередь (%s)\n" ); exit(-4);

}

exit(0);

}
