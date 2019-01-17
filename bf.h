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

extern int rank, sizeMPI;

struct bf {
	char tabSymbole[MAXSYMBOLE];
	int nbSymbole;
};

/**
 *
 */
void initTabSymb(struct bf*);

/**
 *
 * @param e
 * @param c
 * @param l
 * @param word
 */
void decode(struct bf* e, int c, int l, char word[]);

/**
 *
 * @param p longueur du préfixe
 * @param l longueur du mot
 * @param motGagnant
 * @param monMD5
 * @return
 */
bool bruteForce(int p, int l, char motGagnant[], unsigned char* monMD5);

/**
 *
 * @param e
 * @param p
 * @param l
 * @param word
 * @param monMD5
 * @return
 */
bool bruteForcePrefixe(struct bf* e, int p, int l, char word[], unsigned char monMD5[]);

#endif
