use strict;
use warnings;
use IO::KaitaiStruct;


# add custom serialisation logic to base class
sub IO::KaitaiStruct::Struct::TO_JSON {
    my $self = shift;

    my %hash = map { $_ => $self->{$_} } grep { substr($_, 0, 1) ne '_' } keys %$self;
    return \%hash;
}


# wrapper object which allows KaitaiStream to be used with inputs which do
# not support seeking
package BufferedKaitaiStream;

our @ISA = qw(IO::KaitaiStruct::Stream);

use constant SBP_HEADER_LEN => 6;

sub new {
    my ($class, $fp, $max_buf_size) = @_;

    read($fp, my $buf, $max_buf_size);

    my $fd;
    open $fd, '<', \$buf or return undef;
    binmode $fd;

    my $self = IO::KaitaiStruct::Stream->new($fd);

    bless $self, $class;

    $self->{fp} = $fp;
    $self->{buf} = \$buf;
    $self->{max_buf_size} = $max_buf_size;

    return $self;
}


# discard processed data, then attempt to read more data such that
# the buffer contains 'max_buf_size' bytes
sub fill_buffer($) {
    my ($self) = @_;

    my $pos = tell($self->{_io});
    my $space = $self->{max_buf_size} - length(${$self->{buf}}) + $pos;
    ${$self->{buf}} = substr(${$self->{buf}}, $pos); # remove consumed bytes
    if($space > 0) {
        my $read_data;
        my $read_len = read($self->{fp}, $read_data, $space);
        ${$self->{buf}} .= $read_data if($read_len > 0);
    }

    $self->seek(0);
}


# get bytes required to compute CRC
sub get_crc_bytes($$) {
    my ($self, $payload_len) = @_;

    return substr(${$self->{buf}}, 1, &SBP_HEADER_LEN + $payload_len - 1);
}


package ParseUtils;

use MIME::Base64;


# convert KaitaiStruct object to have similar structure to sbp2json output
sub get_flattened_msg($) {
    my $obj = shift;
    my $payload = $obj->{'payload'};

    $payload->{'preamble'} = ord($obj->{'preamble'});
    $payload->{'msg_type'} = $obj->{'msg_type'};
    $payload->{'sender'} = $obj->{'sender'};
    $payload->{'length'} = $obj->{'length'};
    $payload->{'_io'}->seek(0);
    $payload->{'payload'} = encode_base64($payload->{'_io'}->read_bytes_full(), '');
    $payload->{'crc'} = $obj->{'crc'};

    return $payload;
}


1;
