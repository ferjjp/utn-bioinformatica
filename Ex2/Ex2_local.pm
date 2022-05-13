#! /usr/bin/perl
use strict;
# use Bio::SeqIO;
# use Bio::SearchIO;
use Bio::Tools::Run::StandAloneBlastPlus;

#https://bioperl.org/howtos/BlastPlus_HOWTO.html

my $blast_factory = Bio::Tools::Run::StandAloneBlastPlus->new( -db_data => "swissprot", -create => 1 );

$blast_factory->blastp(-query => "variante2_orfs.fasta", 
                       -outfile => "reporte_variante_2_orfs_local.bls");

$blast_factory->cleanup();