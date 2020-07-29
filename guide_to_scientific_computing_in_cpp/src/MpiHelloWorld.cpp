/*
 * MpiHelloWorld.cpp
 * 
 * Example MPI program that spawns one instance per process and displays a message.
 *
 * Compile with:
 * mpiCC MpiHelloWorld.cpp -o MpiHelloWorld
 *
 * Run with:
 * mpirun -np <number of processes> ./MpiHelloWorld 
 */

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[]) {
  // Initialize MPI code.  All MPI calls must be between ::Init and ::Finalize
  MPI::Init(argc, argv);

  // Get the number of processes that will be run 
  int num_procs = MPI::COMM_WORLD.Get_size();

  // Get the process that will be running
  int rank = MPI::COMM_WORLD.Get_rank();
  std::cout << "Hello world from process " << rank
            << " of " << num_procs << "\n";
  MPI::Finalize();
  return 0;
}
