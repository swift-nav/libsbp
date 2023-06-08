# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use Sbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Ndb;

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
package Ndb::MsgNdbEvent;

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

    $self->{recv_time} = $self->{_io}->read_u8le();
    $self->{event} = $self->{_io}->read_u1();
    $self->{object_type} = $self->{_io}->read_u1();
    $self->{result} = $self->{_io}->read_u1();
    $self->{data_source} = $self->{_io}->read_u1();
    $self->{object_sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{src_sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{original_sender} = $self->{_io}->read_u2le();
}

sub recv_time {
    my ($self) = @_;
    return $self->{recv_time};
}

sub event {
    my ($self) = @_;
    return $self->{event};
}

sub object_type {
    my ($self) = @_;
    return $self->{object_type};
}

sub result {
    my ($self) = @_;
    return $self->{result};
}

sub data_source {
    my ($self) = @_;
    return $self->{data_source};
}

sub object_sid {
    my ($self) = @_;
    return $self->{object_sid};
}

sub src_sid {
    my ($self) = @_;
    return $self->{src_sid};
}

sub original_sender {
    my ($self) = @_;
    return $self->{original_sender};
}

1;
