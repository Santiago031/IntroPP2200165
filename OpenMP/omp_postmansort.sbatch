#!/bin/bash

#SBATCH -p normal
#SBATCH --ntasks=10
#SBATCH --output=output_postmansort.txt
#SBATCH --error=error_%j.txt
#SBATCH --mail-user=speedy.gonzalez12321@gmail.com
#SBATCH --cpus-per-task=10
#SBATCH -w ExaDELL

gcc -fopenmp omp_postmansort.c -o omp_postmansort
./omp_postmansort
