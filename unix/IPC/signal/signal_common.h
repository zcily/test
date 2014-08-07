#ifndef __SIGNAL_COMMON_H__
#define __SIGNAL_COMMON_H__

#ifndef CLI_FIFO_INFO
#define CLI_FIFO_INFO "cli_%d_fifo"
#endif

#ifndef SER_FIFO_INFO
#define SER_FIFO_INFO "ser_fifo"
#endif

#ifndef CONTENT_BUFFER
#define CONTENT_BUFFER 2048
#endif 

struct message
{
	pid_t client_pid;
	char data[1024];
};



#endif
