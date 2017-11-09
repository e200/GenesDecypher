C	= gcc

default:
	$(C) decypher.c -o decypher

install: default
	sudo mv decypher /usr/bin/decypher
	clear
	@echo "Decifrador de Genes instalado com sucesso."

remove:
	sudo rm /usr/bin/decypher
	clear
	@echo "Decifrador de Genes removido com sucesso."