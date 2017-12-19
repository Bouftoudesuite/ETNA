#!/bin/sh

# Creation fichier/dossier
touch test1 test3 test4 test5 testJour01
mkdir test0 test2
ln -s testJour01 test6

# Permission
chmod 715 test0
chmod 414 test1
chmod 504 test2
chmod 404 test3 test5
chmod 020 test4
chmod 777 test6
chmod 615 testJour01

# Changer taille
echo "a a">>test1
echo "">>test3
echo "a">>test4
echo "">>test5
echo "a a a a a a a a a a a a a a a a a a a a a">>testJour01


# Changer Date
touch -t 1210042020 test0
touch -t 1210042020 test1
touch -t 1210042020 test2
touch -t 1210042010 test3
touch -t 1210042010 test4
touch -t 1210042010 test5
touch -t 1210042010 test6 -h
touch -t 1210042010 testJour01
