#! /usr/bin/sh

# Correr desde el root del proyecto

# Download swissprot db in fasta format
wget https://ftp.ncbi.nlm.nih.gov/blast/db/FASTA/swissprot.gz
gzip -d swissprot.gz 

# Download blast+
wget https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ncbi-blast-2.13.0+-x64-linux.tar.gz
tar xvf ncbi-blast-2.13.0+-x64-linux.tar.gz

#Execute local blast
BLASTPLUSDIR=$(pwd)/ncbi-blast-2.13.0+/bin ./Ex2_local.pm

#Execute remote blast
./Ex2.pm