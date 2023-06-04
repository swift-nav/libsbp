use strict;
use warnings;
use IO::KaitaiStruct;


# add custom serialisation logic to base class
sub IO::KaitaiStruct::Struct::TO_JSON {
    my $self = shift;

    my %hash = map { $_ => $self->{$_} } grep { substr($_, 0, 1) ne '_' } keys %$self;
    return \%hash;
}


package Utils;

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
