/*****************************************************************************/
/* Michael Krajecki,                                                         */
/* Universite de Reims                                                       */
/*                                                                           */
/* Les fonctions utiles a l'enumeration complete                             */
/*****************************************************************************/


#ifndef BF_H
#define BF_H

#include <stdbool.h>
#include <math.h>

#define MAXSYMBOLE 100
#define LONGMAXMOT 10

struct bf {
	char tabSymbole[MAXSYMBOLE];
	uint32_t nbSymbole;
};

void initTabSymb(struct bf*);

void decode(struct bf* e, int c, int l, char word[]);

bool bruteForce(uint32_t p, uint32_t l, char* motGagnant, unsigned char* monMD5);

bool bruteForcePrefixe(struct bf* e, int p, int l, char word[], unsigned char monMD5[]);

#endif
