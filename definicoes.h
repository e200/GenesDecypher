/**
 * Representa é o número de combinações
 * de amino ácidos.
 *
 * Existem 4 tipos de amino ácidos, isso
 * significa que só existem 64 possíveis combinações
 * entre os mesmos. (4 x 4 x 4 = 64).
 *
 * Para entender melhor veja a tabéla das combinações.
 */
#define NUM_AMIN_ACID 64

/**
 * Este é o limite de proteínas que o nosso
 * programa irá suportar.
 */
#define LIM_AMIN_ACID 1000

/**
 * Este é o limite de códigos genéticos
 * que o nosso programa irá suportar.
 * 
 * Se nos for passado mais do que isso, o
 * resto não será lido.
 */
#define LIM_SEQ_COD_GEN 10000