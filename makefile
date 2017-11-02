C	= gcc

default:
	$(C) decifrador_de_genes.c -o decifrador_de_genes

install: default
	sudo mv decifrador_de_genes /usr/bin/decifrador_de_genes
	clear
	@echo "Decifrador de Genes instalado com sucesso."

remove:
	sudo rm /usr/bin/decifrador_de_genes
	clear
	@echo "Decifrador de Genes removido com sucesso."
