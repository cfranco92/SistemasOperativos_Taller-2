/* DirectorioActual.c */
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

  int retVal;
  pid_t pid;

  pid = fork();

  if (pid == (pid_t)(-1)) {
    fprintf(stderr, "%s, Fallo al hacer el fork\n",
	    strerror(errno));
    exit(13);
  }
  else if (pid == 0) {
                // LA LINEA DE ESTE PUNTO
    char *execArgs[] = {"ls", NULL};
    execvp("ls", execArgs);// execl("/bin/ls", "ls", "-l", (char *) 0);
    // No se debe ejecutar este c�digo
    fprintf(stderr, "No pudo ejecutar /bin/ls %s\n", strerror(errno));
  }
  else {
    wait(&retVal);
    // Verifica si el hijo termin� bien
    if (WIFEXITED(retVal)) {
      fprintf(stdout, "El proceso termino bien: %d\n",
	      WEXITSTATUS(retVal));
    }
    else if (WIFSIGNALED(retVal)) { // Fue se�alizado
      fprintf(stderr, "La senal capturada: %d\n",
	      WTERMSIG(retVal));
    }
    else if (WIFSTOPPED(retVal)) {
      fprintf(stderr, "El proceso se encuentra parado: %d\n",
	      WSTOPSIG(retVal));
    }
    else if (WEXITSTATUS(retVal)){
      fprintf(stderr, "El proceso no encontró el proceso a ejecutar: %d\n",
        WEXITSTATUS(retVal)); //Número diferente de 0
    }
  }
}
