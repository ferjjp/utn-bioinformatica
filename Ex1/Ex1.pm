#! /usr/bin/perl
use strict;
use Bio::DB::GenBank;
use Bio::SeqIO;

my $db = Bio::DB::GenBank->new();

# nuestro gen genera dos variantes transcripcion
# variante 2
# Accession: NM_001281503.2 GI: 1677500628
# variante 1
# Accession: NM_052910.2 GI: 527498300

# bajamos la variante 2 de GenBank
my $seq_obj = $db->get_Seq_by_gi('1677500628');

#transformamos la secuencia original en un archivo con formato fasta
my $seqio_obj = Bio::SeqIO->new(-file => ">variante2_original.fasta",
                             -format => 'fasta');
$seqio_obj->write_seq($seq_obj);

# --------------------------- Aca comienza el ejercicio -------------------------------------------------
$seqio_obj = Bio::SeqIO->new(-file => ">variante2_orfs.fasta",
                             -format => 'fasta');

# recibe por parametro una secuencia y escribe la traduccion en el archivo
writeTranslatedSeq($seq_obj, $seqio_obj);
writeTranslatedSeq($seq_obj->revcom, $seqio_obj);

sub writeTranslatedSeq {
    my ($seq_obj, $seqio_obj) = @_;
    for (my $i = 0; $i < 3; $i++) {
        my $translated_seq = $seq_obj->translate(-frame => $i);
        $seqio_obj->write_seq($translated_seq);
    }
}