# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Mag;

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
package Mag::MsgMagRaw;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{tow_f} = $self->{_io}->read_u1();
    $self->{mag_x} = $self->{_io}->read_s2le();
    $self->{mag_y} = $self->{_io}->read_s2le();
    $self->{mag_z} = $self->{_io}->read_s2le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub tow_f {
    my ($self) = @_;
    return $self->{tow_f};
}

sub mag_x {
    my ($self) = @_;
    return $self->{mag_x};
}

sub mag_y {
    my ($self) = @_;
    return $self->{mag_y};
}

sub mag_z {
    my ($self) = @_;
    return $self->{mag_z};
}

1;
