#include "definicoes.h"

/**
 * Pega a sequência dos genes
 * e associa a sua respectiva
 * proteína.
 */
int resolva_seq_gen(
    /**
     * Onde a sequência de amino ácidos será
     * armazenada.
     */
    char amin_acids_achados[][LIM_SEQ_COD_GEN],
    /**
     * Recebe a sequência de amino ácidos
     */
    char seq_amin_acid[],
    /**
     * Aqui recebe o número de amino ácidos lidos.
     */
    int num_amin_acid_lidos,
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
        pos_cod_gen = num_tentativas,
        con_while = 0;
    

    for (int i = 0; i < num_amin_acid_lidos; i++)
    {   
        while (con_while != 3)
        {
            amin_acids_achados[i][con_while] = seq_amin_acid[pos_cod_gen];
            
            pos_cod_gen++;
            con_while++;
        }

        con_while = 0;
    }

    return 0;
}