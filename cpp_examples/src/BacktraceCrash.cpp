/*
 * BacktraceCrash.cpp
 *
 * Example of using the backtrace() function to provide a stack trace in the
 * event of a segmentation fault.
 */
#include <csignal>    // signal()
#include <cstdlib>    // exit()
#include <cstdio>     // fprintf()
#include <execinfo.h> // backtrace()

void handler(const int sig) {
  void *array[10];
  size_t size = backtrace(array, 10);

  fprintf(stderr, "Error: signal %d\n", sig);
  backtrace_symbols_fd(array, size, 2);
  exit(1);
}

void debughandler( int signum, siginfo_t *info, void *context ) {
  struct sigaction action;
  action.sa_handler = SIG_DFL;
  action.sa_sigaction = nullptr;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  action.sa_restorer = nullptr;

  fprintf( stderr, "Fault address: %p\n", info->si_addr );
  switch( info->si_code ) {
    case SEGV_MAPERR:
      fprintf( stderr, "Address not mapped.\n");
      break;
    case SEGV_ACCERR:
      fprintf( stderr, "Access to this address is not allowed.\n" );
      break;
    default:
      fprintf( stderr, "Unknown reason.\n" );
      break;
  }
  sigaction( SIGSEGV, &action, NULL );
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./%s <0 for signal handler, 1 for sigaction>\n",
      argv[0]);
    return -1;
  }

  // User specified 0 for signal handler
  if (atoi(argv[1]) == 0) {
    signal(SIGSEGV, handler);
  } else {
    struct sigaction action;
    action.sa_handler = nullptr;
    action.sa_sigaction = debughandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    action.sa_restorer = nullptr;

    sigaction(SIGSEGV, &action, nullptr);
  }

  // Force a segfault by assigning a value to a null pointer
  int *x = nullptr;
  *x = 0;

  return 0;
}
