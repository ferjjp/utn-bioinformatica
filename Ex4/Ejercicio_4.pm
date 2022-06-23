#! /usr/bin/perl

use strict;
use warnings;
use Getopt::Long;
use Bio::SearchIO;
use Bio::DB::GenBank;

my $input = 'secuencia.blast';
my $pattern;

GetOptions ('f=s' => \$input,      
            'p=s' => \$pattern);  # Leemos de consola el input file y el pattern.

my $input_file = Bio::SearchIO->new(
    -file => $input,
    -format => 'blast'
    );

my $db = Bio::DB::GenBank->new();

my $result = $input_file->next_result;
my $coincidencias = 0;

while (my $hit = $result->next_hit) { # Itera sobre el archivo blast.
    my $description = $hit->description;
    $description = uc($description); # Se convierte la description y el pattern a uppercase para comparar de forma no-case-sensitive.
    $pattern = uc($pattern);

    print '- Description: ', $description, "\n";


    if (index($description, $pattern) != -1) { # Checkea si el pattern esta contenido dentro de la description, si el index devuelve -1 es porque no se encuentra.
        my $acc = $hit->accession;
        my $seq = $db->get_Seq_by_acc($acc);
        my $file = ">$acc.fas";
        my $output_file = Bio::SeqIO->new( -file => $file,  # Genera un archivo FASTA por cada coincidencia que encuentre.
                                    -format => 'fasta',
                                   );
        $output_file->write_seq($seq);
        $coincidencias++;
    }
}
print 'FINALIZADO', "\n", "Coincidencias: $coincidencias", "\n";