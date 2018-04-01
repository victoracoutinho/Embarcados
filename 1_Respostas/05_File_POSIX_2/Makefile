main: funcao_cat.o funcao_grep.o bib_arqs.o
	gcc -o busca_e_conta funcao_grep.o bib_arqs.o
	gcc -o cat_falsificado funcao_cat.o bib_arqs.o
funcao_grep.o:
	gcc -c funcao_grep.c
bib_arqs.o:
	gcc -c bib_arqs.c
funcao_cat.o:
	gcc -c funcao_cat.c

