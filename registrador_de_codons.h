#include "definicoes.h"

/**
 * Pega a sequência dos genes
 * e associa a sua respectiva
 * proteína.
 */
int registre_os_codons(
    /**
     * Onde a sequência de amino ácidos será
     * armazenada.
     */
    char registro_de_amin_acidos[][MAX_CODON],
    /**
     * Recebe a sequência de amino ácidos
     */
    char seq_amin_acid[],
    /**
     * Aqui recebe o número de amino ácidos lidos.
     */
    int qtd_amin_acidos,
    /**
     * Recebe o número de num_tentativas já ocorridas
     * de decifrar o código genético da proteína.
     */
    int num_tentativas
) {
    /**
     * Representa a posição do código genético
     * que estamos a ler.
     */
    int
        byte = num_tentativas,
        con_while = 0;

    for (int i = 0; i < qtd_amin_acidos; i++)
    {
        while (con_while != 3)
        {            
            registro_de_amin_acidos[i][con_while] = seq_amin_acid[byte];

            byte++;
            con_while++;
        }

        con_while = 0;
    }

    return 0;
}