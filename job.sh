#!/bin/bash
#SBATCH	--comment "ProgParallele"
#SBATCH	-J "CasseMD5"

#SBATCH --error=job.%J.err
#SBATCH	--output=job.%J.out

#SBATCH	-p short
#SBATCH	--time=05:00:00

#SBATCH --mem 51200
#SBATCH -c 28
#SBATCH -N 1

#SBATCH --mail-user=<florent.denef@etudiant.univ-reims.fr>
#SBATCH	--mail-type=ALL,TIME_LIMIT_50,TIME_LIMIT_80

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
./prog Chps7 2