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
     * Recebe o número de tentativas já ocorridas
     * de decifrar o código genético da proteína.
     */
    int tentativas
) {
    for (int i = tentativas; i < (num_amin_acid_lidos + tentativas); i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            amin_acids_achados[j][i] = seq_amin_acid[i];            
        }
    }
    
    return 0;
}