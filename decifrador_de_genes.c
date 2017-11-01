/**
 * Este programa decifra o código
 * genético de amino ácidos.
 * 
 * Data: 31/10/2017
 *
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200/GenesDecypher/blob/master/
 */

#include <stdio.h>
#include <stdlib.h>

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
#define NUMERO_DE_AMINO_ACIDOS 64

/**
 * Este é o limite de proteínas que o nosso
 * programa irá suportar.
 */
#define LIMITE_DE_AMINO_ACIDOS 1000

/**
 * Este é o limite de códigos genéticos
 * que o nosso programa irá suportar.
 * 
 * Se nos for passado mais do que isso, o
 * resto não será lido.
 */
#define LIMITE_DE_CODIGOS_GENETICOS 10000

/**
 * Armazena as proteínas.
 */
int pegue_a_proteina(char ficheiro_proteina[], char *proteina, int *numero_proteina)
{
    // Conterá o número de amino acidos
    int contador = 0;
    
    /**
     * Pointeiro para o ficheiro.
     *
     * O ficheiro é de onde as proteínas
     * serão extraídas.
     */
    FILE *ptr_ficheiro;

    /**
     * Uma vez que iremos pegar carácter
     * por carácter, vamos armazenar cada
     * carácter na variável `c`, para
     * para posterior processamento.
     */
    char c;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_proteina, "r");

    /**
     * Aqui lemos cada carácter e armazenamos
     * no nosso vector `proteinas`.
     * 
     * Cada carácter representará uma sequência
     * de amino ácidos.
     */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        // Armazenando cada carácter.
        proteina[contador] = c;

        // Contando cada amino ácido.
        contador++;
    }

    /**
     * Uma vez contados o número de amino ácidos
     * vamos passá-lo ao ponteiro que representa
     * variável fora da função que conterá o
     * número de proteínas.
     */
    *numero_proteina = contador;
    
    // Nunca se esqueça: Limpar sempre a casa (memória).
    fclose(ptr_ficheiro);

    /**
     * Em C edde é o padrão para indicar que
     * a função foi executada com sucesso.
     */
    return 0;
}

/**
 * Pega a sequência dos genes
 * e associa a sua respectiva
 * proteína.
 */
int pegue_as_seq_de_genes(
    char ficheiro_seq_genes[],
    char sequencia_de_amino_acidos[][LIMITE_DE_CODIGOS_GENETICOS],
    int numero_de_proteinas_extraidas,
    int tentativas
) {
    FILE *ptr_ficheiro;

    char c;

    int
        linha = 0,
        coluna = 0,
        contador = 0;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_seq_genes, "r");

    /**
    * Aqui lemos cada carácter e armazenamos
    * no nosso vector `proteina`.
    */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        if (contador > tentativas)
        {
            if (coluna != 2)
            {
                sequencia_de_amino_acidos[linha][coluna] = c;
    
                coluna++;
            }
            else
            {
                sequencia_de_amino_acidos[linha][coluna] = c;
                
                linha++;
                coluna = 0;
            }
    
            if (linha == numero_de_proteinas_extraidas)
            {
                break;
            }
        }

        contador++;
    }

    // Nunca se esqueçam de limpar a memória.
    fclose(ptr_ficheiro);

    return 0;
}

/**
 * O parámetro `argc` indica o número
 * de parámetros passados via terminal.
 *
 * O parámetro `argv` contem os parámetros
 * passados via terminal.
 */
int main(int argc, char *argv[])
{
    int
        numero_de_proteinas_extraidas,
        tentivas = 0,
        codigo_genetico_ainda_nao_decifrado = 0;

    char
        // Vetor que armazenara as proteínas extraídas.
        proteina[NUMERO_DE_AMINO_ACIDOS],
        /**
         * Matríz (vetor 2d) que armazenará as sequências de amino ácidos.
         * 
         * As linhas representarão os amino ácidos.
         * As colunas representarão os códigos genéticos dos amino ácidos.
         * 
         * Ex:
         * 
         *  M   H   I   S   Y
         * AGT TTT GGA AAG ATA
         * 
         * Onde cada letra representa um amino ácido
         * e cada amino ácido representa um sequência genética.
         */
        sequencia_de_amino_acidos[NUMERO_DE_AMINO_ACIDOS][LIMITE_DE_CODIGOS_GENETICOS];  
    
    // Pegando a proteina.
    pegue_a_proteina("dados/proteina", proteina, &numero_de_proteinas_extraidas);

    while (codigo_genetico_ainda_nao_decifrado != 1)
    {
        pegue_as_seq_de_genes(
            "dados/sequencia_de_amino_acidos",
            sequencia_de_amino_acidos,
            numero_de_proteinas_extraidas,
            tentivas
        ); 

        // Percorrendo cada amino ácido.
        for (int i = 0; i < numero_de_proteinas_extraidas; i++)
        {
            // Percorrendo cada sequência de um amino ácido.
            for (int j = 0; j <= numero_de_proteinas_extraidas; j++)
            {
                if (i != j)
                {
                    if (
                        sequencia_de_amino_acidos[i][0] == sequencia_de_amino_acidos[j][0]
                        &&
                        sequencia_de_amino_acidos[i][1] == sequencia_de_amino_acidos[j][1]
                        &&
                        sequencia_de_amino_acidos[i][2] == sequencia_de_amino_acidos[j][2]
                    ) {
                        tentivas++;

                        printf("%dª tentativa: falhada\n\n", tentivas);

                        printf("%c: %s\n", proteina[i], sequencia_de_amino_acidos[i]);
                        printf("%c: %s\n", proteina[j], sequencia_de_amino_acidos[j]);
                    }
                }
            }

            /**
             * Se já lemos todos amino ácidos convém parar,
             * se não iremos ler lixo do buffer, e que não
             * é nosso.
             */
            if (i == numero_de_proteinas_extraidas)
            {
                codigo_genetico_ainda_nao_decifrado = 1;
                
                break;
            }
        }
    }
        
    return 0;
}