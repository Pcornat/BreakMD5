/*****************************************************************************/
/* Michael Krajecki,                                                         */
/* Universite de Reims                                                       */
/*                                                                           */
/* Les fonctions utiles a l'enumeration complete                             */
/*****************************************************************************/


#ifndef BF_H
#define BF_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAXSYMBOLE 100
#define LONGMAXMOT 10

typedef struct _bf {
	char tabSymbole[MAXSYMBOLE];
	uint32_t nbSymbole;
} bf;

/**
 *
 * @param e
 */
void initTabSymb(bf* e);

/**
 *
 * @param e
 * @param c
 * @param l
 * @param word
 */
void decode(bf* e, int c, int l, char* word);

/**
 *
 * @param p
 * @param l
 * @param motGagnant
 * @param monMD5
 * @return
 */
bool bruteForce(uint32_t p, size_t l, char* motGagnant, unsigned char* monMD5);

/**
 *
 * @param e
 * @param p
 * @param l
 * @param word
 * @param monMD5
 * @return
 */
bool bruteForcePrefixe(bf* e, uint32_t p, size_t l, char* word, unsigned char* monMD5);

#endif
