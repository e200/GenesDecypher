/**
 * Data: 31/10/2017
 *
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200/GenesDecypher/blob/master/
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Este é o número de combinações para codóns
 * actualmente conhecido.
 *
 * Existem 4 tipos de codóns, isso significa
 * que só existem 64 possíveis combinações
 * entre os mesmos. (4 x 4 x 4 = 64).
 *
 * Vejam a tabela de codóns para entenderem.
 */
#define NUMERO_DE_CODONS 64

/**
 * Uma vez que não sabemos o número de proteinas,
 * vamos usar um vetor com 1000 índices, só para garantir.
 */
#define LIMITE_DE_PROTEINAS 1000
/**
 * TODO: Add descrition.
 */
#define LIMITE_DE_SEQUENCIA_DE_GENES 10000

/**
 * Retorna um vetor contendo em cada
 * um dos seus índices o carácter que
 * está na mesma posição no arquivo lido.
 */
int pegue_as_proteinas(char ficheiro_proteinas[], char *proteinas)
{
    /**
    * Pointeiro para o ficheiro.
    *
    * O ficheiro é de onde as proteínas
    * serão lidas.
    */
    FILE *ptr_ficheiro;

    /**
    * Uma vez que iremos pegar carácter
    * por carácter, vamos armazenar cada
    * carácter na variável `c`.
    */
    char c;

    /**
    * Contador.
    *
    * Contará a posição de cada carácter a ser lido.
    */
    int i = 0;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_proteinas, "r");

    /**
    * Aqui lemos cada carácter e armazenamos
    * no nosso vector `proteinas`.
    */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        proteinas[i] = c;

        i++;
    }

    // Nunca se esqueça de limpar a memória.
    fclose(ptr_ficheiro);

    return 0;
}

/**
* Pega a sequência dos genes
* e associa a cada proteína.
*/
int pegue_seq_genes(
    char ficheiro_seq_genes[],
    char sequencia_de_genes[][LIMITE_DE_SEQUENCIA_DE_GENES]
) {
    FILE *ptr_ficheiro;

    char c, sequencia[2];

    int
        i = 0,
        l = 0;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_seq_genes, "r");

    /**
    * Aqui lemos cada carácter e armazenamos
    * no nosso vector `proteinas`.
    */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        if (l != 3)
        {
            sequencia_de_genes[i][l] = c;
            l++;
        }
        else
        {
            l = 0;
            i++;
        }
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
    char
        // Vetor que armazenará os codóns encontrados.
        codons[NUMERO_DE_CODONS],
        // Vetor que armazenara as proteinas extraídas.
        proteinas[LIMITE_DE_PROTEINAS],
        // Matríz que armazenara as sequências de gênes encontradas.
        sequencia_de_genes[NUMERO_DE_CODONS][LIMITE_DE_SEQUENCIA_DE_GENES];

    /**
     * Pointeiros que referenciarão os arquivos
     * contendo as proteínas e a sequência de gênes.
     */
    FILE *ptr_gene_seq;

    /**
     * Aqui vamos ler o conteúdo de cada arquivo
     * correspondente ao seu ponteiro.
     */
    pegue_as_proteinas("dados/proteinas", proteinas);

    pegue_seq_genes("dados/sequencia_de_genes", sequencia_de_genes);

    for (int i = 0; i < sizeof(sequencia_de_genes); i++)
    {
        for (int l = 0; l < sizeof(sequencia_de_genes[i]); l++)
        {
            printf("%c", sequencia_de_genes[i][l]);
        }
    }

    //printf("%s", sequencia_de_genes[0][2]);
    
    return 0;
}
