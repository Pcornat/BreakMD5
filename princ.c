#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>
#include <openssl/md5.h>
#include <mpi.h>

#include "bf.h"

int rank, sizeMPI;

int main(int argc, char** argv) {
	unsigned char monMD5[MD5_DIGEST_LENGTH];
	int i = 0;
	//int j = 0;
	//int _a = 1;
	char word[64];
	char hex[129]; // note : 128 ne passe pas... ptet a cause du caractere de fin dans l'argv.. i don't know

	int taillePrefixe;
	// pour le temps
	struct timeb tav, tap;
	double te;

	if (argc != 3) {
		fprintf(stderr, "usage: %s string-to-hash taille-du-prefixe\n", argv[0]);
		exit(1);
	}
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &sizeMPI);

	memset(monMD5, 0, sizeof(monMD5));
	memset(word, 0, sizeof(word));

	sprintf(word, "%s", argv[1]);
	taillePrefixe = atoi(argv[2]);

	// on hash le code
	MD5((unsigned char*) word, strlen(word), monMD5);

	if (rank == 0)
		ftime(&tav);

	if (bruteForce(taillePrefixe, (int) strlen(word), word, monMD5)) {
		if (rank == 0) {
			printf("Gagne : %s\n", word);
			for (i = 0; i < 16; i++) {
				printf("%02x", (unsigned int) monMD5[i]);
			}
			printf("\n");
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	if (rank == 0) {
		ftime(&tap);
		te = (double) ((tap.time * 1000 + tap.millitm) - (tav.time * 1000 + tav.millitm)) / 1000;
		printf("Temps d'exécution : %f\n", te);
	}

	MPI_Finalize();
	return EXIT_SUCCESS;
}
