<<<<<<< HEAD
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define BUF_SIZE 256
void DieWithError(char *errorMessage){
	perror(errorMessage); //�W���G���[�o�͂ɃG���[���b�Z�[�W���o��
	exit(1);//�I���X�e�[�^�X�B1�ȏ��Ԃ��Ƃ����Ӗ�
}
void commun (int sock){
	char buf[BUF_SIZE];
	int len_r;
	char *message = "Tea ceremony is martial arts";//���b�Z�[�W�����}������Ƃ���
	if(send(sock, message, strlen(message), 0) != strlen(message))
		DieWithError("send()sent a message of unexpected bytes");
	if((len_r = recv(sock, buf, BUF_SIZE, 0)) <= 0)
		DieWithError("recv()failed");
	buf[len_r] = '\0';
	printf("%s\n", buf);
}
int main(int argc, char**argv){
	if (argc != 3)
		DieWithError("arguments is not available");
	char *server_ipaddr = argv[1];//"10.13.64.20"
	int server_port = atoi( argv[2] );//10001
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	DieWithError("socket()failed");
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(server_ipaddr);
  target.sin_port = htons(server_port);
	if(connect(sock, (struct sockaddr *)&target, sizeof(target))<0)
		DieWithError("connect()failde");
  commun(sock);
  close(sock);
  return 0;
=======
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define BUF_SIZE 256
void DieWithError(char *errorMessage){
	perror(errorMessage); //�W���G���[�o�͂ɃG���[���b�Z�[�W���o��
	exit(1);//�I���X�e�[�^�X�B1�ȏ��Ԃ��Ƃ����Ӗ�
}
void commun (int sock){
	char buf[BUF_SIZE];
	int len_r;
	char *message = "Tea ceremony is martial arts";//���b�Z�[�W�����}������Ƃ���
	if(send(sock, message, strlen(message), 0) != strlen(message))
		DieWithError("send()sent a message of unexpected bytes");
	if((len_r = recv(sock, buf, BUF_SIZE, 0)) <= 0)
		DieWithError("recv()failed");
	buf[len_r] = '\0';
	printf("%s\n", buf);
}
int main(int argc, char**argv){
	if (argc != 3)
		DieWithError("arguments is not available");
	char *server_ipaddr = argv[1];//"10.13.64.20"
	int server_port = atoi( argv[2] );//10001
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	DieWithError("socket()failed");
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(server_ipaddr);
  target.sin_port = htons(server_port);
	if(connect(sock, (struct sockaddr *)&target, sizeof(target))<0)
		DieWithError("connect()failde");
  commun(sock);
  close(sock);
  return 0;
>>>>>>> 4591f35be94d3c0c4085d6e3820c8e1d57d51a6f
}