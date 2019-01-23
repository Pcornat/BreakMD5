#!/bin/bash
#SBATCH	--comment "ProgParallele"
#SBATCH	-J "BreakMD5"

#SBATCH --error=job.%J.err
#SBATCH	--output=job.%J.out

#SBATCH	-p short
#SBATCH	--time=00:30:00

#SBATCH --mem 50G
#SBATCH -n 28
##SBATCH -c 28
#SBATCH -N 1

#SBATCH --mail-user=<florent.denef@etudiant.univ-reims.fr>
#SBATCH	--mail-type=ALL,TIME_LIMIT_50,TIME_LIMIT_80

srun ./prog totot 2
