
#
# fichier de directives 
# pour generer le programme de test: testChaine
#

# unites de compilation separee
PE = testChaine

F1 = creerChaineVide
F2 = libererChaine
F3 = convertirChaine
F4 = longueurChaine
F5 = copierChaine
F6 = comparerChaine
# fichier binaire executable
EXEC = ${PE}

# listes des fichiers objets pour l'editeur de liens
OBJETS1 = ${PE}.o  ${F1}.o ${F2}.o ${F3}.o ${F4}.o
OBJETS2 = ${F5}.o ${F6}.o

#
# édition de liens et génération du fichier executable 
#
${EXEC}: ${OBJETS1} ${OBJETS2}
	gcc -g ${OBJETS1}  ${OBJETS2}  -o ${EXEC}

#
# compilation separee des fichiers sources en C
#
${PE}.o: ${PE}.c chaine.h
	gcc -c -g ${PE}.c 2>${PE}.err
    
${F1}.o: ${F1}.c chaine.h
	gcc -c -g ${F1}.c 2>${F1}.err
    
${F2}.o: ${F2}.c chaine.h
	gcc -c -g ${F2}.c 2>${F2}.err
    
${F3}.o: ${F3}.c chaine.h
	gcc -c -g ${F3}.c 2>${F3}.err
        
${F4}.o: ${F4}.c chaine.h
	gcc -c -g ${F4}.c 2>${F4}.err
        
${F5}.o: ${F5}.c chaine.h
	gcc -c -g ${F5}.c 2>${F5}.err

${F6}.o: ${F6}.c chaine.h
	gcc -c -g ${F6}.c 2>${F6}.err

