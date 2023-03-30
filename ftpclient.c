#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include <netinet/in.h>
 #include <arpa/inet.h>
int main()
{   int client;
   struct sockaddr_in serveraddr;
  char buffer[1050];
  char s[1050];
   int port=1052;
    client=socket(AF_INET,SOCK_STREAM,0);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=inet_addr("172.20.3.5");
    serveraddr.sin_port = htons( port );
   if( connect(client,(struct sockaddr*)&serveraddr,sizeof(serveraddr))>-1)
    printf("connected");
  else
  printf("Not connected");
  printf("Enter:-");
  scanf("%s",buffer);
  send(client,buffer,strlen(buffer),0);
while(1)
{  int n=read(client,buffer,1050);
  if(n==0)
  break;
   buffer[n]='\0';
   printf("%s",buffer);
}

close(client);
}

