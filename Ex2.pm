#! /usr/bin/perl
use strict;
use Bio::Perl;
use Bio::SeqIO;

#https://metacpan.org/pod/Bio::Perl
my $seqs = Bio::SeqIO->new(-file => "variante2_orfs.fasta", -format => "fasta" );


#https://blast.ncbi.nlm.nih.gov/Blast.cgi?PROGRAM=blastp&PAGE_TYPE=BlastSearch&LINK_LOC=blasthome
while(my $seq = $seqs->next_seq()) {
    my $blast = blast_sequence($seq->seq);
    write_blast(">>reporte_variante_2_orfs_remoto.bls", $blast);
}