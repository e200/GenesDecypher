/**
 * O número de combinações de amino ácidos.
 *
 * Existem 4 tipos de amino ácidos, isso
 * significa que só existem 64 possíveis
 * combinações entre os mesmos. (4 x 4 x 4 = 64).
 
 * Para entender melhor veja a tabéla do código
 * genético na pasta `ficheiros_auxiliares`.
 *
 * Caso também fiquem confusos sobre a diferença
 * entre codóns e amino ácidos, leiam:
 *
 * https://br.answers.yahoo.com/question/index?qid=20100315152331AAfeSuj
 */
#define NUM_AMIN_ACID 64

/**
 * Limite máximo de amino ácidos
 * na nossa proteína.
 */
#define MAX_AMIN_ACID_NA_PROT 1000

/**
 * Limite de codóns.
 */
#define MAX_CODON 2

/**
 * Limite de sequências genéticas.
 */
#define MAX_SEQ_GEN 10000