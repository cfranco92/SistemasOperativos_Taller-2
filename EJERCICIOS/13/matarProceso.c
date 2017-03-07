// matar proceso únicamente dando el número del proceso

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int kill(pid_t pid, int sig);

int main main(int argc, char *argv[]) {


  while ((option = getopt(argc, argv, "p:gc")) != -1) {

  	kill(option, SIG_KILL);
  }

  return 0;
}

// #include <sys/types.h>
// #include <signal.h>
//
// int kill(pid_t pid, int sig);
