/* $begin shellmain */
#include <csapp.h>
#define MAXARGS   128

/* function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);//解析原始命令行的参数
int builtin_command(char **argv); 

int main() 
{
    char cmdline[MAXLINE]; /* Command line */

    while (1) {
		/* Read */
		printf("> ");                   
		Fgets(cmdline, MAXLINE, stdin); 
		if (feof(stdin))
			exit(0);

		/* Evaluate */
		eval(cmdline);
    } 
}
/* $end shellmain */
  
/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* 参数表，条目数量为参数表条目最大值 128 = 2^7 */
    char buf[MAXLINE];   /* 命令缓存，大小字符串最大值 8192 = 2^13 */
    int bg;              /* 是否在后台运行 */
    pid_t pid;           /* 进程ID */
    
    strcpy(buf, cmdline);		// 将传入的命令复制一份作为缓存
    bg = parseline(buf, argv); 	// 解析命令参数
    if (argv[0] == NULL)  		// 如果参数表第一个条目为NULL，说明无命令，返回
	return;   /* Ignore empty lines */

    if (!builtin_command(argv)) {	// 是否为内建命令，是则返回0，进入分支
		if ((pid = Fork()) == 0) {  // 创建子进程
			if (execve(argv[0], argv, environ) < 0) {	// 运行命令
				printf("%s: Command not found.\n", argv[0]);
				exit(0);			// 命令未找到
			}
		}

	/* Parent waits for foreground job to terminate */
		if (!bg) {										// 如果不扔到后台，则等待运行
			int status;
			if (waitpid(pid, &status, 0) < 0)			// 如果返回值为负数，则出错
				unix_error("waitfg: waitpid error");	// 输出错误信息
		}
		else
			printf("%d %s", pid, cmdline);				// 如果后台运行命令，则不等待，并输出命令信息
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "quit")) /* quit command */
		exit(0);  
    if (!strcmp(argv[0], "&"))    /* Ignore singleton & */
		return 1;
    return 0;                     /* Not a builtin command */
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* 过滤命令行前面的空格 */
		buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {	//将delmin指向每个参数后的空格
		argv[argc++] = buf;					//将每个条目指向参数字符串第一个字母
		*delim = '\0';						//将条目结尾的空格改成结束符
		buf = delim + 1;					//指向下一个字符，有可能是空格
		while (*buf && (*buf == ' ')) 		//过滤空格
	       buf++;
    }
    argv[argc] = NULL;		//将参数表的最后一个条目之后的那一个指针指向NULL
    
    if (argc == 0)  		//如果参数表条目为0，返回 1
		return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0)	//如果参数表最后一个条目为&，设置bg为1，并将这个条目过滤掉
		argv[--argc] = NULL;

    return bg;
}
/* $end parseline */


