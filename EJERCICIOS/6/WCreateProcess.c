/* CreateProcess.c */
/* $Id: WCreateProcess.c,v 1.1 2013/03/19 03:07:42 fcardona Exp $ */

#include <Windows.h>

int
main(int argc, char *argv[])
{
  STARTUPINFO startupInfo;
  PROCESS_INFORMATION piProcInfo;

  GetStartupInfo(&startupInfo);

  if (CreateProcess(NULL, "NOTEPAD CreateProcess.c", NULL, NULL,
		    FALSE, 0, NULL, NULL, &startupInfo,
		    &piProcInfo)) {
    WaitForSingleObject(piProcInfo.hProcess, 0);
  }
  else {
  }
}
