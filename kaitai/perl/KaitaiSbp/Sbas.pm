# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use KaitaiSbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Sbas;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Sbas::MsgSbasRaw;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{message_type} = $self->{_io}->read_u1();
    $self->{data} = [];
    my $n_data = 27;
    for (my $i = 0; $i < $n_data; $i++) {
        push @{$self->{data}}, $self->{_io}->read_u1();
    }
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub message_type {
    my ($self) = @_;
    return $self->{message_type};
}

sub data {
    my ($self) = @_;
    return $self->{data};
}

1;
