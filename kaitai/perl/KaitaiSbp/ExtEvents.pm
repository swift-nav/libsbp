# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package ExtEvents;

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
package ExtEvents::MsgExtEvent;

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

    $self->{wn} = $self->{_io}->read_u2le();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{ns_residual} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{pin} = $self->{_io}->read_u1();
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub ns_residual {
    my ($self) = @_;
    return $self->{ns_residual};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub pin {
    my ($self) = @_;
    return $self->{pin};
}

1;
