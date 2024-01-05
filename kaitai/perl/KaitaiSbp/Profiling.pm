# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package Profiling;

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
package Profiling::MsgMeasurementPoint;

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

    $self->{total_time} = $self->{_io}->read_u4le();
    $self->{num_executions} = $self->{_io}->read_u2le();
    $self->{min} = $self->{_io}->read_u4le();
    $self->{max} = $self->{_io}->read_u4le();
    $self->{return_addr} = $self->{_io}->read_u8le();
    $self->{id} = $self->{_io}->read_u8le();
    $self->{slice_time} = $self->{_io}->read_u8le();
    $self->{line} = $self->{_io}->read_u2le();
    $self->{func} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub total_time {
    my ($self) = @_;
    return $self->{total_time};
}

sub num_executions {
    my ($self) = @_;
    return $self->{num_executions};
}

sub min {
    my ($self) = @_;
    return $self->{min};
}

sub max {
    my ($self) = @_;
    return $self->{max};
}

sub return_addr {
    my ($self) = @_;
    return $self->{return_addr};
}

sub id {
    my ($self) = @_;
    return $self->{id};
}

sub slice_time {
    my ($self) = @_;
    return $self->{slice_time};
}

sub line {
    my ($self) = @_;
    return $self->{line};
}

sub func {
    my ($self) = @_;
    return $self->{func};
}

1;
