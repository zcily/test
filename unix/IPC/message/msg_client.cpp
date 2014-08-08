#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

using namespace std;

#define KEY_VALUE 'a'
#define MSG_BUFFER 2048

struct myMsgBuffer
{
    size_t msg_type;
    char msg_buffer[MSG_BUFFER];
};

int main(int argc, char**argv)
{
    key_t m_key;
    int msg_id = 0;
    myMsgBuffer msg_buf;
    
    if(-1 == (m_key = ftok(".", KEY_VALUE))){
        perror("create the file key error : "); 
        return EXIT_FAILURE;
    }

    if(-1 == (msg_id = msgget(m_key, IPC_CREAT | 0777))){
        perror("message get"); 
        return EXIT_FAILURE;
    }

    if(1){
        msg_buf.msg_type= 10;
        cin.getline(msg_buf.msg_buffer, sizeof(msg_buf.msg_buffer));
        // 发送过去的字符串不能已NULL结尾， 所以用strlen来计算发送的字符的长度。不然会出现接收端挂掉问题。
        if(-1 == (msgsnd(msg_id, &msg_buf, strlen(msg_buf.msg_buffer), MSG_NOERROR))) {
            perror("send message error : "); 
            return EXIT_FAILURE;
        }
        memset(&msg_buf, 0, sizeof(myMsgBuffer));
    }
    return EXIT_SUCCESS;
}

