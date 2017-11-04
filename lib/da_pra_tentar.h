/**
 * Informa ao loop de tentativas
 * se pode continuar a tentar ou não.
 * 
 * O loop de tentivas pode continuar
 * a tentar se:
 * 
 * 1º O código genético ainda não foi decifrado.
 * 2º O número de tentativas é menor que o número
 * de nucleotides - a quantidade de amino ácidos.
 */
int da_pra_tentar(
    int cod_gen_decifrado,
    int num_tentativas,
    int qtd_nucleotides,
    int qtd_amin_acidos
) {
    return (cod_gen_decifrado == 0) && (num_tentativas < (qtd_nucleotides - qtd_amin_acidos));
}