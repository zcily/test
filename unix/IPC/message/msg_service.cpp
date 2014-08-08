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
    long msg_type;
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

    memset(&msg_buf, 0, sizeof(myMsgBuffer));

    while(1){
        cout << "before recv message " << endl;
        //type为10 意味着client端设置的msgbuf中的type也必须也10才能接收到信息。
        if( -1 == msgrcv(msg_id, &msg_buf, sizeof(myMsgBuffer), 10, MSG_NOERROR)){
            perror("message recvice error : "); 
            return EXIT_FAILURE;
        }
        cout << "recv message :  " << msg_buf.msg_buffer << endl;
    }
    return EXIT_SUCCESS;
}

